#include<bits/stdc++.h>
#define MAXV 610
#define MAXE 100100
#define F_INF 1000000000
#define MXX 99

using namespace std;



struct MaxFlow {
        // MAXV: Number of vertex| MAXE: Number of Edge
        // F_INF: greater than MAXIMUM flow| INF : 1e7
        // i64: long long| SET(x): memset(-1)
        int V, E;int start[MAXV], next[MAXE], v[MAXE];
        int used[MAXV], level[MAXV];int cap[MAXE], flow[MAXE];
        int id[MAXV][MAXV];

        MaxFlow(int n) {
                int i; V = n; E = 0;
                memset(start, -1, sizeof(start));
                memset(id, 0, sizeof id);
        }
        void add_edge(int x, int y, int c) {
//                cout << "EDGE " << x << ' ' << y << ' ' << c << endl;
                id[x][y] = E; cap[E] = c;flow[E] = 0;v[E] = y;next[E] = start[x]; start[x] = E;++E;
                id[y][x] = E; cap[E] = 0;flow[E] = 0;v[E] = x;next[E] = start[y];start[y] = E;++ E;
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
                for (int &i = used[s]; i != -1; i = next[i])
                        //if (level[v[i]] > level[s] && cap[i] > flow[i]) { // should be same
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
                        for (int i = 0; i < V; ++ i) used[i] = start[i];
                        while (dfs(s, t, F_INF) != 0);
                }
                int ret = 0;
                for (int i = start[s]; i != -1; i = next[i]) ret += flow[i];
                return ret;
        }
};

int n,m, st,ed, d1[MAXV], d2[MAXV], nodes, edges, grid[MAXV][MAXV];

int main() {
//    freopen("1262i.txt", "r", stdin);
//    freopen("1262o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        nodes = 2*(n+m-1) + 20;
        MaxFlow g = MaxFlow(nodes);
//        cout << nodes << endl;
        st = 2*(n+m-1); ed = 2*(n+m-1)+1;
        for(int i=0; i<n+m-1; i++) {
            scanf("%d", &d1[i]); //
            g.add_edge(st, i, d1[i]- min( min(n,m) , min(i+1, n+m-1-i) ));
        }
        for(int i=0; i<n+m-1; i++) {
            scanf("%d", &d2[i]);
            g.add_edge(n+m-1+i, ed, d2[i] - min( min(n,m) , min(i+1, n+m-1-i) ));
        } //cout << "b" << endl;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int u = i+j, v = (n+m-1) + i+(m-j-1);
                g.add_edge(u,v, MXX);
            }
        }
//        cout << "BUG" << endl;
        int res = g.maxflow(st,ed);

//        cout << res << endl;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int u = i+j, v = (n+m-1) + i+m-j-1;
                int in = g.id[u][v];
                grid[i][j] = g.flow[in] + 1;
            }
        }

        printf("Case %d:\n", t);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(j) printf(" ");
                printf("%d", grid[i][j]);
            }
            printf("\n");
        }
    }

}
