#include<bits/stdc++.h>
#define pb push_back
#define IM 10000000
using namespace std;

int n,m, cap,st,et;
vector<int>graph[110], len[110];
int cost[110], keys[110][110]; //rem[110];

struct node{

    int u, key, rem, pre;
    node(int uu, int kk, int rr, int pp) {
        u = uu, key = kk, rem = rr, pre = pp;
    }

    bool operator > (const node &a) const {
        if(key == a.key) return pre < a.pre;
        return key > a.key;
    }
};

int dijkstra() {

    for(int j=0; j <= 100; j++) for(int i=0; i<=n; i++) keys[j][i] = IM; //for(int i=0;) rem[i] = 0;

    keys[0][st] = 0;
    priority_queue < node, vector<node>, greater<node> > pq;
    pq.push(node(st, 0, 0, 0) );

    while(!pq.empty()) {

        node nd = pq.top(); pq.pop();
        int u = nd.u, key = nd.key, rem = nd.rem, preCost = nd.pre;

        if(u == et) break;

//        if(u == 4) cout << u << ' ' << keys[u] << endl;

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i], length = len[u][i];
            if(length > cap) continue;

            int res = key + max(0, length - rem) * cost[u] + min(length, rem) * preCost;

            int remNow;
            if(cost[v] > cost[u]) remNow = cap - length;
            else remNow = 0;

            if(res <= keys[remNow][v]) {
                keys[remNow][v] = res;
//                if(cost[v] > cost[u])
                pq.push(node( v , keys[remNow][v], remNow, cost[u]) );
//                else pq.push(node( v, keys[v], 0, 0) );
            }
        }
    }
//    for(int i=0; i<n; i++) cout << keys[i] << ' '; cout << endl;
    int ans = IM;
    for(int rem=0; rem <=100; rem++) ans = min(ans, keys[rem][et]);
    return ans;
}

int main() {

    int T, q;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d %d", &n,&m);
        for(int i=0; i<=n; i++) graph[i].clear(), len[i].clear();

        for(int i=0; i<n; i++) scanf("%d", &cost[i]);
        for(int i=0; i<m; i++) {
            int u,v,l;
            scanf("%d %d %d", &u,&v,&l);
            graph[u].pb(v);
            graph[v].pb(u);
            len[u].pb(l);
            len[v].pb(l);
        }

        scanf("%d", &q);
        printf("Case %d:\n", t);
        while(q--) {

            scanf("%d %d %d", &cap,&st,&et);
            int ans = dijkstra();

            if(ans == IM) printf("impossible\n");
            else printf("%d\n", ans);
        }
    }

    return 0;
}
