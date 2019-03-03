#include<bits/stdc++.h>

using namespace std;

vector<int>graph[10010];
stack<int>stk;
int color[10010], d[10010], f[10010], tim;

void dfs(int u) {

    color[u] = 1;
    d[u] = ++tim;

    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!color[v]) {
            dfs(v);
        }
    }
    f[u] = ++tim;
    stk.push(u);
    //cout << "stk e dhuke " << u << endl;
}

void dfs2(int u) {

    color[u] = 1;
    d[u] = ++tim;

    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!color[v]) {
            dfs2(v);
        }
    }
    f[u] = ++tim;
    //stk.push(u);
    //cout << "stk 2 e dhuke " << u << endl;
}

int main() {

    int T,t;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n,m, u,v;
        tim = 0;
        scanf("%d %d", &n,&m);

        for(int i=0; i<=n; i++) graph[i].clear();
        //graph.empty()
        //stk.empty();
        memset(color, 0, sizeof(color));
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
        tim = 0;
        //int ans = 0;

        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
        }

        for(int i=1; i<=n; i++) {
            if(!color[i]) {
                //ans++;
                //cout << "call " << i << endl;
                dfs(i);
            }
        }

        memset(color, 0, sizeof(color));
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
        tim = 0;
        int ans = 0;

        while(!stk.empty()) {
            u = stk.top();
            stk.pop();
            if(!color[u]) {
                //cout << "u holo : " << u << endl;
                dfs2(u);
                ans++;
            }
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
