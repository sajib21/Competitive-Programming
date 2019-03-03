#include<bits/stdc++.h>
#define LIM 200005
#define vii vector<int>
#define pb push_back
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

using namespace std;

int n,m, a[LIM];
vii graph[LIM];
int t, d[LIM], s[LIM], h[LIM], segTree[4*LIM];

void dfs(int u, int cur) {
    d[u] = ++t; h[u] = cur
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if(d[v]) continue;
        dfs(v, cur+1);
    }
    s[u] = t;
}

void update(int node, int st, int ed, int p, int val) {
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        segTree[node] += val;
        return;
    }
    segVar;
    update(lft, st,md, p, val); update(rgt, md+1,ed, p, val);
}

int query(int node, int st, int ed, int p) {
    if(st == p && ed == p) return segTree[node];
    segVar;
    if(p <= md) return query()
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 1);
}
