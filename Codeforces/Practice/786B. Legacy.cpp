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
//    cout << "GET " << l << ' ' << r << endl;
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
//    cout << "OUT ";
//    for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
//    cout << endl;
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

//        cout << "IN " << u << ' ' << k << endl; getchar();

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i]; ll w = c[u][i];
//            cout << "CHK " << v << ' ' << w << endl; getchar();
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
//cout << "INIT" << endl;
//    for(int i=1; i<=9*n; i++) {
//        cout << i << " : ";
//        for(int j=0; j<g[i].size(); j++) cout << g[i][j] << ' ';
//        cout << endl;
//    }
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
//                cout << 2 << " ADD " << u << ' ' << v << ' ' << n+v << ' ' << w << endl;
            }

        }
        else {
            scanf("%d %d %d %d", &v, &a,&b, &w);
            U = getNodes(a,b);
            for(int i=0; i<U.size(); i++) {
                u = U[i];
                g[5*n+u].pb(v); c[5*n+u].pb(w);
//                cout << 3 << " ADD " << u << ' ' <<5*n+u << ' ' << v << ' ' << w << endl;
            }
        }
    }
//    cout << "HERE" << endl;
//    for(int i=1; i<=9*n; i++) {
//        cout << i << " : ";
//        for(int j=0; j<g[i].size(); j++) cout << g[i][j] << ' ';
//        cout << endl;
//    }

    dij(s);

    bool ff = false;
    for(int i=1; i<=n; i++) {
        if(ff) printf(" ");
        ff = true;
        printf("%lld", keys[i]);
    }
    printf("\n");
}
