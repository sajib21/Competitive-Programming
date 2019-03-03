#include<bits/stdc++.h>

using namespace std;

vector<int>graph[111], cost[111];
//int graph[111], cost[111];
int par[111];

int main() {

    int t,T;
    //cin >> T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        int n, tot = 0;
        //cin >> n;
        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            graph[i].clear();
            cost[i].clear();
        }
        memset(par, 0, sizeof(par));

        for(int i=0; i<n; i++) {
            int u,v,w;
            //cin >> u >> v >> w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(v);
            cost[u].push_back(0);
            graph[v].push_back(u);
            cost[v].push_back(w);
            tot += w;
        }
        int u = 1, now = 0;
        do {
            int sz = graph[u].size();
            for(int i=0; i<sz; i++) if(par[u] != graph[u][i]) {
                par[ graph[u][i] ] = u;
                now += cost[u][i];
                u = graph[u][i];
                break;
            }

        } while(u != 1);

        printf("Case %d: %d\n", t, min(now, tot-now));
    }

    return 0;
}
