#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int

using namespace std;

struct info {
    int u,v,w;
    info() {}
    info(int uu, int vv, int ww) {
        u = uu; v = vv; w = ww;
    }
    bool operator < (const info &b) const {
        return w > b.w;
    }
};

int n,m, a[LIM], sz[LIM], link[LIM];
info ed[LIM];

int findLink(int x) {
    while(x != link[x]) x = link[x];
    return x;
}
bool isSameLink(int a, int b) {
    return findLink(a) == findLink(b);
}
ll unite(int a, int b, int w) {
    ll ans = 0;
    a = findLink(a);
    b = findLink(b);
    if(a == b) return 0;
    ans = 1LL*sz[a]*sz[b]*2 * w;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
    return ans;
}


int main() {
    scanf("%d %d", &n,&m);
    for(int i=1; i<=n; i++) link[i] = i, sz[i] = 1;
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) {
        int u,v, w;
        scanf("%d %d", &u,&v);
        w = min(a[u], a[v]);
        ed[i] = info(u,v, w);
    }
    sort(ed, ed+m);

    ll ans = 0;
    for(int i=0; i<m; i++) {
        int u = ed[i].u, v = ed[i].v, w = ed[i].w;
        if(!isSameLink(u, v)) {
            ans += unite(u,v,w);
        }
    }
    printf("%.6f\n", 1.0*ans/(1LL*n*(n-1)));
}
