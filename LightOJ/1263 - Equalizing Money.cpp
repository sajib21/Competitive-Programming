#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

int n,m, money[LIM+10], vis[LIM+10];
vii graph[LIM+10];

pii dfs(int u) {
    vis[u] = 1;
//    cout << u << ' ' << money[u] << endl;
    int nd=1, mon=money[u];
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]){
            pii temp = dfs(v);
            nd += temp.first;
            mon += temp.second;
        }
    }
    return pii(nd, mon);
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        for(int i=1; i<=n; i++) graph[i].clear();
        for(int i=1; i<=n; i++) scanf("%d", &money[i]);
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        memset(vis, 0, sizeof(vis));
        int av = 0;
        bool con = true;
        for(int u=1; u<=n; u++) {
            if(!vis[u]) {
//                cout << "CALLING DFS " << u << endl;
                pii info = dfs(u);
//                cout << "DFS " << ' ' << u << ' ' << info.first << ' ' << info.second << ' ' << av << endl;
                if(info.second % info.first) {
                    con = false;
                    break;
                }
                else {
                    if(!av) av = info.second / info.first;
                    else {
                        if(av != info.second / info.first) {
                            con = false;
                            break;
                        }
                    }
                }
            }
        }
        if(con) printf("Case %d: Yes\n", t);
        else printf("Case %d: No\n", t);
    }

    return 0;
}
