#include<bits/stdc++.h>
#define ll long long int
#define LIM 66000
#define pb push_back
#define MOD 1000000007

using namespace std;

ll n,m, isPrime[LIM+100];
vector<ll>primes;

void sv() {

    int sq = sqrt(LIM);
    for(int i=4; i<=LIM; i+=2) isPrime[i] = true;
    for(int i=3; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = true;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
}

ll power(ll n, ll p) {
    if(p == 1) return n;
    ll ans = 1;
    if(p%2) ans = power(n, p-1) * n;
    else {
        ans = power(n, p/2);
        ans *= ans;
    }

    return ans % MOD;
}

int main() {

//    cout << power(2, 3) << endl;

    sv();

//    cout << primes.size() << endl;

//    cout << isPrime[13] << endl;
//    cout << power(2, 29) << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%lld %lld", &n,&m);
        ll sodone = 1;
        int sz = primes.size();


        for(int i=0; i<sz && n > 1 && primes[i]*primes[i] <= n ; i++) {
            if(n <= LIM && !isPrime[n]) break;
//            cout << "BUG" << endl;
            ll cnt = 0;
            while(n%primes[i]==0) {
                n /= primes[i];
                cnt++;
            }
            sodone *= (( power(primes[i], cnt*m+1) -1 ) * power((primes[i]-1),MOD-2))%MOD;
            sodone %= MOD;

//            cout << cnt << ' ' << primes[i] << ' ' << sodone << endl;

        }
        if(n > 1) {
            sodone *= (( power(n, m+1) -1 ) * power(n-1,MOD-2))%MOD;
            sodone %= MOD;
        }
        if(sodone<0) sodone+=MOD;
        printf("Case %d: %lld\n", t, sodone);

    }

    return 0;
}
