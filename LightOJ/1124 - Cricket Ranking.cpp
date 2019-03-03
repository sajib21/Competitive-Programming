#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000000
#define MOD 100000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

int n,k, rng[20];
ll fact[LIM+100];

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

ll nCr(ll n, ll r) {
    if(n < r || n < 0 || r < 0) return 0;
    return (fact[n] * modInverse( (fact[r]*fact[n-r])%MOD , MOD)) % MOD;
}

int main() {

//    freopen("1124 out.txt", "w", stdout);

    fact[0] = fact[1] = 1;
    for(ll i=1; i<=LIM+10; i++) fact[i] = (fact[i-1] * i) % MOD;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &k,&n);
        for(int i=0; i<k; i++) {
            int a;
            scanf("%d %d", &a,&rng[i]);
            n -= a;
//            if(n < 0) break;
            rng[i] -= a;
        }
        if(n < 0) {
            printf("Case %d: 0\n", t);
            continue;
        }

        ll ans = 0, lim = 1 << k;
        for(ll i=0; i<lim; i++) {
            ll nn = n, c=0;
            for(int j=0; j<k; j++) if((i >> j) & 1) nn -= rng[j]+1, c++;
            if(c&1) c = -1; else c = 1;
            ans = (ans + c*nCr(nn + k - 1 , nn)) % MOD;
        }
        printf("Case %d: %lld\n", t, (ans+MOD)%MOD );
    }
    return 0;
}
