#include<bits/stdc++.h>
#define ll long long int
#define LIM 30000
#define pb push_back

using namespace std;

int n;
ll key[LIM+10];
vector<int>graph[LIM+10], costs[LIM+10];

ll maxDist() {

    ll uu,du=0;

    memset(key, -1, sizeof(key));
    key[0] = 0;

    queue<int>q;
    q.push(0);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(key[u] > du) {
            du = key[u];
            uu = u;
        }

        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i] , k = costs[u][i];
            if(key[v] == -1) {
                key[v] = key[u] + k;
                q.push(v);
            }
        }
    }

    memset(key, -1, sizeof(key));
    key[uu] = 0;
    du = 0;

    q.push(uu);
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(key[u] > du) {
            du = key[u];
            uu = u;
        }
        int sz = graph[u].size();
        for(int i=0; i<sz; i++) {
            int v = graph[u][i] , k = costs[u][i];
            if(key[v] == -1) {
                key[v] = key[u] + k;
                q.push(v);
            }
        }
    }
    return du;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<=n; i++) graph[i].clear() , costs[i].clear();

        for(int i=1; i<n; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u].pb(w);
            costs[v].pb(w);
        }
        printf("Case %d: %lld\n", t, maxDist());
    }

    return 0;
}
