#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int>graph[1010];

int dp[1010][2], vis[1010], par[1010];

int getMax(int u, int lastTaken) {

    vis[u] = 1;

    if(dp[u][lastTaken] != -1) return dp[u][lastTaken];

    int sz = graph[u].size();
    int uNiyeAns = 1, uCharaAns = 0;

    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(v != par[u]) {
            par[v] = u;
            uCharaAns += getMax(v, false);
        }
    }

    if(!lastTaken) {
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            if(v != par[u]) {
                par[v] = u;
                uNiyeAns += getMax(v, true);
            }
        }
    }
    else uNiyeAns = 0;

    return dp[u][lastTaken] = max(uNiyeAns, uCharaAns);
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(vis, 0, sizeof(vis));
        memset(par, 0, sizeof(par));
        memset(dp, -1, sizeof(dp));

        scanf("%d %d", &n,&m);
        for(int i=1; i<=n; i++) graph[i].clear();

        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                ans += getMax(i, 0);
            }
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
