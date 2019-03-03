#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX  10000000
#define MIN -10000000

using namespace std;

struct node {
    int u,key, left;
    node() {}
    node(int uu, int kk, int lll) {u = uu; key = kk; left = lll;}

    bool operator < (const node &b) const {
        if(key == b.key) return left < b.left;
        return key < b.key;

    }
};

///DIRECTION ARRAY
/*
int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};
*/

///FOR GRAPH
int n,m;
//int graph[LIM+10][LIM+10];
int vis[LIM+10], par[LIM+10], keys1[LIM+10], keys2[LIM+10];
vector<int>graphV[LIM+10], costsV[LIM+10];

int s,t,p;

int dijkstra(int s, int t) {

    memset(keys2, 0, sizeof(keys2));
    for(int i=1; i<=n; i++) keys1[i] = MIN;
    keys1[s] = 0;
    priority_queue<node>pq;
    pq.push(node(s, 0, p) );
    int ans = -1;

    while(!pq.empty()) {
        node nd = pq.top();
        pq.pop();
        int u = nd.u, k = nd.key , l = nd.left;

        if(u == t) {
            ans = max(ans, k);
        }

        int sz = graphV[u].size();
        for(int i=0; i<sz; i++) {
            int v = graphV[u][i], c = costsV[u][i];
            if( max(k, c) > keys1[v] && l >= c) {
                keys1[v] = max(k,c);
                keys2[v] = l-c;
                pq.push(node(v, max(k,c), l-c) );
            }
            else if( max(k, c) <= keys1[v] && l >= c && l-c > keys2[v]) {
//                keys1[v] = max(k,c);
                keys2[v] = l-c;
                pq.push(node(v, max(k,c), l-c) );
            }
        }
    }
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++) {
        scanf("%d %d %d %d %d", &n,&m,&s,&t,&p);
        for(int i=1; i<=n; i++) graphV[i].clear() , costsV[i].clear();

        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graphV[u].pb(v);
            costsV[u].pb(w);
        }

        printf("Case %d: %d\n", tt, dijkstra(s,t));

    }

    return 0;
}
