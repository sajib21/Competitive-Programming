#include<bits/stdc++.h>
#define ll long long int
#define ui unsigned int
#define vii vector<int>
#define vll vector<ll>
#define vui vector<ui>
#define pb push_back
#define LIM 100000009LL
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

int isPrime[LIM/32 + 100];
//vui primes, mulPrimes;
ui primes[5761456+10], mulPrimes[5761456+10], sz=0;

void genSieve() {
    isPrime[0] |= (1 << 0); isPrime[0] |= (1 << 1);
    ui sq = sqrt(LIM);
    for(ui i=3; i<=sq; i+=2) {
        if( !(isPrime[i/32] & (1 << (i%32) )) ) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j/32] |= (1 << (j%32));
        }
    }
    ui m = 2;
    primes[sz] = 2; mulPrimes[sz] = 2;
    sz++;

//    primes.pb(2); mulPrimes.pb(2);
    for(ui i=3; i<=LIM; i+=2) if(!(isPrime[i/32] & (1 << (i%32))) ) {
        primes[sz] = i;
//        primes.pb(i);
        m *= i ;
        mulPrimes[sz] = m;
        sz++;
//        mulPrimes.pb(m);
    }
}

int n, sq;

int main() {
    genSieve();
//    cout << sz << endl;
//    cout << primes.size() << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        ui ans = 1;
        ll tmp = 2;
//        int lim = log2(n);
        while(tmp*2 <= n) ans *= 2 , tmp *= 2 ;

        sq = sqrt(n);
//        int sz = primes.size();
        for(int i=1; primes[i]*primes[i] <= n ; i++) {
                ll tmp = primes[i];
                while(tmp*primes[i] <= n) tmp *= primes[i] , ans *= primes[i];
        }
        int x = upper_bound(primes, primes+sz, n) - primes - 1;
        ans *= mulPrimes[x];
        printf("Case %d: %u\n", t, ans);
    }
    return 0;
}

