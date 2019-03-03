/// tree merging keeping diameter minimum
#include<bits/stdc++.h>
#define LIM 300005
#define vi vector<int>
#define pb push_back

using namespace std;

int n,m,q, a,b, sz[LIM], link[LIM], ans[LIM];
vi g[LIM];

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
    ans[a] = max( max(ans[a],ans[b]), (ans[a]+1)/2 + (ans[b]+1)/2 + 1);
    link[b] = a;
}

bool vis[LIM], vis2[LIM];
int keys[LIM], keys2[LIM];

void init(int root) {
    queue<int>q;
    q.push(root);
    vis[root] = 1;

    int u = 0;
    while(!q.empty()) {
        u = q.front();
        q.pop();

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if(vis[v]) continue;
            vis[v] = 1;
            keys[v] = keys[u]+1;
            q.push(v);
        }
    }

    q.push(u);
    vis2[u] = 1;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if(vis2[v]) continue;
            vis2[v] = 1;
            keys2[v] = keys2[u] + 1;
            q.push(v);
        }
    }
    int l = findLink(u);
    ans[l] = keys2[u];
}

int query(int x) {
    return ans[ findLink(x) ];
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i=1; i<=n; i++) sz[i] = 1, link[i] = i;

    for(int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
        unite(u,v);
    }

    for(int i=1; i<=n; i++) if(!vis[i]) init(i);

    while(q--) {
        int a,b,c;
        scanf("%d", &a);
        if(a == 1) {
            scanf("%d", &b);
            printf("%d\n", query(b));
        }
        else if(a == 2) {
            scanf("%d %d", &b,&c);
            unite(b,c);
        }

    }
}
