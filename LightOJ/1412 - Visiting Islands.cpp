#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 100005
#define pii pair<int,int>
#define ff first
#define ss second
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
using namespace std;

int n,m;
vi g[LIM];
int vis[LIM], vis2[LIM], mxd, mxs;
vector< pii > d;

int dfs(int u, int p=0) {
//    vis[u] = 1;
    int ans = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(v == p) continue;
        ans += dfs(v, u);
    }
    return ans;
}
int bfs(int root) {
    queue<int>q;
    q.push(root);
    vis[root] = 1;
    int last = root;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if(vis[v]) continue;
            vis[v] = vis[u]+1;
            last = v;
            q.push(v);
        }
    }
//    cout << "LAST " << last << ' ' << q.size() << endl;

    int diam = 0;
    q.push(last);
    vis2[last] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        diam = max(diam, vis2[u]);

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
//            cout << "CHK " << v << ' ' << vis2[v] << endl;
            if(vis2[v]) continue;
            vis2[v] = vis2[u]+1;
            q.push(v);
        }
    }
    return diam;
}

int segTree[4*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = d[st].ss;
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = max(segTree[lft], segTree[rgt]);
}
int query(int node, int st, int ed, int p) {
    if(ed < p) return 0;
    if(st >= p) return segTree[node];
    segVar;
    return max( query(lft, st,md, p) , query(rgt, md+1,ed, p) );
}


int main() {
//    freopen("1412i.txt", "r", stdin);
//    freopen("1412o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(g, NULL, sizeof g);
        d.clear();
        scanf("%d %d", &n,&m);
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            g[u].pb(v); g[v].pb(u);
        }
        memset(vis, 0, sizeof vis);
        memset(vis2, 0, sizeof vis2);
        mxd = mxs = 0;
        for(int u=1; u<=n; u++) if(!vis[u]) {
            int sub = dfs(u);
            int diam = bfs(u);
            mxd = max(mxd, diam);
            mxs = max(mxs, sub);
            d.pb( pii(sub, diam) );
//            cout << "INF " << u << ' ' << sub << ' ' << diam << endl;
        }
        sort(d.begin(), d.end());

        init(1, 0,d.size()-1);

        int q;
        scanf("%d", &q);
        printf("Case %d:\n", t);
        while(q--) {
            int k;
            scanf("%d", &k);
            if(k > mxs) printf("impossible\n");
            else if(k <= mxd) printf("%d\n", k-1);
            else {
                int x = lower_bound(d.begin(), d.end(), pii(k,0)) - d.begin();
                int diam = query(1, 0,d.size()-1, x);
                printf("%d\n", diam + (k-diam)*2 - 1 );
            }
        }
    }
}
