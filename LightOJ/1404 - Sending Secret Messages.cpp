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
#define     LIM             500
#define     MOD             1000000007
#define     MAX             10000000
#define     INF             1<<30 - 1
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
        for(i=1; i<=t; i++) dis[i] = INF;
        dis[s] = 0;
        while(update) {
            update = false;
//            cout << "UPDATE " << endl; getchar();
            for(u=s; u<=t; u++) {
                if(dis[u]==INF) continue;
                for(i=0; i<graph[u].size(); i++) {
                    Edge &e = graph[u][i];
//                    cout << u << ' ' << dis[u] << ' ' <<e.v << ' ' << dis[e.v] << ' ' << e.cost << endl; getchar();
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
        d=f;
        for(u=t; u!=s; u=prev[u]) {
            Edge e = graph[ prev[u] ][ pree[u] ];
            d = min(e.cap,d);
        }

//        cout << "TAKE " << d << " WITH COST " << d*dis[t] << endl;
//        cout << "NODES " ;
        for(u=t; u!=s; u=prev[u]) {
            Edge &e = graph[ prev[u] ][ pree[u] ];
            e.cap -= d;
            graph[e.v][e.rev].cap += d;
//            cout << u << ' ';
        }
//        cout << endl;
        res += d*dis[t];
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
        int n,m,p,c,x;
        scanf("%d %d %d", &n,&m,&p);
        int s,e;
        s=0; e=n+1;
        for(int i=s; i<=e; i++) graph[i].clear();

        ///MAKE GRAPH HERE
        //THIS CODE IS BASED ON LightOJ 1222 - Gift Packing
        for(int i=0; i<m; i++) {
            int u,v,w,c;
            scanf("%d %d %d %d", &u,&v,&c,&w);
            addEdge(u,v,c,w);
            addEdge(v,u,c,w);
        }
//        addEdge(s, 1, p, 0);
//        addEdge(n, e, p, 0);
//        cout << "BUG" << endl;
        int res = minCostFlow(1,n,p);
        if(res != -1) printf("Case %d: %d\n", t, res);
        else printf("Case %d: impossible\n", t);
    }

    return 0;
}
