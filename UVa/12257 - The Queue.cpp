#include<bits/stdc++.h>
#define LIM 1010
#define MOD 1000000007
#define vi vector<int>
#define pb(x) push_back(x)
#define ll long long int

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }


int n;
vi g[LIM];
ll fact[LIM];
int vis[LIM], sub[LIM];
ll dp[LIM];

stack<int>stk;
void dfs(int u) {
    vis[u] = 1; sub[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(!vis[v]) dfs(v);
        sub[u] += sub[v];
    }
    stk.push(u);
}

ll f(int u) {
//    cout << "IN " << u << endl; getchar();
    vis[u] = 1;
    dp[u] = fact[ sub[u]-1 ];
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        dp[u] *= f(v);
        dp[u] %= MOD;
        dp[u] *= modInverse(fact[ sub[v] ], MOD);
        dp[u] %= MOD;
    }
//    cout << "DP " << u << ' ' << dp[u] << endl; getchar();
    return dp[u];
}

int main() {
    fact[0] = 1;
    for(int i=1; i<=1000; i++) fact[i] = (fact[i-1] * i) % MOD;

    int T;
    scanf("%d", &T);
    while(T--) {
        memset(vis, 0, sizeof vis);
        while(!stk.empty()) stk.pop();
        scanf("%d", &n);
        for(int i=1; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            g[u].pb(v);
//            g[v].pb(u);
        }

        for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
        memset(vis, 0, sizeof vis);
        memset(dp, -1, sizeof dp);
        printf("%lld\n", f(stk.top()) );
    }
}
