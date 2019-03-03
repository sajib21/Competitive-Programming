#include<bits/stdc++.h>
#define LIM     505
#define INF     2000000000
#define pii     pair<int,int>
#define ff      first
#define ss      second
#define vi      vector<int>
#define pb(x)   push_back(x)

using namespace std;

struct info{
    int x,y,z, p;
    info() {}
    info(int xx, int yy, int zz, int pp) {
        x = xx, y = yy, z = zz, p = pp;
    }
    bool operator < (const info &b) const {
        return x > b.x;
    }
};

int n,m;
vi g[LIM],c[LIM], e[LIM];
int keys[LIM], par[LIM];
bitset<500*500>ase[LIM];
int ans[LIM][LIM];

void dij(int root) {
    for(int i=1; i<=n; i++) keys[i] = INF;
    memset(ase, 0, sizeof ase);
//    memset(par, 0, sizeof par);
    keys[root] = 0;

    priority_queue<info>pq;
    pq.push(info(keys[root], root, 0, 0));

    while(!pq.empty()) {
        info cur = pq.top();
        pq.pop();
        int u = cur.y, k = cur.x, ed = cur.z, p = cur.p;

        if(k > keys[u]) continue;

        ase[u] |= ase[ p ];
        if(ed) ase[u][ed] = 1;

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i], w = c[u][i], x = e[u][i];
            if(k+w <= keys[v]) {
                keys[v] = k+w;
//                par[v] = u;
                pq.push(info(keys[v], v, x, u));
            }
        }
    }

//    cout << "FROM " << root << endl;
//    for(int i=root+1; i<=n; i++) cout << i << ' ' << ase[i] << ' ' << ase[i].count() << endl;

    for(int v=root+1; v<=n; v++) ans[root][v] = ase[v].count();
}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=1; i<=m; i++) {
        int u,v,w;
        scanf("%d %d %d", &u,&v, &w);
        g[u].pb(v); g[v].pb(u);
        c[u].pb(w); c[v].pb(w);
        e[u].pb(i); e[v].pb(i);
    }

    for(int u=1; u<=n; u++) dij(u);

    bool z = false;

    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(z) printf(" ");
            z = true;
            printf("%d", ans[i][j]);
        }
    }
    printf("\n");
}
