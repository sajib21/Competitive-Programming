/*
Min Cost Max Flow; Graph is directed;

*/

///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             205
#define     MOD             1000000007
#define     MAX             10000000
#define     INF             1<<31 - 1
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);

using namespace std;

struct Edge {
    int v, cap, rev, cost;
    Edge() {}
    Edge(int vv, int cc, int rr, int cs) {
        v = vv; cap = cc; rev = rr; cost = cs;
    }
};
vector<Edge>graph[LIM+10];
int prev[LIM+10], pree[LIM+10];
void addEdge(int u, int v, int cap, int cost) {
    graph[u].pb(Edge(v,cap,graph[v].size(),cost));
    graph[v].pb(Edge(u,0,graph[u].size()-1,-cost));
}

int dis[LIM+10];
int minCostFlow(int s, int t, int f) {
    int u,i,v,d,res=0;
    while(f > 0) {
//        cout << f << endl;
        bool update = true;
        for(i=1; i<=t; i++) dis[i] = -INF;
        dis[s] = 0;
        while(update) {
            update = false;
            for(u=s; u<=t; u++) {
                if(dis[u]==-INF) continue;
                for(i=0; i<graph[u].size(); i++) {
                    Edge &e = graph[u][i];
                    if(e.cap>0 && dis[e.v]<dis[u]+e.cost) {
                        dis[e.v] = dis[u]+e.cost;
                        prev[e.v] = u;
                        pree[e.v] = i;
                        update = true;
                    }
                }
            }
        }
        if(dis[t]==-INF) return -1;
        d=INF;
        for(u=t; u!=s; u=prev[u]) {
            Edge e = graph[ prev[u] ][ pree[u] ];
            d = min(e.cap,d);
        }

        for(u=t; u!=s; u=prev[u]) {
            Edge &e = graph[ prev[u] ][ pree[u] ];
            e.cap -= d;
            graph[e.v][e.rev].cap += d;
        }
        res += dis[t];
        f -= d;
    }
    return res;
}

int minCostFlow2(int s, int t, int f) {
    int u,i,v,d,res=0;
    while(f > 0) {
//        cout << f << endl;
        bool update = true;
        for(i=1; i<=t; i++) dis[i] = INF;
        dis[s] = 0;
        while(update) {
            update = false;
            for(u=s; u<=t; u++) {
                if(dis[u]==INF) continue;
                for(i=0; i<graph[u].size(); i++) {
                    Edge &e = graph[u][i];
                    if(e.cap>0 && dis[e.v]>dis[u]+e.cost) {
                        dis[e.v] = dis[u]+e.cost;
                        prev[e.v] = u;
                        pree[e.v] = i;
                        update = true;
                    }
                }
            }
        }
        if(dis[t]==INF) return -1;
        d=INF;
        for(u=t; u!=s; u=prev[u]) {
            Edge e = graph[ prev[u] ][ pree[u] ];
            d = min(e.cap,d);
        }

        for(u=t; u!=s; u=prev[u]) {
            Edge &e = graph[ prev[u] ][ pree[u] ];
            e.cap -= d;
            graph[e.v][e.rev].cap += d;
        }
        res += dis[t];
        f -= d;
    }
    return res;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n,k,g,c,x, a[60], b[60];
        scanf("%d %d %d", &n, &k, &g);
        int s,e;
        s=0; e=n*2+1;
        for(int i=s; i<=e; i++) graph[i].clear();

        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) scanf("%d", &b[i]);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(a[i] >= b[j]) continue;
                int tim = b[j] - a[i];
                addEdge(i+1, n+j+1, 1, min( sqr(tim-k) , g ) );
//                cout << i+1 << ' ' << n+j+1 << ' ' << min( sqr(a[i]-b[j]) , g ) << endl;
            }
        }
        for(int i=1; i<=n; i++) {
            addEdge(s,i,1,0);
            addEdge(i+n,e,1,0);
        }
        int res = minCostFlow(s,e,n);

        if(res == -1) {
            printf("Case %d: impossible\n", t);
            continue;
        }

        s=0; e=n*2+1;
        for(int i=s; i<=e; i++) graph[i].clear();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(a[i] >= b[j]) continue;
                int tim = b[j] - a[i];
                addEdge(i+1, n+j+1, 1, min( sqr(tim-k) , g ) );
//                cout << i+1 << ' ' << n+j+1 << ' ' << min( sqr(a[i]-b[j]) , g ) << endl;
            }
        }
        for(int i=1; i<=n; i++) {
            addEdge(s,i,1,0);
            addEdge(i+n,e,1,0);
        }
        int res2 = minCostFlow2(s,e,n);

        printf("Case %d: %d %d\n", t, res2, res);


    }

    return 0;
}
