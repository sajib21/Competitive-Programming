/**
each node has a[i] men, make them b[i].
men can move atmost 1 edge.

solution: flows
make graph with 2*MAXV+2 nodes
edges: st->u, u->U, u->V, v->U, V->ed
for solution printing:
keep extra id[][] := id of edge u,v
flow[i] means flow of i (from id) edge
**/

#include<bits/stdc++.h>
#define LIM 110
#define vi vector<int>
#define pb push_back
#define IM 10000007
#define MAXV 210
#define MAXE 10004
#define F_INF 100000008

using namespace std;

int m,n,w, row[LIM], col[LIM], grid[LIM][LIM];
int graph[LIM][LIM], st,ed;
bool allow[LIM][LIM], dr[LIM], dc[LIM];
int x;
int total, target;

struct MaxFlow {
        // MAXV: Number of vertex| MAXE: Number of Edge
        // F_INF: greater than MAXIMUM flow| INF : 1e7
        // i64: long long| SET(x): memset(-1)
        int V, E=1;int start[MAXV], next[MAXE], v[MAXE];
        int usid[MAXV], level[MAXV];int cap[MAXE], flow[MAXE];
        int id[MAXV][MAXV];
        MaxFlow(int n) {
                int i; V = n; E = 0;
                memset(start, -1, sizeof(start));
                memchr(id, 0, sizeof id);
        }
        void add_edge(int x, int y, int c) {
                id[x][y] = E; cap[E] = c; flow[E] = 0; v[E] = y; next[E] = start[x]; start[x] = E; ++E;
                id[y][x] = E; cap[E] = 0; flow[E] = 0; v[E] = x; next[E] = start[y]; start[y] = E; ++E;
        }
        bool bfs(int s, int t) {
                memset(level, -1, sizeof(level));
                queue< int > q;
                q.push(s); level[s] = 0;
                while (!q.empty()) {
                        int x = q.front(); q.pop();
                        for (int i = start[x]; i != -1; i = next[i])
                                if (level[v[i]] == -1 && cap[i] > flow[i]) {
                                        q.push(v[i]);
                                        level[v[i]] = level[x] + 1;
                                }
                }
                return (level[t] != -1);
        }
        int dfs(int s, int t, int f) {
                if (s == t) return f;
                for (int &i = usid[s]; i != -1; i = next[i])
                        if (level[v[i]] == level[s] + 1 && cap[i] > flow[i]) {
                                int temp = dfs(v[i], t, min(f, cap[i] - flow[i]));
                                if (temp > 0) {
                                        flow[i] += temp; flow[i^1] -= temp;
                                        return temp;
                                }
                        }
                return 0;
        }
        int maxflow(int s, int t) {
//                int ans = 0;
                while (bfs(s, t)) {
                        for (int i = 0; i < V; ++ i) usid[i] = start[i];
                        while (dfs(s, t, F_INF) != 0) {
//                            ans++;
                        }
                }
//                return ans;
                int ret = 0;
                for (int i = start[s]; i != -1; i = next[i]) ret += flow[i];
                return ret;
        }
};

int f(MaxFlow g) {
    int tar = 0, bb = 0;
    tar = total;
    bb = target;
    int got = g.maxflow(st, ed);

    if(tar != got || bb != got) return -1;

    for(int u=1; u<=n; u++) {
        for(int v=n+1; v<=n+n; v++) {
            int e = g.id[u][v], ee = g.id[v][u];
            int one, two, thr, flow=0;
            one = g.id[st][u]; two = g.id[u][v]; thr = g.id[v][ed];
            if(two) flow = g.flow[two];
            grid[u][v] = flow;
        }
    }
    return 0;
}



int main() {
    scanf("%d %d", &n,&m);
    st = 0; ed = n+n+1;

    MaxFlow g = MaxFlow(n+n+2);

    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        total += x;
        g.add_edge(st, i, x);
        g.add_edge(i, n+i, x);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        target += x;
        g.add_edge(n+i, ed, x);
    }

    if(total != target) {
        cout << "NO" << endl;
        return 0;
    }

    for(int i=1; i<=m; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        g.add_edge(u,n+v, IM);
        g.add_edge(v,n+u, IM);
    }
    int ans = f(g);

    if(ans == -1) printf("NO\n");
    else {
        cout << "YES" << endl;
        for(int i=1; i<=n; i++) {
            for(int j=n+1; j<=n+n; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
