#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back

using namespace std;

int n, vis[2020], p;
vii graph[2020], root;

int dfs(int u) {
    vis[u] = 1;
    int ans = 0;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if(!vis[v]) ans = max(ans, dfs(v));
    }
    return ans + 1;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &p);
        if(p == -1) root.pb(i);
        else graph[p].pb(i);
    }

    int ans = 0;
    for(int i=0; i<root.size(); i++) {
        ans = max(ans, dfs(root[i]));
    }
    cout << ans << endl;

    return 0;
}
