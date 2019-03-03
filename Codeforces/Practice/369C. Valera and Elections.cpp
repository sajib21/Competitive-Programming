#include<bits/stdc++.h>
#define LIM 200005
#define pb push_back

using namespace std;

vector<int>graph[LIM], bad[LIM];
bool vis[LIM], flag[LIM];
int n;

bool dfs(int u) {
    vis[u] = 1;
    bool ase = false;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i], t = bad[u][i];
        if(vis[v]) continue;
        if(t == 2) {
            flag[u] = 0;
            flag[v] = 1;
            ase = true;
        }
        ase |= dfs(v);
    }
    if(ase) flag[u] = 0;
    return ase;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u,v,t;
        scanf("%d %d %d", &u,&v,&t);
        graph[u].pb(v); graph[v].pb(u);
        bad[u].pb(t); bad[v].pb(t);
    }

    dfs(1);
    int ans = 0;
    for(int i=1; i<=n; i++) ans += flag[i];
    cout << ans << endl;
    bool f = false;
    for(int i=1; i<=n; i++) if(flag[i]) {
        if(f) printf(" ");
        printf("%d", i);
        f = true;
    }
}
