#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back

using namespace std;

int n,m,k;
int oc[2020], ox[2020], oy[2020];
int cc[7], cs[7][5];

vii g[2020], rg[2020];

int bar(int x) { return (x+n)%(2*n); }

int value[2020], vis[2020], comp[2020], c, sol[2020];
stack<int>stk;

void dfs1(int u) {
    vis[u] = 1;
    int sz = g[u].size();
    for(int i=0; i<sz; i++) {
        int v = g[u][i];
        if(!vis[v]) dfs1(v);
    }
    stk.push(u);
}

void dfs2(int u) {
    vis[u] = 1;
    comp[u] = c;
    int sz = rg[u].size();
    for(int i=0; i<sz; i++) {
        int v = rg[u][i];
        if(!vis[v]) dfs2(v);
    }
}

bool backTrack(int in) {
    if(in == k) {
        memset(vis, 0, sizeof vis);
        for(int u=0; u<2*n; u++) if(!vis[u]) dfs1(u);
        c=0;
        memset(vis, 0, sizeof vis);
        memset(comp, 0, sizeof comp);
        while(!stk.empty()) {
            int u = stk.top();
            stk.pop();
            if(vis[u]) continue;
            c++;
            dfs2(u);
        }
        for(int u=0; u<n; u++) if(comp[u] == comp[bar(u)]) return false;
        for(int v=0; v<n; v++) {
            if(comp[v] < comp[bar(v)]) value[v] = 0;
            else value[v] = 1;
        }
        return true;
    }
    if(cc[in] == 1) {
        bool f = false;
        for(int i=0; i<3 && !f; i++) if(value[ cs[in][i] ] == 1) f = true;
        if(f) return backTrack(in+1);
        for(int i=0; i<3; i++) {
            int v = cs[in][i];
            if(value[v] == -1) {
                value[v] = 1; /// assign true to v : !x -> x
                g[bar(v)].pb(v);            rg[v].pb(bar(v));
                if(backTrack(in+1)) return true;
                value[v] = -1;
                g[bar(v)].pop_back();       rg[v].pop_back();
            }
        }
    }
    else {
        bool f = false;
        for(int i=0; i<3 && !f; i++) if(value[ cs[in][i] ] == 0) f = true;
        if(f) return backTrack(in+1);
        for(int i=0; i<3; i++) {
            int v = cs[in][i];
            if(value[v] == -1) {
                value[v] = 0; /// assign false to v : x -> !x
                g[v].pb(bar(v));             rg[bar(v)].pb(v);
                if(backTrack(in+1)) return true;
                value[v] = -1;
                g[v].pop_back();             rg[bar(v)].pop_back();
            }
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(g, NULL, sizeof g);
        memset(rg, NULL, sizeof rg);
        while(!stk.empty()) stk.pop();

        scanf("%d %d %d", &n,&m,&k);
        for(int i=0; i<m; i++) scanf("%d %d %d", &oc[i], &ox[i], &oy[i]);
        for(int i=0; i<m; i++) ox[i]-- , oy[i]-- ;
        for(int i=0; i<k; i++) {
            scanf("%d", &cc[i]);
            for(int j=0; j<3; j++) {
                scanf("%d", &cs[i][j]);
                cs[i][j]--;
            }
        }

        for(int i=0; i<m; i++) {
            int x = ox[i], y = oy[i];
            if(oc[i] == 1) { /// !x -> y : !y -> x
                g[bar(x)].pb(y);            rg[y].pb(bar(x));
                g[bar(y)].pb(x);            rg[x].pb(bar(y));
            }
            else if(oc[i] == 2) { /// !x -> !y : y -> x
                g[bar(x)].pb(bar(y));       rg[bar(y)].pb(bar(x));
                g[y].pb(x);                 rg[x].pb(y);
            }
            else if(oc[i] == 3) { /// x -> !y : y -> !x
                g[x].pb(bar(y));            rg[bar(y)].pb(x);
                g[y].pb(bar(x));            rg[bar(x)].pb(y);
            }
            else { /// x -> !y : y -> !x || !x -> y : !y -> x
                g[x].pb(bar(y));            rg[bar(y)].pb(x);
                g[y].pb(bar(x));            rg[bar(x)].pb(y);
                g[bar(x)].pb(y);            rg[y].pb(bar(x));
                g[bar(y)].pb(x);            rg[x].pb(bar(y));
            }
        }
        memset(value, -1, sizeof value);
        memset(sol, 0, sizeof sol);
        if(backTrack(0)) {
            int ans = 0;
            for(int i=0; i<n; i++) ans += value[i];
            printf("Case %d: Possible %d", t, ans);
            for(int i=0; i<n; i++) if(value[i] == 1) printf(" %d", i+1);
            printf(".\n");
        }
        else {
            printf("Case %d: Impossible.\n", t);
        }
    }
    return 0;
}
