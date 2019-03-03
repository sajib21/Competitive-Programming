#include<bits/stdc++.h>
#define LIM 10000

using namespace std;

struct info {
    int u,v,x;
    info() {}
    info(int uu, int vv, int xx) {
        u = uu; v = vv; x = xx;
    }
    bool operator < (const info &b) const {
        return x < b.x;
    }
};

int n,m, x, sz[1010], link[1010];
info app[LIM];
bool ase[1010];

int findLink(int x) {
    while(x != link[x]) x = link[x];
    return x;
}
bool isSameLink(int a, int b) {
    return findLink(a) == findLink(b);
}
void unite(int a, int b) {
    a = findLink(a);
    b = findLink(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) sz[i] = 1, link[i] = i;
    for(int i=0; i<n; i++) scanf("%d", &x);
    scanf("%d", &m);

    for(int i=0; i<m; i++) scanf("%d %d %d", &app[i].u, &app[i].v, &app[i].x);
    sort(app, app+m);

    int ans = 0;

    for(int i=0; i<m; i++) {
        int u = app[i].u, v = app[i].v, w = app[i].x;
        if(ase[v] || isSameLink(u,v)) continue;
        ans += w;
        unite(u,v);
        ase[v] = 1;
    }

    for(int i=1; i<n; i++) {
        if(!isSameLink(i, i+1)) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}
