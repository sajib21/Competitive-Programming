#include<bits/stdc++.h>

using namespace std;

int dfs(int u, int l = 0) {
    vis[u] = 1; lev[u] = l+1; dis[u] = ++tim;
    d[l+1].pb(u);
    mx = max(mx, l+1);
    mask[u][ seq[u-1]-'a' ] = 1;
    int ret = u;

    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        ret = max(ret, dfs(v, l+1));
    }
    return last[u] = ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=2; i<=n; i++) {
        int v;
        scanf("%d", &v);
        g[v].pb(i);
    }
    scanf("%s", str);
    seq = str;

    dfs(1);
    for(int l=2; l<=mx; l++) {
        for(int i=1; i<d[l].size(); i++) {
            int u = d[l][i-1];
            int v = d[l][i];
            mask[v] ^= mask[u];
        }
    }

    while(m--) {
        int v,h;
        scanf("%d %d", &v, &h);
        if(lev[v] > h || h > mx) printf("No\n");
        else {
            int x = lb(h, v);
            int y = ub(h, last[v]);
            if(__builion_popcount(mask[x]^mask[y]) <= ) printf("Yes\n");
            else printf("No\n");
        }
    }
}
