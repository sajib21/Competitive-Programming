#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 250005
#define ll long long int

using namespace std;

int n,a[LIM], bst[LIM][2];
vi g[LIM], cg[LIM];
int sub[LIM];
int root, par[LIM];
ll res[LIM], cnt[LIM], rem[LIM];
bool centroid[LIM];
set<int>ase;

/// make bst then g[]
void add(int v) {
    set<int>:: iterator it = ase.lower_bound(v);
    if(it == ase.end() || bst[*it][0]) {
        it--;
        bst[*it][1] = v;
    }
    else {
        bst[*it][0] = v;
    }
    ase.insert(v);
}

void df(int u) {
    if(bst[u][0]) {
        int v = bst[u][0];
        g[u].pb(v);
        g[v].pb(u);
        df(v);
    }
    if(bst[u][1]) {
        int v = bst[u][1];
        g[u].pb(v);
        g[v].pb(u);
        df(v);
    }
}

void makeBST() {
    int rt = a[1];
    ase.insert(rt);
    for(int i=2; i<=n; i++) {
        add(a[i]);
    }
    df(rt);
}

///decompose
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
    root = a[1];
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

void update(int u) {
    int U = u;
    cnt[u]++;

    while(par[u]) {
        int p = par[u];
        cnt[p]++;
        int w = getDist(U, p);
        res[p] += w;
        rem[u] += w;

        u = p;
    }
//    cout << "AFTER UPDATE" << endl;
//    for(int i=1; i<=n; i++) cout << res[i] << ' '; cout << endl;
//    for(int i=1; i<=n; i++) cout << rem[i] << ' '; cout << endl;
}

ll query(int u) {
//    cout << "QUERY " << u << endl;
    int U = u;
    ll ans = res[u];

    while(par[u]) {
        int p = par[u];
        ll temp = getDist(U, p)*(cnt[p]-cnt[u]) + res[p] - rem[u];
        ans += temp;
//        cout << "IN " << u << ' ' << p << ' ' << getDist(U,p) << ' ' << temp << ' ' << ans << endl;
        u = p;
    }
//    cout << "RET " << ans << endl;
    return ans;
}

void printCenTree() {
    cout << "CENTROID TREE " << endl;
    cout << "ROOT " << root << endl;
    for(int i=1; i<=n; i++) {
        cout << i << " : ";
        for(int j=0; j<cg[i].size(); j++) cout << cg[i][j] << ' ';
        cout << endl;
    }
    cout << "PAR " << endl;
    for(int i=1; i<=n; i++) cout << i << ' ' << par[i] << endl;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    makeBST();

    decom();
//    printCenTree();

    makeSparse();

    ll ans = 0;

    for(int i=1; i<=n; i++) {
        ll temp = query(a[i]);
        ans += temp;
        update(a[i]);
//        cout << temp << endl;
        printf("%lld\n", ans);
    }

}

/*
8
4 7 3 1 8 2 6 5
*/
