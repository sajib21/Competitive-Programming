#include<bits/stdc++.h>
#define LIM 300
#define pb(x) push_back(x)
#define vi vector<int>
#define ll long long int

using namespace std;

bool isPrime[LIM+100];
vector<int>primes;
int sz;
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
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

vi getDiv(int x) {
    vi ans;
    for(int i=0; primes[i]*primes[i] <= x; i++) {
        int p = primes[i];
        while(x%p==0) {
            ans.pb(p);
            x /= p;
        }
    }
    if(x != 1) ans.pb(x);
    return ans;
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
    genSieve();
    cout << sz << endl;
}
