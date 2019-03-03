/// MAX FLOW = MIN CUT

#include<bits/stdc++.h>
#define LIM 110
#define vi vector<int>
#define pb push_back
#define IM 10000007
#define MAXV 110
#define MAXE 10004
#define F_INF 100000008

using namespace std;

int m,n,w, row[LIM], col[LIM], grid[LIM][LIM];
int graph[LIM][LIM], st,ed;
bool allow[LIM][LIM], dr[LIM], dc[LIM];

struct MaxFlow {
        int V, E;int start[MAXV], next[MAXE], v[MAXE];
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
    memset(grid, 0, sizeof grid);
    int tar = 0, bb = 0;
    for(int i=1; i<=m; i++) tar += row[i];
    for(int i=1; i<=n; i++) bb += col[i];
    int got = g.maxflow(st, ed);

    if(tar != got || bb != got) return -1;

    for(int u=1; u<=m; u++) {
        for(int v=m+1; v<=n+m; v++) {
            int e = g.id[u][v], ee = g.id[v][u];
            int one, two, thr;
            one = g.id[st][u]; two = g.id[u][v]; thr = g.id[v][ed];

            if(!g.flow[two]) {
                g.cap[two] = 0;
            }
            else {
                g.flow[one]--; g.flow[two]--; g.flow[thr]--;
                g.flow[one^1]++; g.flow[two^1]++; g.flow[thr^1]++;
                g.cap[ two ] = 0;

                int temp = g.maxflow(st, ed);
                if(temp == got) {
                    grid[u][v-m] = 0;
                }
                else {
                    g.flow[one]++; g.flow[two]++; g.flow[thr]++;
                    g.flow[one^1]--; g.flow[two^1]--; g.flow[thr^1]--;
                    g.cap[ two ] = 0;

                    grid[u][v-m] = 1;
                }
            }
        }

    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &m,&n);
        st = 0; ed = m+n+1;

        MaxFlow g = MaxFlow(m+n+2);

        for(int i=1; i<=m; i++) {
            scanf("%d", &row[i]);
            graph[st][i] = row[i];
            g.add_edge(st,i, row[i]);
        }
        for(int i=1; i<=n; i++) {
            scanf("%d", &col[i]);
            graph[m+i][ed] = col[i];
            g.add_edge(m+i,ed, col[i]);
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                graph[i][m+j] = 1;
                g.add_edge(i, m+j, 1);
            }
        }

        if(f(g) == -1) printf("Case %d: impossible\n", t);
        else {
            printf("Case %d:\n", t);
            for(int i=1; i<=m; i++) {
                for(int j=m+1; j<=m+n; j++) {
                    printf("%d", grid[i][j-m]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
