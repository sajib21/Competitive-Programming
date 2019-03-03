#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mpr make_pair
#define vp vector<pii>
#define pb push_back
#define LIM 200000

using namespace std;

int n,m;
vp graph[LIM+100];
int f[LIM+100], g[LIM+100], color[LIM+100];

int bfs(int root) {
    queue<int>q;
    q.push(root);
    f[root] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i].ss, c = graph[u][i].ff;
//            cout << i << ' ' << v << ' ' << f[v] << endl;
            if(f[v] != -1) continue;
            f[v] = 1 + f[u];
            q.push(v);
        }
    }
    return f[1];
}


int path() {
    queue<int>q;
    q.push(1);
    g[1] = 0;

    bool vis[LIM+100] = {0};

    while(!q.empty()) {
//        cout << "OUT " << q.front() << endl;
        int cur = g[ q.front() ];
        int nxt, nxtCol = INT_MAX;
        queue<int>temp;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(vis[u]) continue;
            vis[u] = 1;
//            cout << "CHK " << u << endl; getchar();
            for(int i=0; i<graph[u].size(); i++) {
                int v = graph[u][i].ss , c = graph[u][i].ff;
                if( g[u]+1+f[v] != f[1]) continue;

                g[v] = g[u]+1;
                if(c < nxtCol) {
                    while(!temp.empty()) temp.pop();
                    nxtCol = c;
                }
                if(c == nxtCol) {

                    temp.push(v);
                }
            }
        }
        color[cur+1] = nxtCol;
//        cout << "COL " << nxtCol << endl;
        while(!temp.empty()) {
//            cout << "PUSHING " << temp.front() << endl;
            q.push(temp.front());
            temp.pop();
        }
    }
    for(int i=1; i<=f[1]; i++) {
        if(i > 1) printf(" ");
        printf("%d", color[i]);
    }
    return printf("\n");
}

int main() {
//    freopen("1599i.txt", "r", stdin);
//    freopen("1599o.txt", "w", stdout);
    while( scanf("%d %d", &n,&m) != EOF) {
        memset(graph, NULL, sizeof graph);
        for(int i=0; i<m; i++) {
            int u,v,c;
            scanf("%d %d %d", &u,&v,&c);
            graph[u].pb(mpr(c,v));
            graph[v].pb(mpr(c,u));
        }
        for(int i=1; i<=n; i++) sort(graph[i].begin(), graph[i].end());
//cout << "BUG" << endl;
        memset(f, -1, sizeof f);
        printf("%d\n", bfs(n));

//        for(int i=1; i<=n; i++) cout << i << ' ' << f[i] << endl; getchar();

        memset(color, 127, sizeof color);
        memset(g, -1, sizeof g);
        path();
    }
    return 0;

}
