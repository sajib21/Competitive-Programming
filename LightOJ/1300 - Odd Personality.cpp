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

using namespace std;

int n,m, vis[LIM+100], low[LIM+10], odd[LIM+100], color[LIM+10];
vii g[LIM+100];
map<pii, bool> mp;

int tim = 0;
void dfs(int u, int pre) {
    low[u] = vis[u] = ++tim;
    int sz = g[u].size(), comp = 0;;
    for(int i=0; i<sz; i++) {
        int v = g[u][i];
        if(v == pre) continue;
        else if(vis[v]) low[u] = min(low[u], vis[v]);
        else {
            dfs(v, u);
            if(low[v] > vis[u]) mp[mpr(u,v)] = mp[mpr(v,u)] = 1;
            low[u] = min(low[v], low[u]);
        }
    }
}

bool dfs2(int u, int pre, int c) {
    vis[u] = 1;
    color[u] = c;
    int sz = g[u].size();
    for(int i=0; i<sz; i++) {
        int v = g[u][i];
        if(v == pre || mp[mpr(u,v)]) continue;
        else if(color[v] == c) return true;
        else if(!vis[v]) {
            if(dfs2(v, u, 3-c)) return true;
        }
    }
    return false;
}

void dfs3(int u) {
    odd[u] = 1;
    int sz = g[u].size();
    for(int i=0; i<sz; i++) {
        int v = g[u][i];
        if(mp[mpr(u,v)] || odd[v]) continue;
        dfs3(v);
    }
}



int main() {
//    freopen("1300i.txt", "r", stdin);
//    freopen("1300o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        memset(g, NULL, sizeof g);
        mp.clear();
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            g[u].pb(v); g[v].pb(u);
        }
        tim = 0;
        memset(low, 0, sizeof low);
        memset(vis, 0, sizeof vis);
        for(int u=0; u<n; u++) if(!vis[u]) dfs(u, -1);

        memset(color, 0, sizeof color);
        memset(vis, 0 ,sizeof vis);
        memset(odd, 0, sizeof odd);
        for(int u=0; u<n; u++) if(!vis[u]) {
            if(dfs2(u, -1, 1 )) {
//                cout << "INIT " << u << endl;
                dfs3(u);
            }
        }
        int ans = 0;
        for(int u=0; u<n; u++) ans += odd[u];
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
