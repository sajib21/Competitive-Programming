#include<bits/stdc++.h>
#define IM INT_MAX/100

using namespace std;

int n,m, graph[110][110];

struct info {

    int u, k;
    info(int uu, int kk) {
        u = uu;
        k = kk;
    }
    bool operator < (const info &b) const {
        return k > b.k;
    }
};

int pfs(int root) {

    int key[110], par[110], cap = -1;
    memset(par, -1, sizeof(par));
    for(int i=1; i<=n; i++) key[i] = IM;
    key[root] = 0;
    priority_queue<info>pq;
    pq.push(info(root, key[root]));

    while(!pq.empty()) {

        info nd = pq.top(); pq.pop();
        int u = nd.u , ky = nd.k;

//        cout << u << ' ' << ky << endl; getchar();

        if(u == n) {
            cap = ky;
            break;
        }

        for(int v=1; v<=n; v++) {
            if(u != v && graph[u][v] != 0 && ky+graph[u][v] < key[v]) {
                key[v] = ky+graph[u][v];
                par[v] = u;
                pq.push(info(v, key[v]));
            }
        }
    }
    if(cap == -1) return cap;

    int u,v;
    v = n;
    u = par[v];

    int ans = 0 , temp = -1;
    while(u != -1) {
        graph[v][u] = -graph[u][v];
        graph[u][v] = 0;
        u = par[u];
        v = par[v];
    }
    return cap;
}

int flow() {

    int ans = 0, cnt = 0, temp = -1;
    while(cnt < 2) {
        temp = pfs(1);
        if(temp == -1) break;
        ans += temp;
        cnt++;
    }
    if(cnt < 2) return -1;
    else return ans;
}

int main() {

    while(scanf("%d", &n) && n) {

        memset(graph, 0, sizeof(graph));
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u][v] = graph[v][u] = w;
        }
        int ans = flow();
        if(ans == -1) printf("Back to jail\n");
        else printf("%d\n", ans);
    }
    return 0;
}
