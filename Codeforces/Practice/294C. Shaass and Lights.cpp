#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(r<=0) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

int n,m, a[1010];
ll fact[1010];

int main() {
    fact[0] = 1;
    for(int i=1; i<=1000; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &a[i]);
//        a[i]--;
    }
    sort(a, a+m);

    ll ans = fact[n-m];
    ans *= modInverse(fact[ a[0]-1 ], MOD);
    ans %= MOD;

    for(int i=1; i<m; i++) {
        ans *= bigMod(2, a[i]-a[i-1]-2, MOD);
        ans %= MOD;
        ans *= modInverse(fact[ a[i]-a[i-1]-1 ], MOD);
        ans %= MOD;
    }

    ans *= modInverse(fact[ n-a[m-1] ], MOD);
    ans %= MOD;

//    ans *= fact[n-m];


    cout << ans << endl;

}
