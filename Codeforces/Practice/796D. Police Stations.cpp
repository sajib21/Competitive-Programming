#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 300005

using namespace std;

int n,k,d, uu[LIM], vv[LIM];
vi g[LIM];
int vis[LIM], dis[LIM];

int main() {
    scanf("%d %d %d", &n,&k,&d);
    queue<int>q;
    for(int i=0; i<k; i++) {
        int u;
        scanf("%d", &u);
        q.push(u);
        vis[u] = 1;
    }

    for(int i=1; i<n; i++) {
        int u,v;
        scanf("%d %d", &u,&v);
        uu[i] = u; vv[i] = v;
        g[u].pb(v); g[v].pb(u);
    }

    int ans = 0;
    vi solu, solv;

    map< pair<int,int>, bool>ase;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        if(dis[u] >= d) continue;

        for(auto v: g[u]) {
            if(vis[v]) {
//                solu.pb(u); solv.pb(v);
                continue;
            }
            ans++;
            vis[v] = 1;
            dis[v] = dis[u]+1;
            q.push(v);

            ase[ make_pair(min(u,v), max(u,v)) ] = 1;

        }
    }


//    cout << ans << endl;
    printf("%d\n", n-1-ans);

    for(int i=1; i<n; i++) {
            int u = uu[i], v = vv[i];
//            if(v < u) continue;
            if(ase.find(make_pair(min(u,v),max(u,v))) == ase.end()) printf("%d\n", i);
    }
}
