/// unit move: can remove 1 unit from edge
/// subtree removes when edge becomes 0 weight

using namespace std;

int n;
vll graph[LIM+10], costs[LIM+10];
int vis[LIM+10];

ll getVal(int u) {
    vis[u] = 1;
    int sz = graph[u].size();
    ll xorSum = 0;
    for(int i=0; i<sz; i++) {
        ll v = graph[u][i], c = costs[u][i];
        if(!vis[v]) {
            if(c == 1) xorSum ^= (getVal(v) + 1);
            else xorSum ^= (c%2 ^ getVal(v));
        }
    }
    return xorSum;
}

int main() {

//    freopen("1355i.txt", "r", stdin);
//    freopen("1355o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) graph[i].clear() , costs[i].clear();
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<n; i++) {
            ll u,v,w;
            scanf("%lld %lld %lld", &u,&v,&w);
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u].pb(w);
            costs[v].pb(w);
        }
        ll ans = getVal(0);
        if(ans) printf("Case %d: Emily\n", t);
        else printf("Case %d: Jolly\n", t);
    }

    return 0;
}

