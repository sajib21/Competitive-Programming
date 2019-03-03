#include <bits/stdc++.h>
#define IM 22000
using namespace std;

struct node {

    int u, key;
    node(int uu, int k) {
        u = uu;
        key = k;
    }

    bool operator > (const node &e) const {
        return key > e.key;
    }
};

vector<int>graph[505], cost[505];
int key[505];
int n, m, init;

void dijkstra() {

    priority_queue<node, vector<node>, greater<node> >pq;
    key[init] = 0;
    pq.push(node(init, key[init]));

    while(!pq.empty()) {

        node nd = pq.top();
        pq.pop();

        int u = nd.u;
        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];

            if(max(key[u], cost[u][i]) < key[v]) {
                key[v] = max(key[u], cost[u][i]);
                pq.push(node(v, key[v]));
            }
        }
    }


}

int main() {

    int t,T;
    cin >> T;
    for(t=1; t<=T; t++) {

        //memset(key, IM, sizeof(key));

        cin >> n >> m;

        for(int i=0; i<n; i++) key[i] = IM;
        for(int i=0; i<n; i++) {
            graph[i].clear(); cost[i].clear();
        }

        for(int i=0; i<m; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        cin >> init;

        dijkstra();

        printf("Case %d:\n", t);
        for(int i=0; i<n; i++) {
            if(key[i] == IM) {
                printf("Impossible\n");
            }
            else printf("%d\n", key[i]);
        }
    }

    return 0;
}
