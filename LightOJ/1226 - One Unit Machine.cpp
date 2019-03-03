/// COMBINATORICS
#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000
#define MOD 1000000007
#define MAX 1000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

ll fact[MAX+10];
int n, slot[LIM+10], all;

int main() {
    fact[0] = 1;
    for(int i=1; i<=MAX; i++) fact[i] = (fact[i-1]*i) % MOD;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &slot[i]);
        }

        ll ans = fact[all];
        ll tem = 0;
        for(int i=0; i<n; i++) {
            tem += slot[i];
            ll div = (fact[ slot[i]-1 ] * tem) % MOD;
            ans = (ans * modInverse(div, MOD)) % MOD;
        }
//        ans = (ans * modInverse(fact[n], MOD)) % MOD;
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
