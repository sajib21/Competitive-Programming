#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 100005

using namespace std;

int n,q;
vi g[LIM], cg[LIM];
int sub[LIM];
int root, par[LIM];
bool centroid[LIM];

void dfs(int u, int p=0) {
    sub[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(p == v || centroid[v]) continue;
        dfs(v,u);
        sub[u] += sub[v];
    }
}

int getCentroid(int u, int p=0, int pc=0) {
    bool ok = true;
    int up = 1, nxt;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i], sz;
        if(centroid[v]) continue;

        if(v == p) sz = pc;
        else sz = sub[v];

        if(sz > sub[root]/2) ok = false, nxt = v;
        else up += sz;
    }
    if(ok) return u;
    else return getCentroid(nxt, u, up);
}

void decom() {
    root = 1;
    dfs(root);
    root = getCentroid(root);

    queue<int>q;
    q.push(root);
    centroid[root] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if(centroid[v]) continue;

            root = v;
            dfs(v);
            int cen = getCentroid(v);
            centroid[cen] = true;

            cg[u].pb(cen);
            cg[cen].pb(u);
            par[cen] = u;
            q.push(cen);
        }
    }
}

void printCenTree() {
    cout << "CENTROID TREE " << endl;
    for(int i=1; i<=n; i++) {
        cout << i << " : ";
        for(int j=0; j<cg[i].size(); j++) cout << cg[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    scanf("%d %d", &n,&q);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    decom();
    printCenTree();

}
