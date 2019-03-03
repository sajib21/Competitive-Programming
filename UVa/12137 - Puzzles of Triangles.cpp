#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000000
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

bool isPrime[MAX+100];
vi primes;

void gen() {
    for(int i=4; i<=MAX; i+=2) isPrime[i] = 1;
    int sq = sqrt(MAX);
    for(int i=3; i<=sq; i++) {
        if(isPrime[i]) continue;
        for(int j=i+i; j<=MAX; j+=i) isPrime[j] = 1;
    }
    primes.pb(2);
    for(int i=3; i<=MAX; i++) if(!isPrime[i]) primes.pb(i);
}

ll n,m, num;

int main() {
    gen();
//    cout << primes.back() << endl;
    int t = 1;
    while(scanf("%lld", &n) && n) {
        num = n; m = 1;
        for(int i=0; i<primes.size() && primes[i]*primes[i] <= num; i++) {
            int p = primes[i];
            int cnt = 0;
            while(num%p==0) {
                cnt++;
                num /= p;
                m *= p;
            }
            if(cnt&1) m /= p;
        }
        m = ceil(sqrt(m));

//        cout << m << endl;

        if(m == 1) printf("Case %d: Impossible\n", t++);
        else printf("Case %d: %lld\n", t++, (m-1)*8 );
    }
}
