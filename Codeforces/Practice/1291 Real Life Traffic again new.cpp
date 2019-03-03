#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
using namespace std;

int n,m;
vector<int>graph[10004]; //bridgeTree[10004];
int dis[10004], par[10004], low[10004], comp[10004], countComp, tim;
map<int, int>bridgeTree[10004];
vector<pii>bridge;
map<int, map<int, int> > bridgeFlag;

void dfs(int u) {

    low[u] = dis[u] = ++tim;
//    stk.push(u);

    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!dis[v]) {
            par[v] = u;

            dfs(v);
            low[u] = min(low[u], low[v]);
            if(dis[u] < low[v]) {
                bridge.pb(pii(u,v));
                bridgeFlag[u][v] = bridgeFlag[v][u] = 1;
            }
        }
        else if(v != par[u]) {
            low[u] = min(low[u], dis[v]);
        }
    }
}

void dfs_comp(int u, int compNum) {

    comp[u] = compNum;
    dis[u] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!dis[v]) {
            if(bridgeFlag[u][v] != 1 && bridgeFlag[v][u] != 1) {
                dfs_comp(v, compNum);
            }
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(dis, 0, sizeof(dis));
        memset(low, 0, sizeof(low));
        memset(comp, -1, sizeof(comp));
        countComp = 0; tim = 0;
//        stk.clear();

        scanf("%d %d", &n,&m);
        for(int i=0; i<=n; i++) graph[i].clear(), bridgeTree[i].clear();

        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bridge.clear();
        bridgeFlag.clear();

        for(int i=0; i<n; i++) {
            if(!dis[i]) {
                dfs(i);
            }
        }

        memset(dis, 0, sizeof(dis));
        memset(comp, -1, sizeof(comp));
        int sz = bridge.size();

//        for(int i=0; i<sz; i++) cout << bridge[i].first << ' ' << bridge[i].second << endl;



        countComp = 0;
        for(int i=0; i<sz; i++) {
            int a = bridge[i].first, b = bridge[i].second;
//            cout << "check dis " << a << ' ' << dis[a] << endl;
            if(!dis[a]) {
                dfs_comp(a, countComp);
                countComp++;
            }
            if(!dis[b]) {
                dfs_comp(b, countComp);
                countComp++;
            }
        }
//        for(int i=0; i<n; i++) cout << comp[i] << ' ' ; cout << endl;

        for(int u=0; u<n; u++) {
            int sz = graph[u].size();
            for(int i=0; i<sz; i++) {
                int v = graph[u][i];
                if(comp[u] != comp[v]) {
                    bridgeTree[ comp[u] ][ comp[v] ] = 1; //.push_back( comp[v] );
                    bridgeTree[ comp[v] ][comp [u] ] = 1; //.push_back( comp[u] );
                }
            }
        }
        int leaf = 0;
        for(int i=0; i<countComp; i++) {

//            cout << bridgeTree[i].size() << ' ';
            if(bridgeTree[i].size() == 1) leaf++;
            if(bridgeTree[i].size() == 0) leaf+=2;

        } //cout << endl;
        printf("Case %d: %d\n", t, (leaf+1)/2 );

    }

    return 0;
}
