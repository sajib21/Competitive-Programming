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
#define     LOG             20
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

struct info{
    int x,y,z;
    info() {x = y = z = 0;}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};
bool cmpx(info x, info y) {
    return x.x < y.x;
}
bool cmpy(info x, info y) {
    return x.y < y.y;
}

int n,m, u,v, k;
vii g[LIM+10], graph[LIM+10], tree[LIM+10];
int vis[LIM+10], dis[LIM+10], low[LIM+10], tax[LIM+10];
int tim = 0;
void dfs2(int u, int pre = 0) {
    dis[u] = low[u] = ++tim;
    int sz = g[u].size();
    for(int i=0; i<sz; i++) {
        int v = g[u][i];
        if(v == pre) continue;

        if(!dis[v]) {
            dfs2(v, u);
            if(low[v] > dis[u]) tax[v] = 1; /// eitare low[u] diya try koira dekhum
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], dis[v]);
    }
}

void dfs1(int u) {
    vis[u] = 1;
    int sz = g[u].size();
    for(int i=0; i<sz; i++) {
        int v = g[u][i];
        if(vis[v]) continue;

        graph[u].pb(v);
        graph[v].pb(u);
        dfs1(v);
    }
}

int lev[LIM+10], par[LIM+10][LOG+10], cost[LIM+10][LOG+10];

int dfs(int u) {
    if(u == 1) lev[u] = 0;
    else lev[u] = lev[ par[u][0] ] + 1;
    int sz = graph[u].size();

    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!lev[v] && v != 1) {
            par[v][0] = u;
            cost[v][0] = tax[v];
            dfs(v);
        }
    }
}

void makeSparse() {
    for(int p=1; p<=LOG; p++) {
        for(int u=1; u<=n; u++) {
            if(par[u][p-1] != -1) {
                par[u][p] = par[ par[u][p-1] ][ p-1 ];
                cost[u][p] =  cost[u][p-1] + cost[ par[u][p-1] ][p-1] ;
            }
        }
    }
}

int getLCA(int u, int v) {
    if(lev[u] < lev[v]) swap(u,v);

    int ans = 0;
    int up = log2(lev[u]) ;
    while(up >= 0) {
        int sp = par[u][up];
        if( lev[u] - (1 << up) >= lev[v]) {
            ans += cost[u][up];
            u = sp;
        }
        up--;
    }

    up = log2(lev[u]) ;
    while(up >= 0) {
        if(par[u][up] != par[v][up]) {
            ans += cost[u][up] + cost[v][up];
            u = par[u][up];
            v = par[v][up];
        }
        up--;
    }

    if (u == v) return ans;
    return ans += cost[u][0] + cost[v][0];
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d %d", &n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    tim = 0;
    dfs2(1);
    dfs1(1);
//    for(int i=1; i<=n; i++) cout << tax[i] <<  ' ' ; cout << endl;

    dfs(1);
    makeSparse();

    scanf("%d", &k);
    while(k--) {
        scanf("%d %d", &u,&v);
        printf("%d\n", getLCA(u,v) );
    }

    return 0;
}
