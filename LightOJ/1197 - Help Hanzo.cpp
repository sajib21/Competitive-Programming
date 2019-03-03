#include<bits/stdc++.h>
#define LIM 70000
#define pb push_back
#define ll long long int

using namespace std;

int n, isPrime[LIM+1000];
vector<ll>primes;

void sv() {

    isPrime[0] = isPrime[1] = 1;
    int sq = sqrt(LIM) + 100;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    for(int i=3; i<=sq; i+=2) {
//        cout << "BUG" << endl;
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
}

int flag[LIM*2];

int main() {

    sv();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(flag, 0, sizeof(flag));
        ll a,b;
        scanf("%lld %lld", &a,&b);

        if(a == 1) flag[0] = 1;

        int sz = primes.size();
        for(int i=0; i<sz && primes[i]*primes[i] ; i++) {
            ll init = ( (a+primes[i]-1)/primes[i] ) * primes[i];

            for(ll j=init; j<=b; j+=primes[i]) {
                if(j <= LIM && !isPrime[j]) continue;
                flag[j-a] = 1;
            }
        }

        int cnt = 0;
        for(ll i = a; i<=b; i++) if(!flag[i-a]) cnt++;

//        for(ll i=a; i<=b; i++) {
//            cout << i << ' ' << flag[i-a] << endl;
//            getchar();
//        }

        printf("Case %d: %d\n", t, cnt);
    }
    return 0;
}
