#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 20000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

int n,m;
vii graph[LIM+100], revGraph[LIM+100];
int vis[LIM+100], cmp, comp[LIM+100], compIn[LIM+100], compOut[LIM+100];
stack<int>stk;

void dfs1(int u) {
    vis[u] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            dfs1(v);
        }
    }
    stk.push(u);
}

void dfs2(int u, int cmp) {
    vis[u] = 1;
    comp[u] = cmp;
    int sz = revGraph[u].size();
    for(int i=0; i<sz; i++) {
        int v = revGraph[u][i];
        if(!vis[v]) {
            dfs2(v, cmp);
        }
        else {
            if(cmp != comp[v]) {
                compOut[ comp[u] ] = 1;
                compIn[ comp[v] ] = 1;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        for(int i=1; i<=n; i++) graph[i].clear() , revGraph[i].clear();
        memset(comp, 0, sizeof(comp));
        memset(compIn, 0, sizeof(compIn));
        memset(compOut, 0, sizeof(compOut));
        cmp = 0;
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            revGraph[v].pb(u);
        }
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; i++) if(!vis[i]) dfs1(i);

        memset(vis, 0, sizeof(vis));
        while(!stk.empty()) {
            int u = stk.top();
            stk.pop();
            if(!vis[u]) {
                dfs2(u, ++cmp);
            }
        }
        int in = 0, out = 0;
        for(int i=1; i<=cmp; i++) in += compIn[i] , out += compOut[i];

//        cout <<
        if(cmp == 1) printf("Case %d: %d\n", t, 0);
        else printf("Case %d: %d\n", t, max(cmp-in, cmp-out));
    }
    return 0;

}
