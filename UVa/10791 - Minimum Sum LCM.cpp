#include<bits/stdc++.h>
#define pb push_back
#define ll long long int

using namespace std;

ll LIM = 33000;

bool isPrime[33000+100];
vector<int>primes;
int sz;
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = 1; // isPrime[1] = 1;
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

ll n;

int main() {
    genSieve();
    int t = 1;
    while(scanf("%lld", &n) && n) {
        ll num = n;
        ll ans = 0;

        if(n <= LIM && !isPrime[n]) {
            printf("Case %d: %lld\n", t++, n+1);
            continue;
        }

        int cnt = 0;

        for(int i=0; i<sz && primes[i]*primes[i] <= num; i++ ) {
            ll temp = 1;
            int p = primes[i];
            if(num%p == 0) cnt++;
            while(num%p==0) {
                temp *= p;
                num /= p;
            }
            if(temp > 1) ans += temp;
        }

        if(num > 1) {
            ans += num;
            cnt++;
        }

        if(cnt == 1) ans++;

        printf("Case %d: %lld\n", t++, ans);


    }
    return 0;
}
