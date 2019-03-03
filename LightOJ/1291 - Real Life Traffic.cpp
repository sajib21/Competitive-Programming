#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

vector<int> graph[10010], g2[10010];
stack<int> nd;
int color[10010], d[10010], f[10010], low[10010], pre[10010];
int tim;
int comp = 0;
int compo[10010];
int compoEdge[10010];

void dfs(int node) {
    color[node] = 1;
    d[node] = ++tim;
    low[node] = d[node]; //arti
    nd.push(node);

    for(int i=0; i<graph[node].size(); i++) {
        if(color[ graph[node][i]] == 0) {
            //cout << node << " and v is " << graph[node][i] << " " << " DEBUG " << endl;
            pre[graph[node][i]] = node;
            dfs(graph[node][i]);
            //cout << node << " and v is " << graph[node][i] << " " << " dfs theke bair hoise " << endl;


            if(low[ graph[node][i] ] > d[node] ) { //ARTI

                   // cout << "debug" <<endl;

                comp++;
                while( nd.top() != node) {
                    compo[nd.top()] = comp;
                    nd.pop();
                }
                g2[node].push_back(graph[node][i]);
                g2[graph[node][i]].push_back(node);

//                g2[comp].push_back(comp-1);
//                g2[comp-1].push_back(comp);
            }

            if(low[ graph[node][i] ] < low[node]) low[node] = low[ graph[node][i] ];
        }
        else if(pre[node] != graph[node][i] && d[ graph[node][i] ] < low[node]) low[node] = d[graph[node][i]];
    }

    color[node] = 2;
    f[node] = ++tim;
}

int main() {

    int t,T;
    scanf("%d", &T);

    for(t=1; t<=T; t++) {
        comp=0;
        int n,m;

        scanf("%d %d", &n, &m);

        for(int i=0; i<=n; i++) {
            graph[i].clear();
            g2[i].clear();
        }
        //nd.clear();
        while(!nd.empty()) nd.pop();


        for(int i=0; i<m; i++) {
            int u,v;
        //cin >> u >> v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        memset(low, 300000, sizeof(low));
        memset(f, 300000, sizeof(f));
        memset(d, 300000, sizeof(d));
        memset(color, 0, sizeof(color));
        memset(pre, 0, sizeof(pre));
        memset(compo, 0, sizeof(compo));
        memset(compoEdge, 0, sizeof(compoEdge));
        tim = 0;


        for(int i=0; i<n; i++) {
            if(!color[i]) {
                dfs(i);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            //if(g2[i].size() == 1) ans++;
            compoEdge[ compo[i] ] += g2[i].size();
        }

        for(int i=0; i<=comp; i++) {
            if(compoEdge[i] == 1) ans++;
        }

        printf("Case %d: %d\n", t, (ans+1)/2);
    }

    return 0;


}

