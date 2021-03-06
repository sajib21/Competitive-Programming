/**
Directed graph Dijkstra. edges are gives as:
1. u v w (regular)
2. u a b w (edge between u and all nodes in [a,b])
3. v a b w (edge between all nodes in [a,b] and v)

Add nodes which will represent a set of nodes.
Best way of doing this is like segment tree nodes.
Cover all ranges in 4*n nodes and logn nodes needed per query.
Keep 2 segment tree nodes. for u to [a,b] and [a,b] to v.
This way, for each [a,b] you need to add max logn edges.

**/

#include<bits/stdc++.h>
#define LIM 1000006
#define inf 10000000000000000LL
#define ll long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define vi vector<info>
#define vin vector<int>
#define pb(x) push_back(x)
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2

using namespace std;

struct info {
    int x,y,z;
    ll k;
    info() {}
    info(int xx, ll kk) {
        x = xx; k = kk;
    }
    info(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        return k > b.k;
    }
};

int n,q,s;
vin g[LIM], c[LIM];
ll keys[LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        g[n+node].pb(st); c[n+node].pb(0);
        g[st].pb(5*n+node); c[st].pb(0);
        return;
    }
    segVar;

    g[n+node].pb(n+lft); c[n+node].pb(0);
    g[n+node].pb(n+rgt); c[n+node].pb(0);

    g[5*n+lft].pb(5*n+node); c[5*n+lft].pb(0);
    g[5*n+rgt].pb(5*n+node); c[5*n+rgt].pb(0);

    init(lft, st,md); init(rgt, md+1,ed);
}

vin getNodes(int l, int r) {
    vin ans;
    queue<info>q;
    q.push(info(1, 1,n));

    while(!q.empty()) {
        info cur = q.front(); q.pop();
        int node = cur.x, st = cur.y, ed = cur.z;
        segVar;

        if(ed < l || st > r) continue;
        if(st >= l && ed <= r) {
            ans.pb(node);
            continue;
        }
        q.push(info(lft, st,md));
        q.push(info(rgt, md+1,ed));
    }
    return ans;
}

void dij(int root) {
    for(int i=0; i<LIM; i++) keys[i] = inf;
    keys[root] = 0;
    priority_queue<info>pq;
    pq.push(info(root, 0));

    while(!pq.empty()) {
        info cur = pq.top();
        pq.pop();
        int u = cur.x;
        ll k = cur.k;
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i]; ll w = c[u][i];
            if(k+w < keys[v]) {
                keys[v] = k+w;
                pq.push(info(v, keys[v]));
            }
        }
    }
    for(int i=1; i<LIM; i++) if(keys[i] == inf) keys[i] = -1;
}

int main() {
    scanf("%d %d %d", &n,&q,&s);
    init(1, 1,n);

    while(q--) {
        int t, u,v, a,b, w;
        vin U,V;
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d %d %d", &u,&v,&w);
            g[u].pb(v); c[u].pb(w);
        }
        else if(t == 2) {
            scanf("%d %d %d %d", &u, &a,&b, &w);
            V = getNodes(a,b);
            for(int i=0; i<V.size(); i++) {
                v = V[i];
                g[u].pb(n+v); c[u].pb(w);
            }
        }
        else {
            scanf("%d %d %d %d", &v, &a,&b, &w);
            U = getNodes(a,b);
            for(int i=0; i<U.size(); i++) {
                u = U[i];
                g[5*n+u].pb(v); c[5*n+u].pb(w);
            }
        }
    }

    dij(s);

    bool ff = false;
    for(int i=1; i<=n; i++) {
        if(ff) printf(" ");
        ff = true;
        printf("%lld", keys[i]);
    }
    printf("\n");
}
