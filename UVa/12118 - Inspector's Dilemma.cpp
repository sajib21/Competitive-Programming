#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 1010

using namespace std;

int n,m,t, ans,cnt, u,v;
vi g[LIM];
int vis[LIM];

void dfs(int u) {
    vis[u] = 1;
    cnt += g[u].size()&1;
    for(int  i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main() {
    int T=1;
    while(scanf("%d %d %d", &n,&m,&t)) {
        if(!n && !m && !t) return 0;

        memset(g, NULL, sizeof g);
        memset(vis, 0, sizeof vis);

        for(int i=0; i<m; i++) {
            scanf("%d %d", &u,&v);
            g[u].pb(v);
            g[v].pb(u);
        }

        ans = 0;
        for(int i=1; i<=n; i++) if(!vis[i] && g[i].size()) {
            cnt = 0;
            dfs(i);
            ans += max(cnt,2);
        }

        printf("Case %d: %d\n", T++, (m+max(ans/2-1, 0))*t );
    }
}
