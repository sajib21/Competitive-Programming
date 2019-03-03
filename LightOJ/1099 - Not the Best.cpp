#include<bits/stdc++.h>

using namespace std;

struct node {

    int v; int k;
    node(int vv, int kk) {
    v = vv; k = kk;
    }

    bool operator > (const node &n) const {
        return k > n.k;
    }
};

int n,r;
vector<int>graph[5005],cost[5005];
int key1[5005];
int key2[5005];

void dijkstra() {

    memset(key1, -129, sizeof(key1));
    memset(key2, -129, sizeof(key2));

    priority_queue<node, vector<node>, greater<node> >pq;

    key1[1] = 0;
    pq.push(node(1, key1[1]));

    while(!pq.empty()) {

        node nd = pq.top();
        pq.pop();
        int u = nd.v;

        for(int i=0; i<graph[u].size(); i++) {
            int v = graph[u][i];
            if(nd.k + cost[u][i] < key1[v]) {
                key2[v] = key1[v];
                key1[v] = nd.k + cost[u][i];
                pq.push(node(v, key1[v]));
                //cout << "key 1 er ta v er 1st r 2nd " << key1[v] << "  " << key2[v] << "  u r v hoilo " << u << v << endl;
            }
            else if(nd.k + cost[u][i] == key1[v]) {

            }
            else if(nd.k + cost[u][i] < key2[v]) {
                key2[v] = nd.k + cost[u][i];
                pq.push(node(v, key2[v]));
                //cout << "key 2 er ta v er 1st r 2nd " << key1[v] << "  " << key2[v] << "  u r v hoilo " << u << v << endl;

            }
        }
    }



}

int main() {

    int T,t;
    cin >> T;
    for(t=1; t<=T; t++) {

        cin >> n >> r;
        for(int i=1; i<=n; i++) {
            graph[i].clear();
            cost[i].clear();
        }


        for(int i=0; i<r; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        dijkstra();

        printf("Case %d: %d\n",t, key2[n]);
    }

    return 0;
}
