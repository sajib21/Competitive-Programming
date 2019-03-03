/// MAX FLOW = MIN CUT
/// THE PROBLEM I WAS STUCK WAS IN CONSTRUCTING THE GRAPH.
/// PREVIOUSLY, I SOLVED MAX FLOW IN DIRECTED GRAPH, NODE WEIGHTED GRAPH, BUT NOT BOTH COMBINED.
/// THIS PROBLEM IS COMBINED AND WE CANNOT GENERALIZE THE GRAPH AS A TREE LIKE STRUCTURE.
/// SO WE CANNOT SAY THAT "THIS EDGE" GOES FROM THIS NODE TO THAT NODE.
/// SO I MODIFIED THE GRAPH TO A DIRECTED ONE BY ADDING EDGES IN BOTH DIRECTION AND AN OUTGOING EDGE FROM THE 2ND PART OF THE NODE AS THE NODES ALSO CAN HAVE
/// EDGES AND VICE VERSA.

#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define IM 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

int m,w;
int graph[110][110];

struct info {
    int u, key;
    info() {}
    info(int uu, int kk) {
        u = uu; key = kk;
    }
    bool operator < (const info &b) const {
        return key > b.key;
    }
};

int bfs(int root) {
    int cap = -1;
    int keys[110], par[110], vis[110];
    memset(keys, -1, sizeof(keys));
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    keys[root] = IM;
    priority_queue<info>pq;
    pq.push(info(root, keys[root]));
//    queue<int>q;
//    q.push(root);

    while(!pq.empty()) {
        info U = pq.top();
        int u = U.u , k = U.key;
        pq.pop();

        vis[u] = 1;

        if(u == 2*m) {
            cap = k;
            break;
        }

        for(int v=1; v<=2*m; v++) {
            if(graph[u][v] > 0 && v != par[u] && !vis[v]) {
                if(keys[v] == -1 || min(keys[u],graph[u][v]) < keys[v]) {
                    keys[v] = min(keys[u],graph[u][v]);
                    par[v] = u;
                    pq.push(info(v, keys[v]));
                }
            }
        }
    }

    if(cap == -1) return cap;

    int v = 2*m;
    int u = 2*m-1;
    while(u != -1) {
//        cout << u << ' ' << par[u] << ' ' << v << ' ' << par[v] << endl;
//        getchar();
        graph[u][v] -= cap;
        graph[v][u] += cap;
//        if(u == 1) break;
        u = par[u];
        v = par[v];

        if(v == 1) break;
    }
    return cap;
}

int flow() {
    int ans = 0;
    while(true) {
        int temp = bfs(1);
        if(temp <= 0) break;
        ans += temp;
    }
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(graph, 0, sizeof(graph));
        scanf("%d %d", &m,&w);
        graph[1][2] = graph[2*m-1][2*m] = IM;
        for(int i=2; i<m; i++) {
            int c;
            scanf("%d", &c);
            graph[2*i-1][2*i] = c;
        }
        for(int i=0; i<w; i++) {
            int u,v,c;
            scanf("%d %d %d", &u,&v,&c);
            graph[2*u][2*v-1] = c;
            graph[2*v][2*u-1] = c;
        }
//        cout << "BUG" << endl;
        printf("Case %d: %d\n", t, flow());
    }
    return 0;
}
