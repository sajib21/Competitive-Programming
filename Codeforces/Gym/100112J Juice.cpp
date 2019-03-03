///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             1000
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

int n, u,v, p,d,c;
vii graph[LIM+10];
int cap[LIM+10], dem[LIM+10];
int vis[LIM+10];
int binTree[LIM+10][2];

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

int dp[LIM+10][250][2];
int f(int u, int rem, int cc) {
    if(rem < 0) return -MAX;
    if(!u) return 0;
    if(dp[u][rem][cc] != -1) return dp[u][rem][cc];
//    int sz = graph[u].size();
    int ans = 0;
    int c = binTree[u][0], s = binTree[u][1];

    if(cc) {
        return dp[u][rem][cc] = max( f(c, cap[u],0) , 1+f(c, cap[u]-dem[u],0) );
    }

    for(int r=0; r<=rem; r++) { ///na nia
        int rr = rem - r;
//        if(r < cap[u] || rr < cap[s]) continue;
        ans = max(ans, f(c, min(r,cap[u] ), 0)+f(s, rr, 0) );
    }
    for(int r=0; r<=rem; r++) { ///nia
        int rr = rem - r;
//        if( min(r,cap[u]) < dem[u] ) continue;
        ans = max(ans, 1+f(c, min(r,cap[u])-dem[u], 0)+f(s, rr, 0) );
    }
    return dp[u][rem][cc] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    memset(dp, -1, sizeof dp);

    scanf("%d", &n);
    for(int u=2; u<=n+1; u++) {
        scanf("%d %d %d", &p, &d,&c); p++;
        graph[p].pb(u); graph[u].pb(p);
        cap[u] = c;dem[u] = d;
    }
    dfs(1);
//    dem[1] = 1000;
    cap[1] = 210;
//    for(int i=1; i<=n+1; i++) cout << i << " : " << binTree[i][0] << ' ' << binTree[i][1] << endl;
    int ans = 0;
    for(int i=0; i<graph[1].size(); i++) {
        int u = graph[1][i];
        ans += f(u, cap[u], 1);
//        cout << u << ' ' << f(u, cap[u], 1) << endl;
    }
    printf("%d\n", ans);

    return 0;
}
