#include<bits/stdc++.h>

using namespace std;

void dfs(int u, int cst = 0, int l = 0) {
    vis[u] = 1;
    lev[ u ] = l;
    cost[ mask[u] ] = genies[u] + cst;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            mask[v] = ++msk;
            dfs(v, cost[ mask[u] ], l+1);
            sparse[ v ][0] = u;
        }
    }
    subTreeEnd[u] = msk;
}

void makeSparse() {
    int lim = log2(n) + 1;
    for(int par = 1; par <=lim; par++) { ///EI PART E LOG NILE PROBLEM HOY NA
        for(int u=1; u<=n; u++) {
            if(sparse[u][par-1] != -1) {
                sparse[u][par] = sparse[ sparse[u][par-1] ][par-1];
            }
        }
    }
}

int getLCA(int u, int v) {
    if(lev[u] < lev[v]) swap(u,v);

    int up = log2(lev[u]) ;
    while(up >= 0) {
        int sp = sparse[u][up];
        if( lev[u] - (1 << up) >= lev[v]) {
            u = sp;
        }
        up--;
    }

    up = log2(lev[u]) ;
    while(up >= 0) {
        if(sparse[u][up] != sparse[v][up]) {
            u = sparse[u][up];
            v = sparse[v][up];
        }
        up--;
    }

    if (u == v) return u;
    return sparse[u][0];
}
