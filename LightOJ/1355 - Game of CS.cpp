#include    <bits/stdc++.h>
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     1000
#define     MOD     1000000007
#define     MAX     10000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

///STARS AND BARS : (n+k-1)C(k-1)

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

