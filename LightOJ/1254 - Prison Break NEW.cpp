#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100
#define MOD 1000000007
#define MAX 1000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

struct info{
    int v, key, left;
    info() {}
    info(int vv, int kk, int lll) {
        v = vv; key = kk; left = lll;
    }
    bool operator < (const info &b) const {
        if(key == b.key) left < b.left;
        return key > b.key;
    }
};

int n,m,q, price[LIM+10];
int cap, st, ed;
vii graph[LIM+10], costs[LIM+10];

int dijkstra() {
    int keys[LIM+10][LIM+10];
    memset(keys, -1, sizeof(keys));
    keys[st][0] = 0;
    priority_queue<info>pq;
    pq.push(info(st, 0, 0));

    while(!pq.empty()) {
        info nd = pq.top();
        pq.pop();
        int u = nd.v , k = nd.key , l = nd.left;
        if(u == ed) return k;

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i], cst = costs[u][i];
            for(int buy=max(0,cst-l); buy<=cap-l; buy++) {
                if(keys[v][ buy+l-cst ] == -1 || k+buy*price[u] < keys[v][buy+l-cst] ) {
                    keys[v][buy+l-cst] = k+buy*price[u];
                    pq.push(info(v, keys[v][buy+l-cst], buy-cst+l));
                }
            }
        }
    }
    return -1;
}

int main() {

//    freopen("1254i.txt", "r", stdin);
//    freopen("1254o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) graph[i].clear() , costs[i].clear();
        for(int i=0; i<n; i++) scanf("%d", &price[i]);
        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u].pb(w);
            costs[v].pb(w);
        }
        scanf("%d", &q);
        printf("Case %d:\n", t);
        while(q--) {
            scanf("%d %d %d", &cap, &st, &ed);
            int ans = dijkstra();
            if(ans == -1) printf("impossible\n", t);
            else printf("%d\n", ans);
        }
    }
    return 0;
}
