#include<bits/stdc++.h>
#define LIM         200006
#define vi          vector<int>
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define pii         pair<int,int>

using namespace std;

struct info {
    int x, lft, rgt;
    info() {x = lft = rgt = 0;}
};

int n,m,k, u,v, a[LIM];
vi g[LIM];
vector<pii>num;
int level[LIM], par[LIM][22];
int NODES, root[LIM];
info segTree[LIM*22];

void update(int node, int pre, int st, int ed, int p) {
//    cout << "UP " << node << ' ' << pre << ' ' << st << ' ' << ed << ' ' << p << endl; getchar();
    segTree[node] = segTree[pre];
    if(st == p && ed == p) {
        segTree[node].x++;
        return;
    }
    int lft=0,rgt=0, md = (st+ed) / 2;
    lft = segTree[node].lft, rgt = segTree[node].rgt;
    if(p <= md) {
        segTree[node].lft = ++NODES;
        update(segTree[node].lft, segTree[pre].lft, st,md, p);
    }
    else {
        segTree[node].rgt = ++NODES;
        update(segTree[node].rgt, segTree[pre].rgt, md+1,ed, p);
    }
    lft = segTree[node].lft, rgt = segTree[node].rgt;
    segTree[node].x = segTree[lft].x + segTree[rgt].x;
//    cout << "OUT " << node << ' ' << pre << ' ' << st << ' ' << ed << ' ' << p << ' ' << segTree[node].x << endl; getchar();
}

int query(int u, int v, int lca, int lcap, int st, int ed, int k) {
//    cout << "QRY " << u << ' ' << v << ' ' << lca << ' ' << lcap << ' ' << st << ' ' << ed << ' ' << k << endl; getchar();
    if(st == ed) return st;
    int lft, rgt, md = (st+ed) / 2;
    int a = segTree[u].lft, b = segTree[v].lft, c = segTree[lca].lft, d = segTree[lcap].lft;
    int val = segTree[a].x + segTree[b].x - segTree[c].x - segTree[d].x;
//    cout << "INSEG " << val << endl; getchar();
    if(k <= val) return query(segTree[u].lft, segTree[v].lft, segTree[lca].lft, segTree[lcap].lft, st,md, k);
    else       return query(segTree[u].rgt, segTree[v].rgt, segTree[lca].rgt, segTree[lcap].rgt, md+1,ed, k-val);
}

void dfs(int u, int l=0) {
    level[u] = l+1;
    root[u] = ++NODES;
//    cout << "INIT " << u << ' ' << root[u] << ' ' << a[u] << endl;
    update(root[u], root[ par[u][0] ], 1,n, a[u]);
//    cout << segTree[ root[u] ].x << endl; getchar();

    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(level[v]) continue;
        par[v][0] = u;
        dfs(v, l+1);
    }
}

void makeSparse() {
    for(int p=1; p<=19; p++) {
        for(int u=1; u<=n; u++) {
            int temp = par[u][p-1];
            if(temp != -1) {
                par[u][p] = par[ temp ][p-1];
            }
        }
    }
}

int getLCA(int u, int v) {
    if(level[u] < level[v]) swap(u,v);
    int up = 19;
    while(up >= 0) {
        if(level[u] - (1 << up) >= level[v] ) u = par[u][up];
        up--;
    }
    if(u == v) return u;
    up = 19;
    while(up >= 0) {
        if(par[u][up] != par[v][up]) {
            u = par[u][up];
            v = par[v][up];
        }
        up--;
    }
    return par[u][0];
}

int lb(pii x) {
    int lo = 0, hi = num.size(), md;
    while(lo < hi) {
        md = (lo+hi) / 2;
        if(num[md] >= x) hi = md;
        else lo = md + 1;
    }
    return hi;
}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        num.pb(pii(a[i],i));
    }
    sort(all(num));
//    map<int,int>mp;
//    int id = 0;
//    for(int i=0; i<num.size(); i++) mp[ num[i] ] = i+1;
    for(int i=1; i<=n; i++) a[i] = lb( pii(a[i],i)) + 1;
//    for(int i=0; i<num.size(); i++) cout << num[i].first << ' ' << num[i].second << endl;

//    for(int i=1; i<=n; i++) cout <<a[i] << ' ' ; cout << endl;

    for(int i=1; i<n; i++) {
        scanf("%d %d", &u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(par, -1, sizeof(par));
    dfs(1);
    makeSparse();

//    cout << segTree[1].x << endl;

//    cout << "APR" << endl;
//    for(int i=1; i<=n; i++) cout << i << ' ' << root[i] << endl; getchar();

    while(m--) {
        scanf("%d %d %d", &u,&v, &k);
        int lca = getLCA(u,v);
//        cout << u << ' ' << v << " " << lca << ' ' << par[lca][0] << endl;
//        cout << root[u] << ' ' << root[v] << ' ' << root[lca] << ' ' << root[ par[lca][0] ] << endl;
        int val = query(root[u], root[v], root[lca], root[ par[lca][0] ], 1,n, k);
//        cout << val << ' ' << num[val].first << ' ' << num[val-1].first << endl;
        printf("%d\n", num[val-1].first);
    }
}
