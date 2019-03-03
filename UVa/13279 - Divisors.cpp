#include<bits/stdc++.h>
#define LIM 5101000
#define MOD 100000007LL
#define vi vector<ll>
#define pb(x) push_back(x)
#define ll long long int

using namespace std;

bool isPrime[LIM+100];
vi primes;

void gen() {
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
//    int sq = sqrt(LIM);
    for(int i=3; i<=LIM; i+=2) {
        if(isPrime[i]) continue;
        for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i*1LL);
}

int main() {
    gen();
//    cout << primes.back() << endl;
    ll n;
    while(scanf("%lld", &n) && n) {
//        n++;
        ll ans = 1, cnt = 0;
        for(ll i=0; i<primes.size() && primes[i] <= n; i++) {
            cnt = 0;
            for(ll p=primes[i]; p<=n; p*=primes[i]) {
                ll div = n/p;
                ll mod = n%p;
                cnt += ( ( ( (div*(div-1)/2)%MOD )*p )%MOD + (div*(mod+1))%MOD)%MOD;
//                cnt += (p*(div*(div-1)/2%MOD) + div*(mod+1))%MOD;
//                if(cnt < 0) cout << "BUG " << cnt << " AT " << primes[i] << ' ' << p << endl;
            }
//            if(cnt < 0) cout << "BUG " << cnt << " AT " << primes[i] << endl;

            ans = (ans*(cnt+1))%MOD;
//            cout << primes[i] << ' ' << cnt << ' ' << ans << endl; getchar();
        }
        printf("%lld\n", ans);
    }
}
///p*(n*(n-1)/2) + n*((v%p)+1)
