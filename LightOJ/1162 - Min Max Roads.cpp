#include<bits/stdc++.h>
#define LIM 100000
#define pb push_back
using namespace std;

int n,m, q;
vector<int>graph[LIM+10], cost[LIM+10];
int lev[LIM+10];
int sparse[LIM+10][20], maxCost[LIM+10][20], minCost[LIM+10][20];

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
                minCost[v][0] = cost[u][i];

                q.push(v);
            }
        }
    }
}

void makeSparse() {

    memset(sparse, -1, sizeof(sparse));
    memset(maxCost, 0, sizeof(maxCost));
    memset(minCost, 0, sizeof(minCost));
    bfs(1);

    int lim = log2(n) + 1;
    for(int par = 1; par <=lim; par++) { ///EI PART E LOG NILE PROBLEM HOY NA
        for(int u=1; u<=n; u++) {
            if(sparse[u][par-1] != -1) {
                minCost[u][par] = min(minCost[u][par-1], minCost[ sparse[u][par-1] ][par-1]);
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

pair<int,int> getMaxCost(int u, int v) {

    if(lev[u] < lev[v]) swap(u,v);

    int mc = 0, nc = INT_MAX;

    int up = log2(lev[u]) ;
    int shft = (1 << up) ;
    while(up >= 0) {
        int sp = sparse[u][up]; ///EKHANE LEFT SHIFT MINUS ER JAGAY LOG NIYA LOOP CHALAILE WA DEY!!
        if( lev[u] - shft >= lev[v]) {
            mc = max(mc, maxCost[u][up]);
            nc = min(nc, minCost[u][up]);
            u = sp;
        }
        up--;
        shft /= 2;
    }

    up = log2(lev[u]) ;
    while(up >= 0) {
        if(sparse[u][up] != sparse[v][up]) {
            mc = max(mc, max( maxCost[u][up] , maxCost[v][up] ) );
            nc = min(nc, min( minCost[u][up] , minCost[v][up] ) );
            u = sparse[u][up];
            v = sparse[v][up];
        }
        up--;
    }

    if (u == v) return make_pair(mc,nc);
    return make_pair( max(mc, max(maxCost[u][0], maxCost[v][0] ) ) ,
                      min(nc, min(minCost[u][0], minCost[v][0] ) ));
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        scanf("%d", &n);
        for(int i=0; i<=n; i++) graph[i].clear() , cost[i].clear();

        for(int i=1; i<n; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }

        makeSparse();

        scanf("%d", &q);

        printf("Case %d:\n", t);
        while(q--) {
            int u,v;
            scanf("%d %d", &u,&v);
            pair<int,int> res;
            res = getMaxCost(u,v);
            printf("%d %d\n", res.second, res.first);
        }
    }

    return 0;
}
