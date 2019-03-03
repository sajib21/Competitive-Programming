#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

vector<int> graph[10010];
vector<pii> pr;
int arti[1000][1000];
int color[10010], d[10010], f[10010], low[10010], pre[10010];
int tim, rootCheck;
//int graph2[10010][10010];

void dfs(int node) {
    color[node] = 1;
    d[node] = ++tim;
    low[node] = d[node]; //arti

    for(int i=0; i<graph[node].size(); i++) {

        int v = graph[node][i];

        if(v == pre[node]) continue;

        if(color[ v] == 0) {
            pre[v] = node;
            dfs(v);

            if(low[ v ] > d[node] ) { //ARTI
                //arti[node][i] = arti[i][node] = 1;
                int uu = node, vv = v;
                if(uu > vv) swap(uu,vv);
                pr.push_back(make_pair(uu,vv));

                //cout << node << '\t' << i << endl;
            }
            low[node] = min(low[node],low[ v ]);
        }

        else if( v != pre[node])
            low[node] = min(low[node], d[ v  ]);

        //if(d[ v ] < low[node]) low[node] = d[v];


    }
    color[node] = 2;
    f[node] = ++tim;
}

int main() {

    int T,t;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

    pr.clear();

    int n,m;
    //cin >> n >> m;
    scanf("%d", &n);

    for(int i=0; i<n; i++) graph[i].clear();

    for(int i=0; i<n; i++) {
        int u,v;
        //cin >> u >> v;
        scanf("%d (%d)", &u, &m);
        for(int j=0; j<m; j++) {
            scanf("%d", &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    memset(low, 300000, sizeof(low));
    memset(f, 300000, sizeof(f));
    memset(d, 300000, sizeof(d));
    memset(color, 0, sizeof(color));
    memset(pre, 0, sizeof(pre));


    for(int i=0; i<n; i++) {
        if(!color[i]) {
            //cout << "debug" << endl;

            dfs(i);
            //cout << "debug" << endl;
            //if(graph[i].size() > 1) arti[i] = 1;
            //else arti[i] = 0;
        }

    }

    sort(pr.begin(), pr.end());

    printf("Case %d:\n", t);
    printf("%d critical links\n", pr.size());
    int sz = pr.size();

    for(int i=0; i<sz; i++) {
        printf("%d - %d\n", pr[i].first, pr[i].second);
    }
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<n; j++) {
//            if(arti[i][j] == 1) printf("%d %d\n", i,j);
//        }
//    }
    }
    return 0;




}

