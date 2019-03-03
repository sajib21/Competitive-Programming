#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9

using namespace std;

int n,k,u,v;
vii graph[1010],revGraph[1010], compVec[1010];
int vis[1010], comp[1010], compGraph[1010][1010];
int totcomp;
stack<int>stk;

void dfs1(int u) {
    vis[u] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) dfs1(v);
    }
    stk.push(u);
}

void dfs2(int u, int cmp) {
//    cout << "DFS2 IN " << u << cmp << endl;
    vis[u]++;
    comp[u] = cmp;
    int sz = revGraph[u].size();
    for(int i=0; i<sz; i++) {
        int v = revGraph[u][i];
//        cout << "OUT " << v << endl;
//        getchar();
        if(vis[v] != 2) dfs2(v, cmp);
//        else {
//            int vcmp = comp[v];
//            if(vcmp == cmp) continue;
//            if(!compGraph[vcmp][cmp]) compVec[vcmp].pb(cmp);
//            compGraph[vcmp][cmp] = 1;
//        }
    }
}

bool dfs3(int u) {
    vis[u] = 1;
    if(compVec[u].size() > 1) return false;
    if(!compVec[u].empty()) {
        int vcmp = compVec[u][0];
//        if(vis[vcmp]) return false;
        if(!vis[vcmp])
            return dfs3(vcmp);
    }
    return true;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        for(int i=0; i<1000; i++) graph[i].clear();
        for(int i=0; i<1000; i++) revGraph[i].clear();
        for(int i=0; i<1000; i++) compVec[i].clear();
        memset(vis, 0, sizeof(vis));
        memset(compGraph, 0, sizeof(compGraph));
        totcomp = 0;

        scanf("%d", &n);
        while(n--) {
            scanf("%d", &k);
            while(k--) {
                scanf("%d %d", &u,&v);
                graph[u].pb(v);
                revGraph[v].pb(u);

            }
        }
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<1000; i++) {
            if(!vis[i] && graph[i].size()) {
                dfs1(i);
//                totcomp++;
//                if(totcomp > 1) break;
            }
        }
//        if(totcomp > 1) {
////            cout << "BUG" << endl;
//            printf("Case %d: NO\n", t);
//            continue;
//        }

//        memset(vis, 0, sizeof(vis));
        memset(comp, 0, sizeof(comp));
//        memset(compGraph, 0, sizeof(compGraph));
        int cmp = 0;
        while(!stk.empty()) {
            int u = stk.top();
            stk.pop();
            if(vis[u] != 2) {
                cmp++;
                dfs2(u, cmp);
//                cmp++;
            }
        }

        for(int u=0; u<1000; u++) {
            if(graph[u].size()) {
                int sz = graph[u].size();
                for(int i=0; i<sz; i++) {
                    int v = graph[u][i];
                    if(comp[u] != comp[v]) {
                        compVec[ comp[u] ].pb(comp[v]);
//                        compGraph[ comp[u] ][ comp[v] ] = 1;
                    }
                }
            }
        }

//        cout << "COMP CHECK " << endl;
//        for(int i=0; i<6; i++) cout << i << " : " << comp[i] << " || " << endl;
//        cout << "SZ " << compVec[ comp[0] ].size() << endl;
//        cout << compVec[ comp[0] ][0] << compVec[ comp[0] ][1]  <<endl;
//        cout << compGraph[ comp[0] ][ comp[3] ] << ' ' << compGraph[ comp[3] ][ comp[0] ] << endl;

//        if(cmp <= 1) {
//            printf("Case %d: YES\n", t);
//            continue;
//        }

        bool ans = true;
        memset(vis, 0, sizeof(vis));
//        dfs3(comp[0]);
        ans = dfs3(comp[0]);
        for(int i=1; i<=cmp; i++) if(!vis[i]) {
            ans = false ; break;
        }
        if(ans) printf("Case %d: YES\n", t);
        else printf("Case %d: NO\n", t);
    }
    return 0;
}
