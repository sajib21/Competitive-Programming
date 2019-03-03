#include <bits/stdc++.h>

using namespace std;

vector<int>graph[50005];
int key[50005], vis[50005];

int dfs(int u) {

    if(vis[u] && key[u]) return key[u];
    if(vis[u]) {

    }

    vis[u] = 1;

    //if(key[u]) return key[u];
    //else return key[u] = graph[u].size() > 0 ?   1 + dfs(graph[u][0]) : 1;
    if(!graph[u].empty() )  {
        if(vis[ graph[u][0] ] && !key[ graph[u][0] ]) {
            vis[u] = 0;
        }
        return key[u] = 1 + dfs(graph[u][0]);
    }
    else return key[u] = 1;
}

int main() {

    int T,t;
    cin >> T;
    for(t=1; t<=T; t++) {

        int n;
        cin >> n;

        for(int i=1; i<=n; i++) graph[i].clear();
        memset(key, 0, sizeof(key));
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<n; i++) {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        int maxMar = 0, mar;
        for(int i=1; i<=n; i++) {
            //maxMar = max(maxMar, dfs(i));
            int temp = dfs(i);
            if(temp > maxMar) {
                maxMar = temp;
                mar = i;
            }

        }
        printf("Case %d: %d\n", t, mar);
    }

    return 0;
}
