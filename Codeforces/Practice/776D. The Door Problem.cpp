#include<bits/stdc++.h>
#define LIM 100005
#define pb push_back

using namespace std;

int n, m, a[LIM];
vector<int>con[LIM];
vector<int> g[2*LIM], r[2*LIM];
int vis[2*LIM], com[2*LIM];
stack<int>stk;
int bar(int x) { return (x+m)%(2*m); }

void dfs1(int u) {
    vis[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        dfs1(v);
    }
    stk.push(u);
}

void dfs2(int u, int c) {
    vis[u] = 1;
    com[u] = c;
    for(int i=0; i<r[u].size(); i++) {
        int v = r[u][i];
        if(vis[v]) continue;
        dfs2(v, c);
    }
}

bool sat() {
    memset(vis, 0, sizeof vis);
    for(int u=0; u<2*m; u++) if(!vis[u]) dfs1(u);
    memset(vis, 0, sizeof vis);
    memset(com, 0, sizeof com);
    int c = 0;
    while(!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if(vis[u]) continue;
        c++;
        dfs2(u,c);
    }
    for(int u=0; u<m; u++) if(com[u] == com[u+m]) return false;
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) {
        int c,x;
        scanf("%d", &c);
        while(c--) {
            scanf("%d", &x);
            con[x].pb(i);
        }
    }
    for(int i=1; i<=n; i++) {
        int u,ub, v,vb;
        u = con[i][0]; ub = u+m;
        v = con[i][1]; vb = v+m;

        if(a[i]) { ///XNOR
            g[u].pb(v);     r[v].pb(u);
            g[ub].pb(vb);   r[vb].pb(ub);
            g[vb].pb(ub);   r[ub].pb(vb);
            g[v].pb(u);     r[u].pb(v);
        }
        else { ///XOR
            g[ub].pb(v);    r[v].pb(ub);
            g[u].pb(vb);    r[vb].pb(u);
            g[vb].pb(u);    r[u].pb(vb);
            g[v].pb(ub);    r[ub].pb(v);
        }
    }

//    for(int i=1; i<=n; i++) cout << i << ' ' << a[i] << ' ' << con[i][0] << ' ' << con[i][1] << endl;
//    for(int u=0; u<2*m; u++) {
//        cout << u << " : ";
//        for(int i=0; i<g[u].size(); i++) cout << g[u][i] << ' ' ;
//        cout << endl;
//    }



    if(sat()) printf("YES\n");
    else printf("NO\n");

    return 0;
}
