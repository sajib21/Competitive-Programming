#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

int isPrime[LIM+100];
vector<int>primes;
int primeCnt[LIM+100];
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    int sq = sqrt(LIM);
    for(int i=3; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j]++;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
    primeCnt[1] = 0;
    for(int i=2; i<=LIM; i++) {
        if(!isPrime[i]) primeCnt[i] = 1;
        else {
            int num = i;
            for(int j=0; primes[j]*primes[j] <= num; j++) {
                int p=primes[j];
                if(num%p) continue;
                primeCnt[i]++;
                while(num%p==0) num/=p;
            }
            if(num > 1) primeCnt[i]++;
        }
    }
}

int n,a, cnt[LIM+10];
ll divCnt[LIM+10];

ll nCr(ll n) {
    if(n < 4) return 0;
    return n*(n-1)*(n-2)*(n-3) / 24;
}

void f(vii dv, int mask, int in, int cur) {
    if(in == dv.size()) return;
    for(int i=in; i<dv.size(); i++) {
        divCnt[cur*dv[i]]++;
        f(dv, setBit(mask, i), i+1, cur*dv[i]);
    }
}

int main() {
//    freopen("1161i.txt", "r", stdin);
//    freopen("1161o.txt", "w",stdout);
    genSieve();
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        memset(divCnt, 0, sizeof divCnt);
        for(int i=0; i<n; i++) {
            scanf("%d", &a);
            vii dv;
            for(int j=0; primes[j]*primes[j] <= a; j++) if(a%primes[j]==0) {
                int p = primes[j];
                while(a%p == 0) a /= p;
                dv.pb(p);
            }
            if(a > 1) dv.pb(a);
            f(dv, 0, 0, 1);
        }

        ll ans = nCr(n); //cout << "TRY " << ans << endl;
        for(int i=2; i<=LIM; i++) {
            if(!divCnt[i]) continue;
            if(primeCnt[i]%2) ans -= nCr(divCnt[i]);
            else              ans += nCr(divCnt[i]);
//            cout << "TRY " << i << ' ' << divCnt[i] << ' ' << ans << endl;
        }

        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
