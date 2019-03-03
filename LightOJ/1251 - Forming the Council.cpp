///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             20000
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

int n,m;
vii graph[2*LIM+10], revGraph[2*LIM+10];
stack<int>stk;
int vis[2*LIM+10];
int sol[LIM+10];
int comp[2*LIM+10];

void dfs(int u) {
    vis[u] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

bool dfs2(int u, int c) {
    vis[u] = 1;
    if(comp[ (u+n)%(2*n) ] == c) return false;
    comp[u] = c;
    int sz = revGraph[u].size();
    for(int i=0; i<sz; i++) {
        int v = revGraph[u][i];
        if(!vis[v]) if(!dfs2(v,c)) return false;
    }
//    if(comp[u])
    if(u >= n) {
        if(sol[u-n]) sol[u] = sol[u-n] = 0;
        else sol[u] = 1;
    }
    else sol[u] = 1;
//    sol.pb(u);

    return true;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &m, &n);
        memset(sol, 0, sizeof(sol));
        memset(comp, 0, sizeof(comp));
        for(int i=0; i<2*n; i++) graph[i].clear() , revGraph[i].clear();
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
//            if() u--;
//            v--;
            if(u < 0) u = n - u - 1; else u--;
            if(v < 0) v = n - v - 1; else v--;

//            cout << u << ' ' << v << endl;

            graph[(u+n)%(2*n)].pb(v);
//            cout << (u+n)%(2*n) << ' ' << v << endl;
            graph[(v+n)%(2*n)].pb(u);
//            cout << (v+n)%(2*n) << ' ' << u << endl;
            revGraph[u].pb((v+n)%(2*n));
            revGraph[v].pb((u+n)%(2*n));
        }

//        for(int i=0; i<2*n; i++) {
//            cout << i << " : ";
//            for(int j=0; j<graph[i].size(); j++) cout << graph[i][j] << ' ' ; cout << endl;
//        }

        memset(vis, 0, sizeof(vis));
        for(int i=0; i<2*n; i++) if(!vis[i]) dfs(i);
        memset(vis, 0, sizeof(vis));
        int c = 1;
        bool f = true;
        while(!stk.empty()) {
            int u = stk.top();
            stk.pop();
            if(!vis[u]) if(!dfs2(u, c++)) f = false;
//            cout << u << endl;
        }

//        for(int i=0; i<2*n; i++) cout << i << ' ' << comp[i] << endl;

        if(!f) printf("Case %d: No\n", t);
        else {
            int ans = 0;
            for(int i=0; i<n; i++) if(sol[i]) ans++;
            printf("Case %d: Yes\n", t);
            printf("%d", ans);
            for(int i=0; i<n; i++) if(sol[i]) printf(" %d", i+1);
            printf("\n");
        }


    }

    return 0;
}


