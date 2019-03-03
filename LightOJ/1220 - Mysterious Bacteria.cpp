#include<bits/stdc++.h>
#define ll long long int
#define LIM 66000
#define pb push_back

using namespace std;

ll a, sz;
int factor[LIM+20], isPrime[LIM+20];
vector<ll>primes;

ll power(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (power(n, r-1) * n) ;
    ll ans = power(n, r/2);
    return (ans*ans) ;
}

void sv() {

    int sq = sqrt(LIM);
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    for(int i=3; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
}

int main() {

    sv();
    sz = primes.size();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(factor, 0, sizeof(factor));
        scanf("%lld", &a);

        ll ans = 1;
        for(int i=2; i<=LIM; i++) {
            if(a%i==0) {
                ll cnt = 0;
                ll aa = a;
                while(aa%i == 0) cnt++ , aa /= i;
                if(abs(aa) != 1) {
//                    printf("Case %d: 1\n", t);
//                    break;
                    continue;
                }

                if(aa<0) {
                    while(cnt%2==0) cnt /= 2;
                        ans = cnt;
                        break;

                }
                else {
                    ans = cnt;
                    break;
                }
//                cout << primes[i] << " : " << cnt << endl;
            }
        }

//        for(int i=2; i<=20; i++) cout << factor[i] << ' ' ; cout << endl;

        printf("Case %d: %lld\n", t, ans);
    }

    return 0;

}
