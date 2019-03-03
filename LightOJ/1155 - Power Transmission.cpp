///MAX FLOW : NODE CAPACITY

#include<bits/stdc++.h>
#define IM INT_MAX - 10000
#define pb push_back
#define ll long long int

using namespace std;

int n,m, graph[210][210];
int B,D, vis[210];
vector<int>gv[210];

int dfs(int u, int mn) {
//    cout << u << ' ' << mn << endl;
    vis[u] = 1;
    if(u == 2*n+1) return mn;

    int sz = gv[u].size();
    for(int i=0; i<sz; i++) {
        int v = gv[u][i];
        if(!vis[v] && graph[u][v] > 0) {
            int temp = dfs(v, min(mn, graph[u][v] ) );
            if(temp != -1) {
                graph[u][v] -= temp;
                graph[v][u] += temp;
                return temp;
            }
        }
    }
//    for(int v=0; v<=2*n+1; v++) {
//        if(!vis[v] && graph[u][v] > 0) {
//            int temp = dfs(v, min(mn, graph[u][v] ) );
//            if(temp != -1) {
//                graph[u][v] -= temp;
//                graph[v][u] += temp;
//                return temp;
//            }
//        }
//    }
    return -1;
}

struct info {

    int u;
    ll k;

    info(int uu, int kk) {
        u = uu; k = kk;
    }

    bool operator < (const info &b) const {
        return k < b.k;
    }
};

int pfs(int root) {

    int key[210] , par[210];
    memset(par, -1, sizeof(par));
    memset(key, 0, sizeof(key));
//    for(int i=0; i<=2*n+1; i++) key[i] = IM;
    key[root] = IM;
    priority_queue<info>pq;
    pq.push( info(root, key[root]) );

    int cap = -1;

    while(!pq.empty()) {
        info nd = pq.top(); pq.pop();
        int u = nd.u , ky = nd.k;

//        cout << u << ' ' << ky << endl;
//        getchar();

        if(u == 2*n+1) {
            cap = ky;
            break;
        }

        int sz = gv[u].size();
        for(int i=0; i<sz; i++) {
            int v = gv[u][i];
            if(graph[u][v] > 0 && min(ky, graph[u][v]) > key[v] ) {
                key[v] = min(ky, graph[u][v]);
                par[v] = u;
                pq.push(info(v, key[v]));
            }
        }
    }
    if(cap == -1) return cap;

    int u,v;
    v = 2*n+1; u = par[v];

    while(u != -1) {
        graph[u][v] -= cap;
        graph[v][u] += cap;
        u = par[u];
        v = par[v];
    }
    return cap;
}

int flow() {

    int ans = 0, temp = 0;
    while(true) {
//        memset(vis, 0, sizeof(vis));
        temp = pfs(0);
        if(temp <= 0) return ans;
        ans += temp;
    }
    return ans;
}


int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(graph, 0, sizeof(graph));
        for(int i=0; i<=205; i++) gv[i].clear();

        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            int w;
            scanf("%d", &w);
            graph[2*i-1][2*i] = w;
//            graph[2*i][2*i-1] = w;
        }
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[2*u][2*v-1] = w;
        }
        scanf("%d %d", &B,&D);
        for(int i=0; i<B; i++) {
            int v;
            scanf("%d", &v);
            graph[0][2*v-1] = IM;
        }
        for(int i=0; i<D; i++) {
            int u;
            scanf("%d", &u);
            graph[2*u][2*n+1] = IM;
        }

        for(int i=0; i<=2*n+1; i++) {
            for(int j=0; j<=2*n+1; j++) {
                if(i != j && graph[i][j]) {
                    gv[i].pb(j);
                    gv[j].pb(i);
                }
            }
        }

        printf("Case %d: %d\n",t, flow());
    }
}
