#include<bits/stdc++.h>
#define LIM 2020
#define vi vector<int>
#define pb push_back

using namespace std;

int n,d, a[LIM];
vi g[LIM];
int vis[LIM], lev[LIM], par[LIM][13], mn[LIM][13], mx[LIM][13];

void dfs(int u, int l = 0) {
    vis[u] = 1; lev[u] = l+1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        par[v][0] = u;
        mn[v][0] = min(a[u], a[v]);
        mx[v][0] = max(a[u], a[v]);
        dfs(v, l+1);
    }
}

void makeSparse() {
    dfs(1);
//    cout << "BUG" << endl;
    for(int p=1; p<=11; p++) {
        for(int u=1; u<=n; u++) {
            int md = par[u][p-1];
            if(!md) continue;
            par[u][p] = par[md][p-1];
            mn[u][p] = min(mn[u][p-1], mn[md][p-1]);
            mx[u][p] = max(mx[u][p-1], mx[md][p-1]);
        }
    }
//    cout << "BUGG" << endl;
}

int getMin(int u, int v) {
//    cout << "MIN " << u << ' ' << v << endl;
    if(lev[u] < lev[v]) swap(u,v);
    int up, val = INT_MAX;

    up = 12;
    while(up >= 0) {
        int p = par[u][up], c = mn[u][up];
        if(!p) {
            up--;
            continue;
        }
        if(lev[p] >= lev[v]) {
            val = min(val, c);
            u = p;
        }
        up--;
    }

//    cout << "TEMP MIN VAL: " << val << endl;

    if(u == v) return val;

    up = 12;
    while(up--) {
        if(par[u][up] == par[v][up]) {
            up--;
            continue;
        }
        val = min(val, mn[u][up]);
        val = min(val, mn[v][up]);
        u = par[u][up];
        v = par[v][up];
        up--;
    }

    val = min(val, mn[u][0]);
    val = min(val, mn[v][0]);
//    cout << "BUG" << endl;
    return val;
}

int getMax(int u, int v) {

    if(lev[u] < lev[v]) swap(u,v);
    int up, val = INT_MIN;
//cout << "BUG" << endl;
//    cout << "MAX " << u << ' ' << v << ' ' << lev[u] << ' ' << lev[v] << endl;

    up = 12;
    while(up >= 0) {
        int p = par[u][up], c = mx[u][up];
//        cout << "P V : " << p << ' ' << v << endl;
        if(!p) {
            up--;
            continue;
        }
//        cout << "LEV " << lev[p] << ' ' << lev[v] << endl;
        if(lev[p] >= lev[v]) {
            val = max(val, c);
            u = p;
        }
        up--;
    }

//    cout << "TEMP MAX VAL: " << val << ' ' << u << endl;

    if(u == v) return val;

    up = 12;
    while(up >= 0) {
        if(par[u][up] == par[v][up]) {
            up--;
            continue;
        }
        val = max(val, mx[u][up]);
        val = max(val, mx[v][up]);
        u = par[u][up];
        v = par[v][up];
        up--;
    }
//    cout << "BUG" << endl;

    val = max(val, mx[u][0]);
    val = max(val, mx[v][0]);

    return val;
}

int main() {
    scanf("%d %d", &d,&n);
    for(int u=1; u<=n; u++) scanf("%d", &a[u]);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    makeSparse();

//    cout << "PARSE" << endl;
//    for(int u=1; u<=n; u++) {
//        for(int p=0; p<=2; p++) {
//            cout << u << ' ' << p << " : " << par[u][p] << ' ' << mn[u][p] << ' ' << mx[u][p] << endl;
//        }
//    }

    int ans = 0;
    for(int u=1; u<=n; u++) {
        for(int v=u+1; v<=n; v++) {
            int dif = getMax(u,v) - getMin(u,v);
//            cout << u << ' ' << v << ' ' << getMax(u,v) << ' ' << getMin(u,v) << ' ' << dif << endl;
            ans += (dif <= d);
        }
    }

    cout << ans+n << endl;
}
