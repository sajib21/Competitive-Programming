#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb(x) push_back(x)
#define pp() pop_back()
#define LIM 100000
#define MOD 1000000007
#define ll  long long int

using namespace std;

bool isPrime[LIM+100];
vector<int>primes, doubles;
int sz1, sz2;
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
//    int sq = sqrt(LIM);
    for(int i=3; i<=LIM; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
    sz1 = primes.size();

    for(int i=0; i<primes.size(); i++) {
        int p = primes[i];
        if(!isPrime[p-2]) doubles.pb(p);
    }
    sz2 = doubles.size();

//    for(int i=0; i<10; i++) cout << primes[i] << ' '; cout << endl;
//    for(int i=0; i<10; i++) cout << doubles[i] << ' '; cout << endl;

}

ll n,m;


int main() {
    genSieve();
//    cout << sz1 << ' ' << sz2 << ' ' << primes.back() << ' ' << doubles.back() << endl;


    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld %lld", &n,&m);
        ll ans = n;

        for(int i=0; primes[i]<n; i++) {
            int p = primes[i];
            ans += (n-p)*(m-1);
            ans %= MOD;

//            cout << p << ' ' << (n-p)*(m-1) << endl;
        }

//        cout << "single " << ans << endl;

        for(int i=0; doubles[i]<n; i++) {
            int p = doubles[i];
            ans += (n-p) * 2*( ( (m-1)*(m-2)/2 ) % MOD);
            ans %= MOD;

//            cout << p << ' ' << (n-p) * 2*( ( (m-1)*(m-2)/2 ) % MOD) << endl;

        }


//        ans += x * 2*( ( (m-1)*(m-2)/2 ) % MOD);
//        ans %= MOD;

//        cout << "Double " << ans << endl;

        if(n > 7 && m > 3) {
//            ans += (n-7)* ( m-1 C 3 )
            ans += (n-7)* ( ( (m-1)*(m-2)*(m-3) / 6 ) % MOD );
            ans %= MOD;
        }

        printf("Case %d: %lld\n", t, ans);
    }
}
