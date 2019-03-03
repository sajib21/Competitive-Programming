/*
Min Cost Max Flow; Graph is directed;
Assumes all cap is 1/0
*/

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
        if(dis[t]==-INF) break;
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
        int n,c,x;
        scanf("%d", &n);
        int s,e;
        s=0; e=n*2+1;
        for(int i=s; i<=e; i++) graph[i].clear();

        ///MAKE GRAPH HERE
        //THIS CODE IS BASED ON LightOJ 1222 - Gift Packing
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &x);
                addEdge(i,j+n,1,x);
            }
        }
        for(int i=1; i<=n; i++) {
            addEdge(s,i,1,0);
            addEdge(i+n,e,1,0);
        }
        int res = minCostFlow(s,e,n);
        printf("Case %d: %d\n", t, res);
    }

    return 0;
}
