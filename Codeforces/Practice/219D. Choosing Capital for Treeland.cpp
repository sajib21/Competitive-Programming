#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define pii pair<int,int>
#define LIM 200005

using namespace std;

int n, u,v;
vii graph[LIM], dir[LIM];
int vis[LIM], val[LIM];

int dfs(int u) {
    vis[u] = 1;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i], d = dir[u][i];
        if(vis[v]) continue;
        val[u] += d;
        val[u] += dfs(v);
    }
    return val[u];
}

void dfs2(int u) {
    vis[u] = 1;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i], d = dir[u][i];
        if(vis[v]) continue;
        if(d) val[v] = val[u] - 1;
        else  val[v] = val[u] + 1;
//        val[v] = val[u] - (d);
        dfs2(v);
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d %d", &u,&v);
        graph[u].pb(v); graph[v].pb(u);
        dir[u].pb(0); dir[v].pb(1);
    }
    dfs(1);
//    for(int i=1; i<=n; i++) cout << val[i] << ' ' ; cout << endl;
    memset(vis, 0, sizeof vis);
    dfs2(1);
//    cout << "FIN" << endl;
//    for(int i=1; i<=n; i++) cout << val[i] << ' ' ; cout << endl;

    int ans = INT_MAX;
    for(int i=1; i<=n; i++) ans = min(ans, val[i]);
    printf("%d\n", ans);
    vii sol;
    for(int i=1; i<=n; i++) if(val[i] == ans) sol.pb(i);
    for(int i=0; i<sol.size(); i++) {
        if(i) printf(" ");
        printf("%d", sol[i]);
    }
    printf("\n");

    return 0;
}
