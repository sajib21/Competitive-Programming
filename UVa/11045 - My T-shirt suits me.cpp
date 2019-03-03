#include<bits/stdc++.h>
#define ll long long int
#define IM INT_MAX
#define pb push_back


using namespace std;

char ch[][5] = {"", "XXL", "XL", "L", "M", "S", "XS"};

int n,m, graph[40][40];
vector<int>gv[40];

void include(int t, char str[]) {
    for(int i=1; i<=6; i++) {
        if(!strcmp(str, ch[i])) {
            graph[t][m+i] = 1;
            break;
        }
    }
}

struct info {

    int u;
    int k;
    info(int uu, int kk) { u = uu; k = kk; }
    bool operator < (const info &b) const {
        return k < b.k;
    }
};

int pfs(int root) {

    int key[40], par[40], cap = -1;
    memset(key, 0, sizeof(key));
    memset(par, -1, sizeof(par));
    key[root] = IM;

    priority_queue<info>pq;
    pq.push(info(root, key[root]));

    while(!pq.empty()) {
        info nd = pq.top(); pq.pop();
        int u = nd.u; int ky = nd.k;

        if(u == m+7) {
            cap = ky;
            break;
        }

        int sz = gv[u].size();
        for(int i=0; i<sz; i++) {
            int v = gv[u][i];
            if(graph[u][v] > 0 && min(ky, graph[u][v]) > key[v]) {
                par[v] = u;
                key[v] = min(ky, graph[u][v]);
                pq.push(info(v, key[v]));
            }
        }
    }
    if(cap == -1) return cap;

    int u,v;
    v = m+7;
    u =  par[v];

    while(u != -1) {
        graph[u][v]--;
        graph[v][u]++;
        u = par[u];
        v = par[v];
    }
    return cap;
}

int flow() {

    int ans = 0, temp = -1;
    while(true) {
        temp = pfs(0);
        if(temp == -1) return ans;
        ans++;
    }
}

int main() {

    int T;
    scanf("%d", &T);
    while(T--) {

        memset(graph, 0, sizeof(graph));
        scanf("%d %d", &n,&m);
        for(int i=1; i<=m; i++) {
            char pref1[5] , pref2[5];
            scanf("%s %s", pref1, pref2);
            include(i, pref1);
            include(i, pref2);
        }
        for(int i=1; i<=m; i++) graph[0][i] = 1;
        for(int i=1; i<=6; i++) graph[m+i][m+7] = n/6;

        for(int i=0; i<=m+8; i++) gv[i].clear();
        for(int i=0; i<=m+7; i++) {
            for(int j=0; j<=m+7; j++) {
                if(i != j && graph[i][j]) {
                    gv[i].pb(j);
                    gv[j].pb(i);
                }
            }
        }

        if(flow() == m) printf("YES\n");
        else printf("NO\n");
    }
    return 0;

}
