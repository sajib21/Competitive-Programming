#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define pp pop_back

#define LIM 100000

using namespace std;

int n,m, sz[2*LIM+10];
vii words[LIM+10];
vii graph[2*LIM+10], revGraph[2*LIM+10];

int bar(int x) { return (x+m)%(2*m); }

int vis[2*LIM+10], comp[2*LIM+10], value[LIM+10], c;
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

void compDfs(int u) {
    vis[u] = 1; comp[u] = c;
    int sz = revGraph[u].size();
    for(int i=0; i<sz; i++) {
        int v = revGraph[u][i];
        if(!vis[v]) compDfs(v);
    }
}

int main() {
    scanf("%d %d", &n,&m);
    m++;
    for(int i=0; i<n; i++) {
        scanf("%d", &sz[i]);
        for(int j=0; j<sz[i]; j++) {
            int x; scanf("%d", &x);
            words[i].pb(x);
        }
    }

    for(int i=1; i<n; i++) {
//        cout << "IN " << i << ' ' << n << endl;
        bool f = false;
        for(int j=0; j<sz[i] && !f; j++) {
            if(j == sz[i-1]) {
                f = true;
                break;
            }
            int x = words[i-1][j] , y = words[i][j];
            if(x == y) continue;
            if(x > y) {
                graph[x].pb(bar(x)) , revGraph[bar(x)].pb(x); /// x -> !x : giving x false
                graph[bar(y)].pb(y) , revGraph[y].pb(bar(y));
            }
            else {
                graph[x].pb(y) ,            revGraph[y].pb(x);
                graph[bar(y)].pb(bar(x)) ,  revGraph[bar(x)].pb(bar(y));
            }
            f = true;
        }
        if(!f && sz[i-1] > sz[i]) {
            printf("No\n");
            return 0;
        }
    }
//    cout << "BUG" << endl;
    memset(vis, 0, sizeof vis);
    for(int u=0; u<2*m; u++) if(!vis[u]) dfs(u);
    memset(vis, 0, sizeof vis);
    c = 0;
    while(!stk.empty()) {
        int u = stk.top(); stk.pop();
        if(vis[u]) continue;
        c++;
        compDfs(u);
    }
    for(int v=1; v<m; v++) if(comp[v] == comp[bar(v)]) {
        printf("No\n");
        return 0;
    }
    for(int v=1; v<m; v++) {
        if(comp[v] < comp[bar(v)]) value[v] = 1;
        else value[v] = 0;
    }

    int ans = 0;
    for(int v=1; v<m; v++) if(value[v]) ans++;
    printf("Yes\n");
    printf("%d\n", ans);
    bool sp = false;
    for(int v=1; v<m; v++) {
        if(sp) printf(" ");
        if(value[v]) {
            printf("%d", v);
            sp = true;
        }
    }
    if(sp) printf("\n");

    return 0;

}
