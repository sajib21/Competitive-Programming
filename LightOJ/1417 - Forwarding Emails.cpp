#include<bits/stdc++.h>
#define LIM 50000
#define pb push_back
using namespace std;

int n, vis[LIM+10], vis2[LIM+10];
vector<int>graph[LIM+10];
stack<int>stk;

void dfs(int u) {

    vis[u] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

int dfs2(int u) {

//    cout << "IN " << u << endl;


    vis[u] = vis2[u] = 1;
    int ans = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis2[v]) ans += dfs2(v);
    }
    vis2[u] = 0;
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) graph[i].clear();
        memset(vis, 0, sizeof(vis));
        memset(vis2, 0, sizeof(vis2));
        for(int i=0; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
        }
        int ans = 0 , ansa = 0;
        for(int i=1; i<=n; i++) {
            int temp = 0;
            if(!vis[i]) temp = dfs2(i);
            if(temp > ans) {
                ans = temp;
                ansa = i;
            }
        }
        printf("Case %d: %d\n", t, ansa);
    }
    return 0;
}
