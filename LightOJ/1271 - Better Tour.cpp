#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 50000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int n, u,v, s,t, sd;
vii graph[LIM+10], ct;
int keysS[LIM+10], keysT[LIM+10], par[LIM+10], vis[LIM+10];

int bfs(int keys[LIM+10]) {
    keys[s] = 0;
    queue<int>q;
    q.push(s);

    for(int i=0; i<ct.size(); i++) {
        int u = ct[i];
        sort(graph[u].begin(), graph[u].end());
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(u == t) break;

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            if(keys[v] == -1) {
                keys[v] = keys[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    sd = keys[s];
}

void dfs(int s) {
    if(!s) return;

    dfs(par[s]);
    printf("%d ", s);

}

int main() {
//
//    freopen("1271i.txt", "r", stdin);
//    freopen("1271o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++) {
        for(int i=1; i<=LIM; i++) graph[i].clear();
        ct.clear();
        memset(keysS, -1, sizeof(keysS));
        memset(par, 0, sizeof(par));
//        memset(keysT, -1, sizeof(keysT));
        scanf("%d", &n);
        scanf("%d", &u);
        s = u;
        ct.pb(s);
        for(int i=1; i<n; i++) {
            scanf("%d", &v);
            ct.pb(v);
            graph[u].pb(v);
            graph[v].pb(u);
            u = v;
            t = v;
        }

        bfs(keysS);
//        getchar(); getchar();



        printf("Case %d:\n", tt);
        dfs(par[t]);
        printf("%d\n", t);

    }
}
