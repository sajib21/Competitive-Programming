///MAX FLOW : UNDIRECTED GRAPH

#include<bits/stdc++.h>
#define IM INT_MAX

using namespace std;

int n,m,s,d;
//vector<int>graph[110], costs[110];
int graph[110][110];
int vis[110];

int dfs(int u, int rem) {

    vis[u] = 1;
    if(u == d) return rem;

    for(int v=1; v<=n; v++) {
        if(u != v && !vis[v] && graph[u][v] > 0) {
            int ret = dfs(v, min(rem, graph[u][v]));
            if(ret != -1) {
                graph[u][v] -= ret;
                graph[v][u] += ret;
                return ret;
            }
        }
    }
    return -1;
}

int flow() {

    int ans = 0;

    while(true) {
        memset(vis, 0, sizeof(vis));
        int fl = dfs(s, IM);
        if(fl <= 0) break;
        ans += fl;
    }
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(graph, 0, sizeof(graph));
        scanf("%d", &n);
        scanf("%d %d %d", &s,&d,&m);
        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u][v] += w;
            graph[v][u] += w;
        }
        printf("Case %d: %d\n", t, flow());
    }
    return 0;
}
