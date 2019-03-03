/// MAX FLOW = MIN CUT

/// THE PROBLEM I WAS STUCK WAS IN CONSTRUCTING THE GRAPH.
/// PREVIOUSLY, I SOLVED MAX FLOW IN DIRECTED GRAPH, NODE WEIGHTED GRAPH, BUT NOT BOTH COMBINED.
/// THIS PROBLEM IS COMBINED AND WE CANNOT GENERALIZE THE GRAPH AS A TREE LIKE STRUCTURE.
/// SO WE CANNOT SAY THAT "THIS EDGE" GOES FROM THIS NODE TO THAT NODE.
/// SO I MODIFIED THE GRAPH TO A DIRECTED ONE BY ADDING EDGES IN BOTH DIRECTION AND AN OUTGOING EDGE FROM THE 2ND PART OF THE NODE AS THE NODES ALSO CAN HAVE
/// EDGES AND VICE VERSA.

/// TRIED PFS BUT GOT 1.7S RUNTIME, BUT .04S WITH NORMAL BFS. BFS WORKED EFFICIENTLY HERE.

/// ANALOGY OF BFS IS IT'S COMPLEXITY REDUCES BECAUSE WE NEVER ITERATE THROUGH ALL THE NODES ALWAYS, WE NOT EVEN CHECK IF ELSE. WE ONLY ITERATE THOUGH THE LISTED ADJACENT NODES
/// ONLY. IF WE IMPLEMENT A LIST VERSION OF THE GRAPH ALONGSIDE THE MATRIX FORM, THEM THE ACTUAL COMPLEXITY OF BFS HOLDS AND TIME REDUCED TO .02S. HURRAY!!!

/// NODE CAPACITY

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
vii vecGraph[110];

int bfs(int root) {
    int cap = -1;
    int keys[110], par[110], vis[110];
    memset(keys, -1, sizeof(keys));
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    keys[root] = IM;
    queue<int>q;
    q.push(root);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;

        if(u == 2*m) {
            cap = keys[u];
            break;
        }

        int sz = vecGraph[u].size();
        for(int i=0; i<sz; i++) {
            int v = vecGraph[u][i];
            if(graph[u][v] > 0 && v != par[u] && !vis[v]) {
                if(keys[v] == -1 || min(keys[u],graph[u][v]) < keys[v]) {
                    keys[v] = min(keys[u],graph[u][v]);
                    par[v] = u;
                    q.push(v);
                }
            }
        }
    }

    if(cap == -1) return cap;

    int v = 2*m;
    int u = 2*m-1;
    while(u != -1) {
        graph[u][v] -= cap;
        graph[v][u] += cap;
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
        graph[1][2] = graph[2][1] = graph[2*m-1][2*m] = graph[2*m][2*m-1] = IM;
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

        for(int i=1; i<=2*m; i++) vecGraph[i].clear();
        for(int i=1; i<=2*m; i++) {
            for(int j=1; j<=2*m; j++) {
                if(graph[i][j] > 0) vecGraph[i].pb(j) , vecGraph[j].pb(i);
            }
        }

        printf("Case %d: %d\n", t, flow());
    }
    return 0;
}
