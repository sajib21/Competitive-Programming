#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

const int INF = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if (!e) {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }

    void ClearFlow() {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < G[i].size(); ++j)
                G[i][j].flow = 0;

    }
};

int n,m, mx, k;
vii graph[103], costs[103];

bool makeAndFlow(int maxDis) {

    int N = n+2;
    int source = 0;
    int sink = N + n+1;
    Dinic g(3*n + 4);
//    cout << "DINIC" << endl;

    g.AddEdge(0, 0+N, 11);
    for(int i=1; i<=n; i++) g.AddEdge(i, N+i, 1);
    g.AddEdge(n+1, n+1+N, 11);

    for(int u=0; u<=n+1; u++) {
        int sz = graph[u].size();
//        cout << u << ' ' << sz << endl;
        for(int i=0; i<sz; i++) {
            int v = graph[u][i], c = costs[u][i];
//            cout << u << ' ' << v << endl;
            if(c <= maxDis) {
                g.AddEdge(u+N,v, 1);

            }
        }
    }
    return g.GetMaxFlow(0, N+n+1) >= k;
}

int bs() {
//    cout << "BS" << endl;
    int lo = 1 , hi = mx+1, md;
    bool f = false;
    while(lo < hi) {
        md = (lo + hi) >> 1;
        if(makeAndFlow(md)) hi = md;
        else lo = md+1;

        if(lo+1 == hi) {
            if(f) break;
            f = true;
        }
//        cout << lo << ' ' << md << ' ' << hi << endl;
    }
    return hi;
}

int main() {

//    freopen("1167i.txt", "r", stdin);
//    freopen("1167o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &m);
        mx = 0;
        for(int i=0; i<=n+1; i++) graph[i].clear();
        for(int i=0; i<=n+1; i++) costs[i].clear();
        for(int i=0; i<m; i++) {
            int u,v,d;
            scanf("%d %d %d", &u,&v,&d);
            if(v < u) swap(u,v);
            graph[u].pb(v);
            costs[u].pb(d);
            mx = max(mx, d);
        }

//        cout << "GRAPH" << endl;
//        for(int u=0; u<=n+1; u++) {
//            for(int i=0; i<graph[u].size(); i++) cout << graph[u][i] << ' ' ;
//            cout << endl;
//        }

        scanf("%d", &k);
        int hi = bs();
        if(hi == mx+1) printf("Case %d: no solution\n", t);
        else printf("Case %d: %d\n", t, hi);
    }

    return 0;
}
