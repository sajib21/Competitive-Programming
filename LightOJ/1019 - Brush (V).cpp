#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define MX1 110
#define MX2 10000000

using namespace std;

struct node {

    int u, key;
    node (int uu, int kk) {
        u = uu, key = kk;
    }

    bool operator > (const node &e) const {
        return key > e.key;
    }
};

int T,t;
int u,v,w;
vector<int>graph[MX1], cost[MX1];
int n,m;
int keys[MX1];

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

    scanf("%d %d", &n,&m);
    for(int i=0; i<=n; i++) graph[i].clear(), cost[i].clear();

    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &u,&v,&w);
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    dijkstra();

    if(keys[n] == MX2) printf("Case %d: Impossible\n", t);
    else printf("Case %d: %d\n", t, keys[n]);
}

void dijkstra() {

    for(int i=0; i<=n; i++) keys[i] = MX2;
//    memset(keys, MX2, sizeof(keys));
    priority_queue< node, vector<node>, greater<node> > pq;
    pq.push(node(1, 0));

    while(!pq.empty()) {
        int u = pq.top().u, k = pq.top().key;
        pq.pop();

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i], w = cost[u][i];
            if(k + w < keys[v]) {
                keys[v] = k + w;
                pq.push(node(v, keys[v]));
            }
        }
    }
}


