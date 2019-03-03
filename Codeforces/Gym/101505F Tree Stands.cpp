///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);

using namespace std;

int n,k, u,v;
vii graph[LIM+100];
int vis[LIM+100];
int binTree[LIM+100][2];
ll dp[203][203][4];

void dfs(int u) {
    vis[u] = 1;
    int sz = graph[u].size();
    int l = -1;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(vis[v]) continue;
        if(l == -1) binTree[u][0] = v;
        else binTree[l][1] = v;
        l = v;

        dfs(v);
    }
}

ll f(int u, int rem, int c) {
    if(!u) {
        if(rem || c == 1) return 0;
        return 1;
    }
    if(dp[u][rem][c] != -1) return dp[u][rem][c];

    ll ans = 0;

    if(c == 0) {
        ///age khali
        for(int r=0; r<=rem; r++) ans = (ans + f(binTree[u][0], r, 0)*f(binTree[u][1], rem-r  , 0) ) % MOD; ///nei nai
        for(int r=0; r< rem; r++) ans = (ans + f(binTree[u][0], r, 1)*f(binTree[u][1], rem-r-1, 0) ) % MOD; ///nisi
    }
    else if(c == 1) {
        ///age single nwa
        for(int r=0; r<rem ; r++) ans = (ans + f(binTree[u][0], r, 2)*f(binTree[u][1], rem-r-1, 2) ) % MOD; ///nisi
        for(int r=0; r<=rem; r++) ans = (ans + f(binTree[u][0], r, 0)*f(binTree[u][1], rem-r  , 1) ) % MOD; ///nei nai
    }
    else {
        ///age jora nwa
        for(int r=0; r<rem ; r++) ans = (ans + f(binTree[u][0], r, 2)*f(binTree[u][1], rem-r-1, 2) ) % MOD; ///nisi
        for(int r=0; r<=rem; r++) ans = (ans + f(binTree[u][0], r, 0)*f(binTree[u][1], rem-r  , 2) ) % MOD; ///nei nai
    }
    return dp[u][rem][c] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

//    memset(dp, -1, sizeof dp);

    while(scanf("%d %d", &n,&k) != EOF) {
        memset(graph, NULL, sizeof graph);
        memset(binTree, 0, sizeof binTree);
        memset(vis, 0, sizeof vis);
        memset(dp, -1, sizeof dp);
        for(int i=1; i<n; i++) {
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        dfs(1);
        printf("%lld\n", f(1, k, 0) );
    }


    return 0;
}
