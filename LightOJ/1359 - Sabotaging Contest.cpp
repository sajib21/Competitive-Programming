
#include<bits/stdc++.h>
#define vi      vector<int>
#define pb(x)   push_back(x)
#define LIM     100005
#define LG     18
#define ll      long long int

using namespace std;

struct info {
    int x,z; ll y;
    info() {x = y = z = 0;}
    info(int xx, ll yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        return y > b.y;
    }
    bool operator > (const info &b) const {
        return y < b.y;
    }
};

int n,m, root;
vi G[LIM], W[LIM], g[LIM], p[LIM];
ll keys[LIM], ok[LIM], vis[LIM];
vi order;
vi tree[LIM];
int par[LIM][20], lev[LIM], sub[LIM];

void dij(int root) {
    keys[root] = 0;
    priority_queue<info>pq;
    pq.push(info(root, keys[root], root));

    while(!pq.empty()) {
        info cur = pq.top();
        pq.pop();
        int u = cur.x, pre = cur.z;
        ll k = cur.y;
        if(k != keys[u]) continue;

        if(u != root) {
            g[pre].pb(u); p[u].pb(pre);
        }
        if(ok[u]) continue;
        ok[u] = 1;

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i], w = W[u][i];
            if(k+w <= keys[v]) {
                keys[v] = k+w;
                pq.push(info(v, keys[v], u));
            }
        }
    }
//    cout << "MAIN DAG" << endl;
//    for(int u=0; u<n; u++) {
//        cout << u << " : ";
//        for(auto v : g[u]) cout << v << " " ; cout << endl;
//    }
//    cout << endl;
}

void dfs(int u) {
    vis[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
    order.pb(u);
}


bool ff = false;
int getLCA(int u, int v) {
    if(lev[u] < lev[v]) swap(u,v);

    int up;

    up = LG;
    while(up >= 0) {
        int sp = par[u][up];
        if(lev[u] - (1 << up) >= lev[v]) u = sp;
        up--;
    }

    up = LG;
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
    for(int i=1; i<=LG; i++) {
        if(par[u][i-1] != -1) par[u][i] = par[ par[u][i-1] ][ i-1 ];
    }
}

void printTree() {
    cout << "PRINT TREE" << endl;
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
    cout << "SPARSE " << n << endl;
    for(int i=0; i<=n; i++) {
            cout << i << " : ";
        for(int j=0; j<5; j++) cout << par[i][j] << ' '; cout << endl;
    }
    cout << endl;
}

void dfs2(int u) {
    sub[u] = 1;
    for(int i=0; i<tree[u].size(); i++) {
        int v = tree[u][i];
        dfs2(v);
        sub[u] += sub[v];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(G, NULL, sizeof G);
        memset(W, NULL, sizeof W);
        memset(g, NULL, sizeof g);
        memset(p, NULL, sizeof p);
        memset(tree, NULL, sizeof tree);
        memset(par, -1, sizeof par);
        memset(lev, 0, sizeof lev);
        memset(sub, 0, sizeof sub);
//        memset(vis, 0, sizeof vis);


        scanf("%d %d", &n,&m);
        for(int i=0; i<m; i++) {
            int u,v, w;
            scanf("%d %d %d", &u,&v, &w);
            G[u].pb(v); W[u].pb(w);
            G[v].pb(u); W[v].pb(w);
        }

        for(int i=0; i<=n; i++) keys[i] = 1000000000;
        memset(ok, 0, sizeof ok);
//        for(int u=0; u<n; u++) if(!ok[u]) dij(u);
        dij(0);

//        int extra = 0;
//        for()

        root = 0;
//        for(int u=0; u<n; u++) if(!p[u].size()) {
//            g[root].pb(u);
//            p[u].pb(root);
//        }

        ///topsort
        memset(vis, 0, sizeof vis);
        order.clear();
        dfs(root);
        reverse(order.begin(), order.end());
//        cout << "ORDER " << endl;
//        for(int i=0; i<order.size(); i++) cout << order[i] << ' '; cout << endl;

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
//        printTree();

//        cout << getLCA(5,2) << endl;

        dfs2(root);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", t);
        while(q--) {
            int k, u, d;
            bool fg = true;
            int okcnt = 0;
            int notokcnt = 0;
            scanf("%d", &k);
            if(k == -1) break;

            vi st;
            while(k--) {
                scanf("%d", &u);
                if(ok[u]) {
                    okcnt++;
                    st.pb(u);
//                    cout << "ASE " << u << endl;
                }
                else notokcnt++;
            }

//            cout << "QQ " ; for(int i=0; i<st.size(); i++) cout << st[i] << ' ' ; cout << endl;

            if(!okcnt) {
                printf("0\n");
                continue;
            }

            d = st[0];
            for(int i=1; i<st.size(); i++) {
                u = st[i];
                d = getLCA(d, u);
//                cout << "D " << d << endl;
            }
//            cout << d << ' ' << sub[d] << ' ' << sub[0] << endl;
            printf("%d %d\n", lev[d]+1, sub[d]);
        }

    }
}
