#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int>graph[10004]; //bridgeTree[10004];
int dis[10004], par[10004], low[10004], comp[10004], countComp, tim;
map<int, int>bridgeTree[10004];
stack<int>stk;

void dfs(int u) {

    low[u] = dis[u] = ++tim;
    stk.push(u);

    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!dis[v]) {
            par[v] = u;

            dfs(v);
            low[u] = min(low[u], low[v]);
            if(dis[u] < low[v]) {
                while(stk.top() != u) {
                    comp[ stk.top() ] = countComp;
                    stk.pop();
                }
                countComp++;
            }
        }
        else if(v != par[u]) {
            low[u] = min(low[u], dis[v]);
//            low[u] = min(low[u], low[v]);
        }
    }
//    tim++;
//    comp[u] = countComp;
//    comp[u] = low[u];
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

        for(int i=0; i<n; i++) {
            if(!dis[i]) {
                dfs(i);
                while(!stk.empty()) {
                    comp[ stk.top() ] = countComp;
                    stk.pop();
                }
                countComp++;
            }
        }



//        for(int i=0; i<n; i++) cout << comp[i] << ' ' ;
//        cout << endl;


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
