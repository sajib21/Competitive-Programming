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

int n,k,u,v,w;
vii graph[110];
int costs[110][110];
int vis[110], key[110];
int binTree[110][2];
int dp[110][110];

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

        key[v] = costs[u][v];
        dfs(v);
    }
}

int f(int u, int rem) {
    if(rem < 0) return MAX;
    if(!u) return 0;
    if(dp[u][rem] != -1) return dp[u][rem];
//    cout << "IN " << u << ' ' << rem << endl; getchar();
    int ans = MAX;
    int v = binTree[u][0], s = binTree[u][1];

    for(int r=0; r<=rem-key[u]; r++) {
//        cout << "FIRST " << u << ' ' << rem << " : " << r << ' ' << rem-r-key[u] << endl; getchar();
        ans = min(ans, f(v, r)+f(s, rem-r-key[u])); ///keeping community
    }
//    for(int r=0; r<=rem; r++) {
//        cout << "SECOND " << u << ' ' << rem << " : " << r << ' ' << rem-r << endl; getchar();
        ans = min(ans, 1+f(v, k)+f(s, rem)); ///breaking community
//    }

//    cout << "FROM " << u << ' ' << rem << ' ' << ans << endl; getchar();
    return dp[u][rem] = ans;

}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&k);
        memset(graph, NULL, sizeof graph);
        memset(vis, 0, sizeof vis);
        memset(key, 0, sizeof key);
        memset(binTree, 0, sizeof binTree);
        memset(dp, -1, sizeof dp);


        for(int i=1; i<n; i++) {
            scanf("%d %d %d", &u,&v,&w);
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u][v] = costs[v][u] = w;
        }
        dfs(1);

//        for(int i=1; i<=n; i++) cout << i << " : " << key[i] << " : " << binTree[i][0] << ' ' << binTree[i][1] << endl;

        printf("Case %d: %d\n", t, 1+f(1, k));
    }

    return 0;
}
