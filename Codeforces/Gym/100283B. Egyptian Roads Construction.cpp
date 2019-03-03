#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

struct info {
    int u,v,w;
    info() {}
    info(int uu, int vv, int ww) {
        u = uu; v = vv; w = ww;
    }
    bool operator < (const info &b) const {
        return w < b.w;
    }
};

int n,m, ed[LIM], a,b, sz[LIM], link[LIM];

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
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        for(int i=1; i<=n; i++) link[i] = i, sz[i] = 1;
        for(int i=0; i<m; i++) scanf("%d %d %d", &ed[i].u, &ed[i].v, &ed[i].w);

    }

}
