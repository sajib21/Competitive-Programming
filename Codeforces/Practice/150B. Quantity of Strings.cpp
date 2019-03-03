#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

int n,m,k;

int main() {
    scanf("%d %d %d", &n,&m,&k);

    if(n < k) {
        printf("%lld\n", bigMod(m, n, MOD) );
    }
    else if(n == k) {
        printf("%lld\n", bigMod(m, (n+1)/2, MOD));
    }
    else {
        if(k == 1) printf("%lld\n", bigMod(m, n, MOD));
        else if(k%2==0) printf("%d\n", m);
        else printf("%lld\n", 1LL*m*m);
    }
}
