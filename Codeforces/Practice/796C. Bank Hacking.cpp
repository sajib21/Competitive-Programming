#include<bits/stdc++.h>
#define LIM 300005
#define vi vector<int>
#define pb(x) push_back(x)
#define segVar int lft=2*node, rgt = 2*node+1, md = (st+ed)/2

using namespace std;

int n, a[LIM];
vi g[LIM];
int segTree[4*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = a[st];
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = max(segTree[lft], segTree[rgt]);
}

void update(int node, int st, int ed, int p, int v) {
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        segTree[node] += v;
        return;
    }
    segVar;
    update(lft, st,md, p,v); update(rgt, md+1,ed, p,v);
    segTree[node] = max(segTree[lft], segTree[rgt]);
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        a[i] += 2;
    }

    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    init(1, 1,n);

    int ans = INT_MAX;

    for(int u=1; u<=n; u++) {
        update(1, 1,n, u, -2);
        for(int v : g[u]) update(1, 1,n, v, -1);

        ans = min(ans, segTree[1]);

        update(1, 1,n, u, +2);
        for(int v : g[u]) update(1, 1,n, v, +1);
    }

    cout << ans << endl;
}
