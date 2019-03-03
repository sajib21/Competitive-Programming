#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 100005
#define ll long long int

using namespace std;

int n,q, a[LIM];
vi g[LIM], cg[LIM];
int sub[LIM];
int root, par[LIM];
bool centroid[LIM];

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
}


///calculating dist(u,v)
int vis[LIM], lev[LIM], cost[LIM], sparse[LIM][20];
void dfs2(int u, int c=0, int l=0) {
    vis[u] = 1; cost[u] = a[u]^c; lev[u] = l+1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        sparse[v][0] = u;
        dfs2(v, cost[u], l+1);
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
    return cost[u] ^ cost[v] ^ a[ getLCA(u,v) ];
}

ll cnt[36][2], ans[36];

void query(int u, int cen, int p) {
//    cout << "Q " << u << ' ' << cen <<  ' ' << p << ' ' << getDist(u, cen) << endl; getchar();
    int d = getDist(u, cen) ^ a[cen];
    for(int i=0; i<32; i++) {
        int m = d&1;
        d /= 2;
        ans[i] += cnt[i][!m];
//        cout << ' ' <<  cnt[i][!m] ;
    }
//    cout << endl;

    for(int v : cg[u]) {
        if(v != p) {
            query(v, cen, u);
        }
    }
}

void update(int u, int cen, int p) {
//    cout << "U " << u << ' ' << cen << ' ' << p << endl; getchar();
    int d = getDist(u, cen);
    for(int i=0; i<32; i++) {
        int m = d&1;
        d /= 2;
        cnt[i][m]++;
//        cout << ' ' << m ;
    }
//    cout << endl;

    for(int v : cg[u]) {
        if(v != p) {
            update(v, cen, u);
        }
    }
}

void process(int u) {
//    cout << "PRO " << u << endl;
    memset(cnt, 0, sizeof cnt);
//    for(int i=0; i<32; i++) cnt[i][0] = 1;

//    query(u, u, par[u]);
//    update(u, u, par[u]);

    int d = a[u];
    for(int i=0; i<32; i++) {
        int m = d&1;
        d /= 2;
        ans[i] += m;
//        cout << ' ' << m ;
    }
//    cout << endl;

    d = a[u];
    for(int i=0; i<32; i++) {
        int m = d&1;
        d /= 2;
        cnt[i][m]++;
//        cout << ' ' << m ;
    }
//    cout << endl;

    for(int v : cg[u]) {
        if(v != par[u]) {
            query(v, u, u);
            update(v, u, u);

//            cout << "UPT " << endl;
//            for(int i=0; i<10; i++) cout << "(" << cnt[i][0] << " " << cnt[i][1] << ") "; cout << endl;
//            for(int i=0; i<10; i++) cout << ans[i] << ' '; cout << endl;
        }
    }

}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    decom();
//    printCenTree();

    makeSparse();

    for(int i=1; i<=n; i++) {
        process(i);
    }

    ll sesh = 0;
    ll dg = 1;

    for(int i=0; i<32; i++) {
        sesh += ans[i]*dg;
        dg *= 2;
    }

    cout << sesh << endl;
}

