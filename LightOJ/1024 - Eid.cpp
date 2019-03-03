#include<bits/stdc++.h>
#define LIM 10000
#define pb push_back
#define ll long long int

using namespace std;


int isPrime[LIM+100], sz;
vector<int>primes;
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

ll bigMod(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1)*n) ;
    ll ans = bigMod(n, r/2);
    return (ans*ans) ;
}

string multiply( string a, long long b ) {
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}


int n;
int factorCount[LIM+10];

int main() {

    genSieve();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        memset(factorCount, 0, sizeof(factorCount));
        for(int i=0; i<n; i++) {
            int num;
            scanf("%d", &num);
            for(int i=0; primes[i]*primes[i]<=num; i++) {
                int prm = primes[i];
                int cnt = 0;
                while(num%prm==0) {
                    cnt++;
                    num/=prm;
                }
                factorCount[prm] = max(factorCount[prm], cnt);
            }
            if(num != 1 && !factorCount[num]) factorCount[num] = 1;
        }

        string lcm = "1";

        for(int i=0; i<sz; i++) {
            int prm = primes[i];
            if(factorCount[prm]) {
                lcm = multiply(lcm, bigMod(prm, factorCount[prm]) );
            }
        }
        reverse(lcm.begin(), lcm.end());
        printf("Case %d: %s\n", t, lcm.c_str());
    }
    return 0;
}
