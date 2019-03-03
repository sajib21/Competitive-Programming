#include<bits/stdc++.h>
#define LIM 1005
#define vi vector<int>
#define pb push_back

using namespace std;

int n,k;
vi g[LIM];
int vis[LIM];

int f(int u) {
    vis[u] = 1;
    if(u != 1 && g[u].size() == 1) return 1;
//    if(g[u].size() < k) return 1;

    priority_queue<int>pq;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        pq.push( f(v) );
    }
    pq.push(0);

    int ans = 1;
    for(int i=0; i<k; i++) {
        if(!pq.top()) return 1;
        ans += pq.top();
        pq.pop();
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&k);
        memset(g, NULL, sizeof g);

        for(int i=1; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            g[u].pb(v); g[v].pb(u);
        }

        memset(vis, 0, sizeof vis);
//        memset(sub, 0, sizeof sub);

        printf("Case %d: %d\n", t, f(1) );
    }
}
