#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pb(x) push_back(x)
#define LIM 100005

using namespace std;

/*
    given weighted tree, query(u, w) : how many nodes reachable
    from u with <= distance w.
    decom. and calc. info for all centroid (nlogn memory).
    messy part: for each cen. subtracting results from children.
    in other problems this can be done easily by querying in children.
    but here, we need to keep track of info for
    each children of each centroid separately.
*/

/*
    Copy variables and these functions from library.

    DECOMPOSITION:
    void dfs(int u, int p=0);
    int getCentroid(int u, int p=0, int pc=0);
    void decom();
    void printCenTree();

    INFORMATION:
    void dfs2(int u, ll c=0, int l=0); // modify c problem wise
    void makeSparse();
    int getLCA(int u, int v);
    ll getDist(int u, int v); // modify function problem wise
    // add new function life getDist if necessary
*/

int n,q;
vi g[LIM], wt[LIM], cg[LIM];
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
    cout << "PAR " << endl;
    for(int i=1; i<=n; i++) cout << i << ' ' << par[i] << endl;
}

///calculating dist(u,v)
int vis[LIM], lev[LIM], sparse[LIM][20];
ll cost[LIM];
void dfs2(int u, ll c=0, int l=0) {
    vis[u] = 1; cost[u] = c; lev[u] = l+1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i], w = wt[u][i];
        if(vis[v]) continue;
        sparse[v][0] = u;
        dfs2(v, c+w, l+1);
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
ll getDist(int u, int v) {
    return cost[u] + cost[v] - 2*cost[ getLCA(u,v) ];
}

vl dis[LIM], tempv;
vector<int>id[LIM];
vector<vl>badd[LIM];

void update(int u, int cen, int p, int in) {
    ll d = getDist(u, cen);
    assert(d >= 0);
    dis[cen].pb(d);
    tempv.pb(d);

    for(int v : cg[u]) {
        if(v != p) update(v, cen, u, in);
    }
}

int query(int U, ll W) {
    int ans = upper_bound(dis[U].begin(), dis[U].end(), W) - dis[U].begin();
    int u = par[U], v = U;

    while(u) {
        int badid = lower_bound(id[u].begin(), id[u].end(), v) - id[u].begin();

        ans += ( upper_bound(dis[u].begin(), dis[u].end(), W-getDist(U,u) ) - dis[u].begin() ) -
               ( upper_bound(badd[u][badid].begin(), badd[u][badid].end(), W-getDist(U,u) ) - badd[u][badid].begin() );

        v = u;
        u = par[u];
    }
    return ans;
}

int brute(int u, ll w) {
    int ans = 0;
    for(int v=1; v<=n; v++) {
        ans += getDist(u,v) <= w;
    }
    return ans;
}


int main() {
    scanf("%d %d", &n,&q);
    for(int i=1; i<n; i++) {
        int u,v,w;
        scanf("%d %d %d", &u,&v, &w);
        g[u].pb(v); g[v].pb(u);
        wt[u].pb(w); wt[v].pb(w);
    }
    decom();
    for(int i=1; i<=n; i++) sort(cg[i].begin(), cg[i].end());
    makeSparse();

    for(int u=1; u<=n; u++) {
        dis[u].pb(0);
        for(int i=0; i<cg[u].size(); i++) {
            int v = cg[u][i];
            if(v != par[u]) {
                tempv.clear();
                update(v, u, u, i);
                sort(tempv.begin(), tempv.end());
                badd[u].pb(tempv);
                id[u].pb(v);

            }
        }
        sort(dis[u].begin(), dis[u].end());
    }

    while(q--) {
        int u;
        ll w;
        scanf("%d %lld", &u, &w);
        printf("%d\n", query(u, w));
    }

}

