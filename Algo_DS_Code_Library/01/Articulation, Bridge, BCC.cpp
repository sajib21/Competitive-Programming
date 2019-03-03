int tim = 0;
void dfs(int u, int par = -1) {
    low[u] = dis[u] = ++tim;
    int v, sz = g[u].size(), comp = 0;

    for(int i = 0; i < sz; ++i) {
        v = g[u][i];
        if(v == par) continue;
        else if(dis[v]) low[u] = min(low[u], disc[v]);
        else {
            ++comp;
            dfs(v, u);

            if(par == -1 && comp > 1) arti[u] = true;
            if(par != -1 && low[v] >= dis[u]) arti[u] = true;

            low[u] = min(low[u], low[v]);
        }
    }
}
