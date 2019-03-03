#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define LIM 100005

using namespace std;

int n,m,d, u,v,x, a[LIM];
vii g[LIM];
int ase[LIM], vis[LIM], dis[LIM], chi[LIM], dis2[LIM], chi2[LIM];

bool dfs(int u) {
    vis[u] = 1;
    if(a[u]) {
        ase[u] = 1;
        dis[u] = 0;
        chi[u] = u;
    }
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
//        if(a[v]) ase[u] = 1;
        if(!dfs(v)) continue;
        ase[u] = 1;
        if(dis[v]+1 > dis[u]) {
            dis2[u] = dis[u]; chi2[u] = chi[u];
            dis[u] = dis[v]+1; chi[u] = v;
        }
        else if(dis[v]+1 > dis2[u]) {
            dis2[u] = dis[v]+1;
            chi2[u] = v;
        }
    }
//    cout <<
    return ase[u];
}

void dfs2(int u) {
    vis[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        if(chi[u] != v) {
            dis2[v] = dis[v]; chi2[v] = chi[v];
            dis[v] = dis[u]+1; chi[v] = u;
        }
        if(chi2[u] && chi2[u] != v) {
//            if(!chi2[u]) continue;
            if(dis2[u]+1 > dis[v]) {
                dis2[v] = dis[v]; chi2[v] = chi[v];
                dis[v] = dis2[u]+1; chi[v] = u;
            }
            else if(dis2[u]+1 > dis2[v]) {
//                dis2[v] = dis[v]; chi2[v] = chi[v];
                dis2[v] = dis2[u]+1; chi2[v] = u;
            }
        }
//        cout << "IN " << v << ' ' << dis[v] << ' ' << chi[v] << ' ' << dis2[v] << ' ' << chi2[v] << endl; getchar();
        dfs2(v);
    }
//    int i = u; cout << "OUT " << i << ' ' << dis[i] << ' ' << chi[i] << ' ' << dis2[i] << ' ' << chi2[i] << endl; getchar();
}

int main() {
    scanf("%d %d %d", &n,&m,&d);
    for(int i=0; i<m; i++) {
        scanf("%d", &x);
        a[x] = 1;
    }
    for(int i=1; i<n; i++) {
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1);
//     for(int i=1; i<=n; i++) cout << i << ' ' << dis[i] << ' ' << chi[i] << ' ' << dis2[i] << ' ' << chi2[i] << endl;
    memset(vis, 0, sizeof vis);
    dfs2(1);  /// for(int i=1; i<=n; i++) cout << i << ' ' << dis[i] << ' ' << chi[i] << ' ' << dis2[i] << ' ' << chi2[i] << endl;

    int ans = 0;
    for(int u=1; u<=n; u++) ans += (dis[u] <= d);
    printf("%d\n", ans);
}
