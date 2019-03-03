#include<bits/stdc++.h>
#define MOD 1000003
#define ll long long int
#define LIM 1000000

using namespace std;

int n,r;
ll fact[LIM+10];

ll power(ll n, ll r, ll mod) {
    if(r == 1) return n % mod;
    else if(r % 2) return ( power(n, r-1, mod) * n ) % mod;
    else {
        ll tmp = power(n, r/2, mod);
        return (tmp * tmp) % mod;
    }
}

ll modIn(ll a, ll b, ll mod) {
    return ( (a % mod) * power(b, mod-2, mod) ) % mod;
}

ll comb(int n, int r) {
    if(r > n-r) r = n-r;

    ll ans = 1;
    ans = modIn( fact[n], fact[r]*fact[n-r], MOD );
    return ans;
}

int main() {

    fact[0] = 1;
    for(int i=1; i<=LIM; i++) fact[i] = (fact[i-1] * i) % MOD;

    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++) {

        scanf("%d %d", &n,&r);
        printf("Case %d: %lld\n", t, comb(n,r));
    }

    return 0;

}
