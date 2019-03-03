#include<bits/stdc++.h>
#define LIM 100005
#define vi vector<int>
#define pb push_back

using namespace std;

int n,k, uu[LIM], vv[LIM], vis[LIM], lev[LIM], keys[LIM], tim, sparse[LIM][20], mx;
vi g[LIM], nodes[LIM];

void dfs(int u, int l=0) {
    vis[u] = 1; lev[u] = l+1; nodes[l+1].pb(u); mx = max(mx, l+1);
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        sparse[v][0] = u;
        dfs(v, l+1);
    }
}

void makeSparse() {
    int up = 18;
    for(int p=1; p<=up; p++) {
        for(int u=1; u<=n; u++) {
            if(sparse[u][p-1]) {
                sparse[u][p] = sparse[ sparse[u][p-1] ][ p-1 ];
            }
        }
    }
}

int getLCA(int u, int v) {
    if(lev[u] < lev[v]) swap(u,v);

    int up =18;
    while(up >= 0) {
        int sp = sparse[u][up];
        if(lev[sp] >= lev[v]) {
            u = sp;
        }
        up--;
    }
    if(u == v) return u;

    up = 18;
    while(up >= 0) {
        if(sparse[u][up] != sparse[v][up]) {
            u = sparse[u][up];
            v = sparse[v][up];
        }
        up--;
    }
    return sparse[u][0];
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        uu[i] = u; vv[i] = v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1);
    makeSparse();

    scanf("%d", &k);
    while(k--) {
        int u,v;
        scanf("%d %d", &u,&v);
        int lca = getLCA(u,v);
        keys[u]++; keys[v]++; keys[lca] -= 2;
//        cout << u << ' ' << v << " LCA " << lca << " : " << keys[u] << ' ' << keys[v] << ' ' << keys[lca] << endl;
    }

//    cout << "SLIDE" << endl;
    for(int i=mx; i>0; i--) {
        for(int j=0; j<nodes[i].size(); j++) {
            int u = nodes[i][j];
            int v = sparse[u][0];
            keys[v] += keys[u];

//            cout << u << ' ' << v << ' ' << keys[v] << endl;
        }
    }
//    cout << "FIN" << endl;
//    for(int i=1; i<=n; i++) cout << i << ' ' << keys[i] << endl;

    for(int i=1; i<n; i++) {
        if(i > 1) printf(" ");
        if(lev[ uu[i] ] > lev[ vv[i] ]) printf("%d", keys[ uu[i] ]);
        else                            printf("%d", keys[ vv[i] ]);
    }
    printf("\n");
}
