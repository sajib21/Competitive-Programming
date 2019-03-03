#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 100005

using namespace std;

int n;
vi g[LIM];
bool vis[LIM];

double f(int u) {
    vis[u] = 1;
    double ans = 0;
    int div = g[u].size();
    if(u != 1) div--;

    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        ans += 1 + f(v);
    }
    if(div == 0) return ans;
    return ans / div;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    printf("%.8f\n", f(1) );
}
