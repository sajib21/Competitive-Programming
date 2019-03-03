#include<bits/stdc++.h>
#define MAX 1000000
#define vi vector<int>
#define pb(x) push_back(x)
#define ll long long int
#define MOD 1000000007
#define MAXN MAX

using namespace std;

bool isPrime[MAX+100];
int divcnt[MAX+100];
vi primes;

void gen() {
    for(int i=4; i<=MAX; i+=2) isPrime[i] = 1;
    for(int i=3; i<=MAX; i+=2) {
        if(isPrime[i]) continue;
        for(int j=i+i; j<=MAX; j+=i) isPrime[j] = 1;
    }
    primes.pb(2);
    for(int i=3; i<=MAX; i+=2) if(!isPrime[i]) primes.pb(i);
}

int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }


int main() {
    gen();
    sieve();
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(divcnt, 0, sizeof divcnt);
        ll sum = 0;
        ll div = 1;
        int n,x;
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &x);

            if(x > 0) {
                vi diviors = getFactorization(x);

//                for(int i=0; i<diviors.size(); i++) cout << diviors[i] << ' '; cout << endl;

                for(int i=0; i<diviors.size(); i++) {
                    int cnt = 0, p = diviors[i];
                    if(i && p == diviors[i-1]) continue;
                    while(x%p==0) {
                        cnt++;
                        x /= p;
                    }
                    div = ( ( (div * modInverse(divcnt[p]+1, MOD) )%MOD) * (divcnt[p]+cnt+1) ) % MOD;
                    divcnt[p] += cnt;
//                    cout << p << ' ' << divcnt[p] << ' ' << cnt << endl;
                }
//                if(x > 1) {
//                    int i = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
//                    div = ( ( (div * modInverse(divcnt[p]+1, MOD) )%MOD) * (divcnt[p]+1+1) ) % MOD;
//                    divcnt[p] += 1;
//                }
//                sum += div;
            }
            else {
                x = -x;
                vi diviors = getFactorization(x);
                for(int i=0; i<diviors.size(); i++) {
                    int cnt = 0, p = diviors[i];
                    if(i && p == diviors[i-1]) continue;
                    while(x%p==0) {
                        cnt++;
                        x /= p;
                    }
                    div = ( ( (div * modInverse(divcnt[p]+1, MOD) )%MOD) * (divcnt[p]-cnt+1) ) % MOD;
                    divcnt[p] -= cnt;
//                    cout << p << ' ' << cnt << ' ' << div << ' ' << divcnt[p] << endl;
                }
//                if(x > 1) {
//                    int i = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
//                    div = ( ( (div * modInverse(divcnt[p]+1, MOD) )%MOD) * (divcnt[p]-1+1) ) % MOD;
//                    divcnt[p] -= 1;
//                }
//                sum += div;
            }
            sum += div;
            sum %= MOD;
//            cout << sum << ' ' << div << endl;
        }
        printf("Case %d: %lld\n", t, sum);
    }
}
