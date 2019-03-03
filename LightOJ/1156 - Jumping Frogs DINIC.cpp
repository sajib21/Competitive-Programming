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

int n,D, d[103];
char type;
bool big[103];

bool makeAndFlow(int maxDis) {

    int source = 2*n;
    int sink = source + 1;
    Dinic g(2*n + 2);
    for(int i=0; i<n; i++) {
        if(big[i]) {
            if(d[i] <= maxDis) g.AddEdge(source, i, 2);
            g.AddEdge(i, n+i, 2);
            if(D-d[i] <= maxDis) g.AddEdge(n+i, sink, 2);
        }
        else {
            if(d[i] <= maxDis) g.AddEdge(source, i, 1);
            g.AddEdge(i, n+i, 1);
            if(D-d[i] <= maxDis) g.AddEdge(n+i, sink, 2);
        }

        for(int j=i+1; j<n; j++) {
            if(d[j]-d[i] <= maxDis) {
                g.AddEdge(n+i, j, 2);
                g.AddEdge(n+j, i, 2);
            }
        }
    }
    if(D <= maxDis) g.AddEdge(source, sink, 2);

    return g.GetMaxFlow(source, sink) >= 2;
}

int bs() {
    int lo = 1 , hi = D+3, md;
    bool f = false;
    while(lo < hi) {
        md = (lo + hi) >> 1;
        if(makeAndFlow(md)) hi = md;
        else lo = md;

        if(lo+1 == hi) {
            if(f) break;
            f = true;
        }
    }
    return hi;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &D);
        for(int i=0; i<n; i++) {
            getchar();
            scanf("%c-%d", &type, &d[i]);
            if(type == 'B') big[i] = 1;
            else big[i] = 0;
        }

        printf("Case %d: %d\n", t, bs());
    }

    return 0;
}
