#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define MX1 10010
#define MX2 10000000

using namespace std;

struct node {

    int u, key, d;
    node (int uu, int kk, int dd) {
        u = uu, key = kk, d = dd;
    }

    bool operator > (const node &e) const {
        if(key == e.key) return d < e.d;
        return key > e.key;
    }
};

int T,t;
int u,v,w;
vector<int>graph[MX1], cost[MX1], xGraph[MX1], xCost[MX1];
int n,m, k,d;
int keys[12][MX1], ex[MX1];

void solve();
void dijkstra();

int main() {

    scanf("%d", &T);
    for(t=1; t<=T; t++) {
        solve();
    }

    return 0;
}

void solve() {

    scanf("%d %d %d %d", &n,&m,&k,&d);
    for(int i=0; i<=n; i++) graph[i].clear(), cost[i].clear(), xGraph[i].clear(), xCost[i].clear();

    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &u,&v,&w);
        graph[u].push_back(v);
//        graph[v].push_back(u);
        cost[u].push_back(w);
//        cost[v].push_back(w);
    }
    for(int i=0; i<k; i++) {
        scanf("%d %d %d", &u,&v,&w);
        xGraph[u].push_back(v);
//        xGraph[v].push_back(u);
        xCost[u].push_back(w);
//        xCost[v].push_back(w);
    }

    dijkstra();

    int ans = MX2;
    for(int i=0; i<=d; i++) ans = min(ans, keys[i][n-1]);
    if(ans == MX2) printf("Case %d: Impossible\n", t);
    else printf("Case %d: %d\n", t, ans);
}

void dijkstra() {

    for(int tim = 0; tim <=10; tim++) for(int i=0; i<=n; i++) keys[tim  ][i] = MX2;
//    memset(ex, 0, sizeof(ex));
//    memset(keys, MX2, sizeof(keys));
    priority_queue< node, vector<node>, greater<node> > pq;
    pq.push(node(0, 0, 0));
    keys[0][0] = 0;

//    int tmp=1;
    while(!pq.empty()) {
        node nd = pq.top();
        int u = nd.u, k = nd.key, dt = nd.d;
        pq.pop();
//        cout << u << ' ' << k << ' ' << dt << endl;

//        if(dt > d) continue;

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i], w = cost[u][i];
            if(k + w < keys[dt][v]) {
                keys[dt][v] = k + w;
                pq.push(node(v, keys[dt][v], dt));
            }
        }

//        if(dt == d) continue;

        sz = xGraph[u].size();
        for(int i=0; i<sz; i++) {
            int v = xGraph[u][i], w = xCost[u][i];
            if(k + w < keys[dt+1][v]) {
                keys[dt+1][v] = k + w;
//                ex[v]++;
                pq.push(node(v, keys[dt+1][v], dt+1));
            }
        }
//        cout << tmp << "th iteration" << endl;
//        tmp++;
//        for(int i=0; i<n; i++) cout << i << ' ' << keys[i] << endl;
    }
}


