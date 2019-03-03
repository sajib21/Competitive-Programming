#include<bits/stdc++.h>
#define vi      vector<int>
#define pb(x)   push_back(x)
#define LIM     100005
#define LOG     18

using namespace std;

int n,m, root;
vi g[LIM], p[LIM];
int tim=0, dis[LIM], vis[LIM];
vi order;
vi tree[LIM];
int par[LIM][20], lev[LIM];

void dfs(int u) {
    vis[u] = 1; dis[u] = ++tim;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
    order.pb(u);
}

int getLCA(int u, int v) {
    if(lev[u] < lev[v]) swap(u,v);

    int up;

    up = LOG;
    while(up >= 0) {
        int sp = par[u][up];
        if(lev[sp] >= lev[v]) u = sp;
        up--;
    }

    up = LOG;
    while(up >= 0) {
        if(par[u][up] != par[v][up]) {
            u = par[u][up];
            v = par[v][up];
        }
        up--;
    }

    if(u == v) return u;
    return par[u][0];
}

void update(int u) {
    for(int i=1; i<=LOG; i++) {
        if(par[u][i-1]) par[u][i] = par[ par[u][i-1] ][ i-1 ];
    }
}

void printTree() {
    queue<int>q;
    q.push(root);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " : ";
        for(int i=0; i<tree[cur].size(); i++) {
            cout << tree[cur][i] << ' ';
            q.push(tree[cur][i]);
        }
        cout << endl;
    }
}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); ///main dag
        p[v].pb(u); ///reverse/parents
    }

    ///add root (make a new parent of all roots if necessary)
    root = 0;
    for(int u=1; u<=n; u++) {
        if(!p[u].size()) {
            p[u].pb(root);
            g[root].pb(u);
        }
    }

    ///topsort
    memset(vis, 0, sizeof vis);
    dfs(root);
    reverse(order.begin(), order.end());
//    for(int i=0; i<order.size(); i++) cout << order[i] << ' '; cout << endl;

    for(int i=1; i<order.size(); i++) {
        int u = order[i];
        int d = p[u][0];
        for(int j=1; j<p[u].size(); j++) {
            int v = p[u][j];
            d = getLCA(d, v);
        }
        tree[d].pb(u); ///tree is kept directed (downwards) currently.
        par[u][0] = d; lev[u] = lev[d] + 1;
        update(u);
    }

    printTree();
}
