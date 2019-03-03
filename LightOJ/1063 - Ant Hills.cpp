#include<bits/stdc++.h>

using namespace std;

vector<int>graph[10010];
int visited[10010], d[10010], f[10010], low[10010], par[10010], tim;
int arti[10010],artiCnt, root;

void dfs(int u) {

    visited[u] = 1;
    low[u] = d[u] = ++tim;
    int nocRoot = 0;

    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];

        if(v == par[u]) continue;

        if(visited[v]) {
            low[u] = min(low[u], d[v]);
        }
        else {
            par[v] = u;
            dfs(v);

            low[u] = min(low[u], low[v]);
            if(d[u] <= low[v] && u != root) {

                if(!arti[u]) {
                    arti[u] = 1;
                    artiCnt++;
                }
                //cout << "arti 1 : " << u << "d of u" << d[u] << endl;
            }
            nocRoot++;
        }
    }
    if(u == root && nocRoot > 1) {
        if(!arti[u]) {
            arti[u] = 1;
            artiCnt++;
        }
        //cout << "arti 2 : " << u << endl;
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++) {

        int n,m, u,v;
        scanf("%d %d", &n, &m);

        for(int i=0; i<=n; i++) graph[i].clear();
        memset(visited, 0, sizeof(visited));
        memset(par, 0, sizeof(par));
        memset(arti, 0, sizeof(arti));
        tim = 0;
        artiCnt = 0;


        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                root = i;
                dfs(root);
            }
        }

        printf("Case %d: %d\n",t, artiCnt);

    }

    return 0;

}
