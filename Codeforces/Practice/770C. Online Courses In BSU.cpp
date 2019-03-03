#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 100005

using namespace std;

int n,k, x[LIM];
vi g[LIM];
int vis[LIM];
vi sol;

void dfs(int u) {
    vis[u] = 1;

    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v] == 1) {
            printf("-1\n");
            exit(0);
        }
        else if(vis[v] == 2) continue;
        dfs(v);
    }
    sol.pb(u);
    vis[u] = 2;
}

int main() {
    scanf("%d %d", &n,&k);
    for(int i=0; i<k; i++) scanf("%d", &x[i]);
    for(int u=1; u<=n; u++) {
        int t,v;
        scanf("%d", &t);
        for(int j=0; j<t; j++) {
            scanf("%d", &v);
            g[u].pb(v);
        }
    }

    for(int i=0; i<k; i++) {
        int u = x[i];
        if(!vis[u]) dfs(u);
    }

    printf("%d\n", sol.size());
    bool ff = false;
    for(int i=0; i<sol.size(); i++) {
        if(ff) printf(" ");
        ff = true;
        printf("%d", sol[i]);
    }
    printf("\n");
}
