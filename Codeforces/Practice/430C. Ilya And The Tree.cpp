#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 200005

using namespace std;

int n, a[LIM];
int ans[LIM], vis[LIM];
vi g[LIM];

void dfs(int u, int all, set<int>cur) {
    ans[u] = max(all, *cur.rbegin());
    vis[u] = 1;

    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        set<int>nxt;
        for(auto it : cur) nxt.insert(__gcd(it, a[v])); ///ager 1ta bade gcd
        nxt.insert(all); ///v bade gcd
        dfs(v, __gcd(all, a[v]), nxt);
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    g[0].pb(1);

    set<int>g;
    g.insert(0);
    dfs(0, 0, g);

    for(int i=1; i<=n; i++) {
        printf("%d ", ans[i]);
    }
    cout << endl;
}
