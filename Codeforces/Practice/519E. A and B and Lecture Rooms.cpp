#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define LIM 1000005
#define LOG 20
using namespace std;

int n,m, u,v;
vi graph[LIM];
int lev[LIM], sub[LIM], par[LIM][22];

int dfs(int u, int l = 0) {
    lev[u] = l+1;
    sub[u] = 1;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if(lev[v]) continue;
        par[v][0] = u;
        sub[u] += dfs(v, l+1);
    }
    return sub[u];
}

void init() {
    memset(par, -1, sizeof par);
    dfs(1);
    for(int p=1; p<LOG; p++) {
        for(int u=1; u<=n; u++) if(par[u][p-1] != -1) {
            par[u][p] = par[ par[u][p-1] ][p-1];
        }
    }
}

int query(int U, int V) {
    if(U == V) return n;
    if(lev[U] < lev[V]) swap(U,V);
    int u = U, v = V;
    int c = LOG;
    while(c >= 0 && lev[u] > lev[v]) {
        int temp = par[u][c];
        if(temp != -1 && lev[temp] >= lev[v]) u = temp; /// check here library
        c--;
    }

    int tar = 0;
    if(u != v) {
        int c = LOG;
        while(c >= 0) {
            if(par[u][c] != par[v][c]) {
                u = par[u][c];
                v = par[v][c];
            }
            c--;
        }
        u = par[u][0];
    }

    tar = (lev[U]+lev[V] - 2*lev[u]);
    if(tar%2) return 0;
    tar /= 2;
//    cout << "LCA " << u << " TAR " << tar << endl;

    int bk = tar;

    u = U;
    c = LOG;
    while(c >= 0) {
        int temp = par[u][c];
        if((1 << c) < tar) {
            u = temp;
            tar -= (1 << c);
        }
        c--;
    }
    int pu = u;
    if(tar) pu = par[pu][0];

    if(lev[U] == lev[V]) {
        v = V;
        c = LOG;
        tar = bk;
        while(c >= 0) {
            int temp = par[v][c];
            if((1 << c) < tar) {
                v = temp;
                tar -= (1 << c);
            }
            c--;
        }
//        int pv = par[v][0];
//        cout << pu << " MINUS " << u << ' ' << v << endl;
        return n - sub[u] - sub[v];
    }
//    cout << pu << ' ' << "MINUSed " << u << ' ' << sub[pu] << ' ' << sub[u] << endl;
    return sub[pu] - sub[u];
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d %d", &u,&v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    init();

    scanf("%d", &m);
    while(m--) {
        scanf("%d %d", &u,&v);
        printf("%d\n", query(u,v));
    }

    return 0;
}
