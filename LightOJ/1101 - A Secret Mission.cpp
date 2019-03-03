#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct edge {
    int u,v,cst;
};

bool cmp (edge a, edge b) {
    return a.cst < b.cst;
}

int n,m, q;
edge e[100005];
int par[50005];
vector<int>graph[50005], cost[50005];
int lev[50005];
int sparse[50005][20], maxCost[50005][20];

int parentCheck(int u) {
    if(par[u] == u) return u;
    return par[u] = parentCheck(par[u]);
}

void makeMST() {

    for(int i=1; i<=n; i++) graph[i].clear() , cost[i].clear();

    for(int i=1; i<=n; i++) par[i] = i;

    for(int i=0; i<m; i++) {
        int u = e[i].u, v = e[i].v, c = e[i].cst;
        if(parentCheck(u) != parentCheck(v)) {
//            cout << "GOT EDGE " << u << ' ' << v << endl;
            par[par[u]] = parentCheck(v);
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(c);
            cost[v].pb(c);
        }
    }

    {
//        cout << "GRAPH" << endl;
//        for(int i=1; i<=n; i++) {
//            cout << i << " : ";
//            for(int j=0; j<graph[i].size(); j++) {
//                cout << graph[i][j] << ' ';
//            }
//            cout << endl;
//        }
//        cout << "COSTS" << endl;
//        for(int i=1; i<=n; i++) {
//            cout << i << " : ";
//            for(int j=0; j<cost[i].size(); j++) {
//                cout << cost[i][j] << ' ';
//            }
//            cout << endl;
//        }
    }
}

void bfs(int root) {

    memset(lev, -1, sizeof(lev));
    lev[root] = 0;

    queue<int>q;
    q.push(root);

//    cout << "INSIDE BFS" << endl;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            if(lev[v] == -1) {
                lev[v] = lev[u] + 1;
                sparse[v][0] = u;
                maxCost[v][0] = cost[u][i];

                q.push(v);
            }
        }
//        cout << u << ' ' << lev[u] << ' ' << maxCost[u][0] << endl;
    }

//    cout << "BFS" << endl;
//    for(int i=1; i<=n; i++) cout << maxCost[i][0] << ' '; cout << endl;
}

void makeSparse() {

    memset(sparse, -1, sizeof(sparse));
    memset(maxCost, 0, sizeof(maxCost));
    bfs(1);

    int lim = log2(n) + 1;
    for(int par = 1; par <=lim; par++) { ///EI PART E LOG NILE PROBLEM HOY NA
        for(int u=1; u<=n; u++) {
            if(sparse[u][par-1] != -1) {
                maxCost[u][par] = max(maxCost[u][par-1], maxCost[ sparse[u][par-1] ][par-1]);
                sparse[u][par] = sparse[ sparse[u][par-1] ][par-1];
            }
        }
    }
    {
//    cout << "SPARSE PARENT" << endl;
//    for(int i=1; i<=n; i++) {
//        cout << i << " : ";
//        for(int p=0; p<=lim; p++) {
//            cout << ' ' << sparse[i][p];
//        }
//        cout << endl;
//    }
//    cout << "SPARSE MAXCOST" << endl;
//    for(int i=1; i<=n; i++) {
//        cout << i << " : ";
//        for(int p=0; p<=lim; p++) {
//            cout << ' ' << maxCost[i][p];
//        }
//        cout << endl;
//    }
    }
}

int getMaxCost(int u, int v) {

    if(lev[u] < lev[v]) swap(u,v);

    int mc = 0;

    int up = log2(lev[u]) ;
    while(up >= 0) {
        int sp = sparse[u][up];
        if( lev[u] - (1 << up) >= lev[v]) {
            mc = max(mc, maxCost[u][up]);
            u = sp;
        }
        up--;
    }

    up = log2(lev[u]) ;
    while(up >= 0) {
        if(sparse[u][up] != sparse[v][up]) {
            mc = max(mc, max( maxCost[u][up] , maxCost[v][up] ) );
            u = sparse[u][up];
            v = sparse[v][up];
        }
        up--;
    }

    if (u == v) return mc;
    return max(mc, max(maxCost[u][0], maxCost[v][0] ) );
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        scanf("%d %d", &n,&m);
        for(int i=0; i<m; i++) {
            scanf("%d %d %d", &e[i].u , &e[i].v, &e[i].cst);
        }
        sort(e, e+m, cmp);
//        for(int i=0; i<m; i++) cout << e[i].cst << ' '; cout << endl;

        makeMST();
        makeSparse();

        scanf("%d", &q);

        printf("Case %d:\n", t);
        while(q--) {
            int u,v;
            scanf("%d %d", &u,&v);
            printf("%d\n", getMaxCost(u,v));
        }
    }

    return 0;
}
