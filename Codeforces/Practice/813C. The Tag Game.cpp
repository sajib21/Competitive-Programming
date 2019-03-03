#include<bits/stdc++.h>
#define LIM 200005
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n,x, keys1[LIM], keys2[LIM];
vi G[LIM];

void bfs(int root, int vis[]) {
    queue<int>q;
    q.push(root);
    vis[root] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : G[u]) {
            if(vis[v] == -1) {
                vis[v] = vis[u]+1;
                q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &x);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        G[u].pb(v); G[v].pb(u);
    }

    memset(keys1, -1, sizeof keys1);
    memset(keys2, -1, sizeof keys2);

    bfs(1, keys1);
    bfs(x, keys2);

    int ans = -1;

    for(int u=1; u<=n; u++) {
        if(keys1[u] >= keys2[u]) ans = max(ans, 2*keys1[u]);
    }
    cout << ans << endl;
}
