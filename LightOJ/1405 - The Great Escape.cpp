#include<bits/stdc++.h>
#define MAXV 60020
#define MAXE 180010
#define F_INF 1000000000

using namespace std;

int dR[] = {-1,  0,  0, +1};
int dC[] = { 0, -1, +1,  0};

struct MaxFlow {
        // MAXV: Number of vertex| MAXE: Number of Edge
        // F_INF: greater than MAXIMUM flow| INF : 1e7
        // i64: long long| SET(x): memset(-1)
        int V, E;int start[MAXV], next[MAXE], v[MAXE];
        int used[MAXV], level[MAXV];int cap[MAXE], flow[MAXE];
//        int id[MAXV][MAXV];

        MaxFlow(int n) {
                int i; V = n; E = 0;
                memset(start, -1, sizeof(start));
//                memset(id, 0, sizeof id);
        }
        void add_edge(int x, int y, int c) {
//                cout << "EDGE " << x << ' ' << y << ' ' << c << endl;
                 cap[E] = c;flow[E] = 0;v[E] = y;next[E] = start[x]; start[x] = E;++E;
                 cap[E] = 0;flow[E] = 0;v[E] = x;next[E] = start[y];start[y] = E;++ E;
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

int n,m, st,ed, nodes, split, man, edges;
char grid[110][110];

int main() {
//    freopen("1262i.txt", "r", stdin);
//    freopen("1262o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        nodes = 2*n*m + 2;
        MaxFlow g = MaxFlow(nodes);
        man = 0;
        st = 2*n*m; ed = 2*n*m+1;

        for(int i=0; i<n; i++) scanf("%s", grid[i]);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int cur = i*m + j;
                g.add_edge(2*cur, 2*cur+1, 1);

                for(int k=0; k<4; k++) {
                    int vi = i+ dR[k];
                    int vj = j+ dC[k];
                    if(vi < 0 || vi >= n || vj < 0 || vj >= m || grid[vi][vj] != '.') continue;
                    g.add_edge(2*cur+1, 2*(vi*m+vj), 1);
                }

                if(grid[i][j] == '*') {
                    man++;
                    g.add_edge(st, 2*cur, 1);
                }

                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    g.add_edge(2*cur+1, ed, 1);
                }
            }
        }

        int res = g.maxflow(st,ed);
//        cout << man << ' ' << res << endl;
        if(res == man) printf("Case %d: yes\n", t);
        else printf("Case %d: no\n", t);
    }

}
