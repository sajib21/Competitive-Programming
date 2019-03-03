#include<bits/stdc++.h>
#define IM 100000
using namespace std;

int n,m;
vector<int>graph[1010], cost[1010], revGraph[1010];
int key[1010], res[1010], vis[1010];

void dfs(int u) {

    vis[u] = 1;
    res[u] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            dfs(v);
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

//        memset(key, 129, sizeof(key));

        memset(res, 0, sizeof(res));
        memset(vis, 0, sizeof(vis));

        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) graph[i].clear(), cost[i].clear(), revGraph[i].clear();
        for(int i=0; i<n; i++) key[i] = IM;

        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[v].push_back(u);
            cost[v].push_back(w);
            revGraph[v].push_back(u);
        }

        key[0] = 0;
        for(int k=1; k<n; k++) {
            for(int u=0; u<n; u++) {
                int sz = graph[u].size();
                for(int i=0; i<sz; i++) {
                    int v = graph[u][i];
                    if(key[u] + cost[u][i] < key[v]) {
                        key[v] = key[u] + cost[u][i];
                    }
                }
            }
        }
        vector<int>temp;
        for(int u=0; u<n; u++) {
            int sz = graph[u].size();
            for(int i=0; i<sz; i++) {
                int v = graph[u][i];
                if(key[u] + cost[u][i] < key[v]) {
//                    key[v] = key[u] + cost[u][i];
//                    if(!res[v]) cout << u << ' ';
                    res[v] = 1;
                    temp.push_back(v);
//                    ans.insert(u);2
                }
            }
        }

        int sz = temp.size();
        for(int i=0; i<sz; i++) {
            int u = temp[i];
            if(!vis[u]) {
                dfs(u);
            }
        }

//        cout << "bug" << endl;

        printf("Case %d:", t);
        if(!sz) printf(" impossible\n");
        else {
            for(int i=0; i<n; i++) if(res[i] == 1) printf(" %d", i);
            printf("\n");
        }
    }
    return 0;
}
