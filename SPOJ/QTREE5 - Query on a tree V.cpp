///given a tree, color/discolor some nodes and tell the shortest distance
///from a node to the nearest colored node(maybe itself)
#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 100005
#define MAX 20000007

using namespace std;

int n,q;
vi g[LIM], cg[LIM];
int sub[LIM];
int root, par[LIM];
bool centroid[LIM];

///decomposition specific
void dfs(int u, int p=0) {
    sub[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(p == v || centroid[v]) continue;
        dfs(v,u);
        sub[u] += sub[v];
    }
}

int getCentroid(int u, int p=0, int pc=0) {
    bool ok = true;
    int up = 1, nxt;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i], sz;
        if(centroid[v]) continue;

        if(v == p) sz = pc;
        else sz = sub[v];

        if(sz > sub[root]/2) ok = false, nxt = v;
        else up += sz;
    }
    if(ok) return u;
    else return getCentroid(nxt, u, up);
}

void decom() {
    root = 1;
    dfs(root);
    root = getCentroid(root);

    queue<int>q;
    q.push(root);
    centroid[root] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if(centroid[v]) continue;

            root = v;
            dfs(v);
            int cen = getCentroid(v);
            centroid[cen] = true;

            cg[u].pb(cen);
            cg[cen].pb(u);
            par[cen] = u;
            q.push(cen);
        }
    }
}
void printCenTree() {
    cout << "CENTROID TREE " << endl;
    for(int i=1; i<=n; i++) {
        cout << i << " : ";
        for(int j=0; j<cg[i].size(); j++) cout << cg[i][j] << ' ';
        cout << endl;
    }
    cout << "PAR: " << endl;
    for(int i=1; i<=n; i++) cout << i << ' ' << par[i] << endl;
}

///calculating dist(u,v)
int vis[LIM], lev[LIM], cost[LIM], sparse[LIM][20];
void dfs2(int u, int c=0, int l=0) {
    vis[u] = 1; cost[u] = c; lev[u] = l+1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        sparse[v][0] = u;
        dfs2(v, c+1, l+1);
    }
}
void makeSparse() {
    dfs2(1);
    for(int p=1; p<=18; p++) {
        for(int u=1; u<=n; u++) {
            int m = sparse[u][p-1];
            if(!m) continue;
            sparse[u][p] = sparse[ m ][p-1];
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
int getDist(int u, int v) {
    return cost[u] + cost[v] - 2*cost[ getLCA(u,v) ];
}

///problem specific
bool red[LIM];
multiset<int>dis[LIM];
void update(int u) {
    int U = u;
    while(u) {
//        dis[u] = min(dis[u], getDist(U, u) );
        dis[u].insert( getDist(U,u) );
//        cout << "ADD " << u << ' ' << getDist(U,u) << endl;
        u = par[u];
    }
}
void reupdate(int u) {
    int U = u;
    while(u) {
//        dis[u] = min(dis[u], getDist(U, u) );
        dis[u].erase( dis[u].find( getDist(U,u) ) );
//        cout << "REM " << u << ' ' << getDist(U,u) << endl;
        u = par[u];
    }
}
int query(int u) {
    int U = u;
    int ans = MAX;
    while(u) {
//        ans = min(ans, dis[u] + getDist(U, u) );
        ans = min(ans, *dis[u].begin() + getDist(U,u) );
        u = par[u];
    }
    return ans;
}

int main() {
//    cout << *dis[0].begin() << endl;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    decom();
//    printCenTree();

    makeSparse();

    for(int i=1; i<=n; i++) dis[i].insert(MAX);

//    update(1);

    scanf("%d", &q);

    while(q--) {
        int c, x;
        scanf("%d %d", &c, &x);
        if(c == 0) {
//            cout << "UPDATE " << x << ' ' << red[x] << endl;
            if(red[x]) reupdate(x);
            else       update(x);
            red[x] = !red[x];

//            update(x);
        }
        else {
            int ans = query(x);
            if(ans == MAX) ans = -1;
            printf("%d\n", ans );
        }
    }

}
