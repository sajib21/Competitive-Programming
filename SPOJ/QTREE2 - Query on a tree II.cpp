#include<bits/stdc++.h>
#define MX 100100
#define ll long long int

using namespace std;

int n;
vector<int>graph[MX], cost[MX];
ll dis[MX];
int lev[MX];
int sparse[MX][50];

void bfs(int root) {

    memset(lev, -1, sizeof(lev));
    memset(dis, 0, sizeof(dis));
    lev[root] = 0;

    queue<int>q;
    q.push(root);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            if(lev[v] == -1) {
                lev[v] = lev[u] + 1;
                dis[v] = dis[u] + cost[u][i];
                q.push(v);
                sparse[v][0] = u;
            }
        }
    }
}

void genSparseTable() {

    memset(sparse, -1, sizeof(sparse));
    bfs(1);
    int lim = log2(n);
//    for(int par=1; (1 << par) <= n; par++ ) {
    for(int par=1; (1 << par) <= n; par++ ) {
        for(int u=1; u<=n; u++) {
            if(sparse[u][par-1] != -1) sparse[u][par] = sparse[ sparse[u][par-1] ][par-1];
        }
    }
}

int getKthParent(int u, int k) {

    int parentLevel = lev[u] - k;
    int lim = log2(lev[u]);
    while(lim >= 0) {
        if(lev[u] - (1 << lim) >= parentLevel)
            u = sparse[u][lim];
            lim--;
//        up /= 2;
//        cout << "ekhn u " << u << endl;
    }
//    cout << "return " << u << endl;
    return u;
}

int getLCA(int u, int v) {

    if(lev[u] < lev[v]) swap(u,v);

    int lim = log2(lev[u]) + 10;
    while(lim >= 0) {
        int sp = sparse[u][lim];
        if(lev[u] - (1 << lim) >= lev[v]) {
            u = sp;
        }
        lim--;
    }
    if(u == v) return u;

    int up = log2(lev[u]) + 10;
    while(up >= 0) {
        if(sparse[u][up] != sparse[v][up]) {
            u = sparse[u][up];
            v = sparse[v][up];
        }
        up--;
    }
    return sparse[u][0];
}



int main() {

    int t;
    cin >> t;
    while(t--) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) graph[i].clear() , cost[i].clear();


        for(int i=1; i<n; i++) {
            int u,v,c;
            scanf("%d %d %d", &u,&v,&c);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }
        genSparseTable();

        string cmd;
        while(cin >> cmd && cmd != "DONE") {
            int u,v,c;
            if(cmd == "DIST") {
                scanf("%d %d", &u,&v);
                int lca = getLCA(u,v);
                int totalDis = dis[u] + dis[v] - 2*dis[lca];
                printf("%d\n", totalDis);
            }
            else {
                scanf("%d %d %d", &u, &v, &c);
                int lca = getLCA(u,v), kpar;
                if(lev[u]-lev[lca]+1 >= c) kpar = getKthParent(u, c-1);
                else kpar = getKthParent(v, lev[u]+lev[v] - 2*lev[lca] - c + 1);
                printf("%d\n", kpar);
            }
        }
        printf("\n");
    }

    return 0;

}
