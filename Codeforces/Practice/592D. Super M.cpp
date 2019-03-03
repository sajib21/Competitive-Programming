#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define LIM 200005

using namespace std;

int n,m,x, a[LIM];
vi g[LIM];
int vis[LIM], ase[LIM];
int sumDis[LIM], maxDis[LIM], maxChild[LIM], max2Dis[LIM], max2Child[LIM];

bool dfs(int u) {
    vis[u] = 1;
    ase[u] |= a[u];

    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        if(!dfs(v)) continue;

        ase[u] = 1;
        sumDis[u] += sumDis[v]+1;
        if(maxDis[v]+1 > maxDis[u]) {
            max2Dis[u] = maxDis[u]; max2Child[u] = maxChild[u];
            maxDis[u] = maxDis[v]+1; maxChild[u] = v;
        }
        else if(maxDis[v]+1 > max2Dis[u]) {
            max2Dis[u] = maxDis[v]+1;
            max2Child[u] = v;
        }
    }
    return ase[u];
}

void dfs2(int u) {
    vis[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;

        if(ase[v]) sumDis[v] = sumDis[u];
        else sumDis[v] = sumDis[u]+1;

        if(maxChild[u] != v) {
            if(maxDis[u]+1 > maxDis[v]) {
                max2Dis[v] = maxDis[v]; max2Child[v] = maxChild[v];
                maxDis[v] = maxDis[u]+1; maxChild[v] = u;
            }
            else if(maxDis[u]+1 > max2Dis[v]) {
                max2Dis[v] = maxDis[u]+1; max2Child[v] = u;
            }
        }
        else if(max2Child[u] != v) {
            if(max2Dis[u]+1 > maxDis[v]) {
                max2Dis[v] = maxDis[v]; max2Child[v] = maxChild[v];
                maxDis[v] = max2Dis[u]+1; maxChild[v] = u;
            }
            else if(max2Dis[u]+1 > max2Dis[v]) {
                max2Dis[v] = max2Dis[u]+1; max2Child[v] = u;
            }
        }
        dfs2(v);
    }
}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &x);
        a[x] = 1;
    }

    dfs(x);

//    cout << "PRIMARY " << endl;
//    for(int i=1; i<=n; i++) cout << i << ' ' << sumDis[i] << ' ' << maxDis[i] << ' ' << maxChild[i] << ' ' << max2Dis[i] << ' ' << max2Child[i] << endl;

    memset(vis, 0, sizeof vis);
    dfs2(x);

    int ans=INT_MAX, p;
    for(int u=1; u<=n; u++) if(2*sumDis[u] - maxDis[u] < ans) {
        ans = 2*sumDis[u] - maxDis[u]; p = u;
    }

    printf("%d\n%d\n", p, ans);
}
