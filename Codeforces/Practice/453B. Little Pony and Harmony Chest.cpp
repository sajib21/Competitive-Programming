#include<bits/stdc++.h>
#define LIM 53
#define ll long long int
#define pb push_back
#define MS 16

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

bool isPrime[LIM+100];
vector<int>primes;
int sz;
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    int sq = sqrt(LIM);
    for(int i=3; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
    sz = primes.size();
}

int n, a[103];
int dp[103][1 << 16];
int go[103];
int dr[103][1 << 16];
int vl[103][1 << 16];

int f(int in, int mask) {
    if(in == n) return 0;
//    cout << "IN " << in << ' ' << mask << endl;
    if(dp[in][mask] != -1) return dp[in][mask];
    int ans = 500000, x, y;
    for(int v=1; v<=LIM; v++) {
        if(go[v] & mask) continue;
//        cout << "TESTING " << in << ' ' << mask << ' ' << v << ' ' << (go[v] | mask) << endl;
        int val = abs(a[in]-v)+f(in+1, go[v] | mask);
        if(val < ans) {
            ans = val;
            x = go[v] | mask;
            y = v;
        }
    }
//    cout << "OUT " << in << ' ' << mask << ' ' << ans << endl; getchar();
    dr[in][mask] = x;
    vl[in][mask] = y;

    return dp[in][mask] = ans;
}

void print(int in, int mask) {
    if(in == n) {
        printf("\n");
        return;
    }
    if(in) printf(" ");
    printf("%d", vl[in][mask]);
//    cout << in << ' ' << mask << ' ' << vl[in][mask] << ' ' << dr[in][mask] << endl; getchar();
    print(in+1, dr[in][mask]);
}

int main() {
//    cout << __gcd(68,69) << endl;
    genSieve();
//    cout << sz << endl;

    for(int i=1; i<=LIM; i++) {
        for(int j=0; j<sz; j++) {
            if(i%primes[j] == 0) go[i] = setBit(go[i], j);
        }
    }
//    cout << go[16] << ' ' << go[14] << ' ' << (go[16] & go[14]) << ' ' << (go[16] | go[14]) << endl;

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
//    printf("%d\n", f(0,0));
    f(0,0);
    print(0,0);

}
