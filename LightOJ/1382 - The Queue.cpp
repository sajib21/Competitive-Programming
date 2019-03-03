/// assume a -> b -> c
/// we have to fix a first then distribute sub tree nodes.
/// do it fact( subtree[a]  - 1 )
/// it will also count a -> c -> b
/// to reduce them, think b and c identical and divide by 2!
/// do this for all the nodes and multiply.

#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000
#define MOD 1000000007LL
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

int n;
vii graph[LIM+10];
int subTree[LIM+10];
ll fact[LIM+10];

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

int dfs(int u) {
    if(subTree[u]) return subTree[u];
    subTree[u] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        subTree[u] += dfs(v);
    }
    return subTree[u];
}

ll getCnt(int u) {
    ll ans = fact[ subTree[u] - 1 ];
    int sz = graph[u].size();

    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        ll inv = modInverse(fact[ subTree[v] ], MOD);
        ans = (ans * inv) % MOD;
    }
    return ans;
}

int main() {
    fact[0] = 1;
    for(int i=1; i<=LIM; i++) fact[i] = (fact[i-1] * i) % MOD;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) graph[i].clear();
        memset(subTree, 0, sizeof(subTree));
        for(int i=1; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
        }

        for(int u = 1; u<=n; u++) {
            if(!subTree[u]) {
                dfs(u);
            }
        }

        ll ans = 1;
        for(int i=1; i<=n; i++) ans = (ans * getCnt(i)) % MOD;
        printf("Case %d: %lld\n", t, ans);
    }


}
