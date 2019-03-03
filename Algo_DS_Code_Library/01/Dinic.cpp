struct MaxFlow {
        // MAXV: Number of vertex| MAXE: Number of Edge
        // F_INF: greater than MAXIMUM flow| INF : 1e7
        // i64: long long| SET(x): memset(-1)
        int V, E;int start[MAXV], next[MAXE], v[MAXE];
        int used[MAXV], level[MAXV];int cap[MAXE], flow[MAXE];
        MaxFlow(int n) {
                int i; V = n; E = 0;
                memset(start, -1, sizeof(start));
        }
        void add_edge(int x, int y, int c) {
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
