#include<bits/stdc++.h>
#define ll long long int
#define LIM 1000000
#define pb push_back

using namespace std;

ll a,b,c, lcm, sz;
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
        scanf("%lld %lld %lld", &a,&b,&lcm);

        if(lcm%a || lcm%b) {
            printf("Case %d: impossible\n", t);
            continue;
        }

        for(int i=0; i<sz; i++) {
            if(lcm%primes[i]==0) {
                ll cnt = 0, temp = lcm;
                while(temp%primes[i] == 0) cnt++ , temp /= primes[i];
                factor[ primes[i] ] = cnt;
//                cout << primes[i] << " : " << cnt << endl;
            }
        }

//        for(int i=2; i<=20; i++) cout << factor[i] << ' ' ; cout << endl;

        for(int i=0; i<sz && a > 1 ; i++) {
            int cnt = 0;
            while(a % primes[i] == 0) cnt++ , a/=primes[i];
            if(cnt && factor[ primes[i] ] == cnt) lcm /= power(primes[i], cnt), factor[ primes[i] ] = 0;
//            cout << primes[i] << ' ' << cnt << ' ' << lcm << endl;
        }
//        cout << "NEXT" << endl;
        for(int i=0; i<sz && b > 1 ; i++) {
            int cnt = 0;
            while(b % primes[i] == 0) cnt++ , b/=primes[i];
            if(cnt && factor[ primes[i] ] == cnt) lcm /= power(primes[i], cnt) , factor[ primes[i] ] = 0;
//            cout << primes[i] << ' ' << cnt << ' ' << lcm << endl;
        }
        printf("Case %d: %lld\n", t, lcm);
    }

    return 0;

}
