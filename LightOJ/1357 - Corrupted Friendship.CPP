#include    <bits/stdc++.h>
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     100000
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

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

int n;
bool vis[LIM+10];
vii graph[LIM+10];
ll ans;

ll dfs(int u) {
    vis[u] = 1;
    ll mul = 0;
    ll cnt=0, br, sub=0, sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v]) {
            cnt++;
            br = dfs(v);
            mul += sub*br;
            sub += br;
        }
    }
    if(cnt > 1) ans += mul;
    return sub + 1;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) graph[i].clear();
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for(int i=1; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
        }
        dfs(1);
        printf("Case %d: %d %lld\n", t, n-1, ans);
    }

    return 0;
}
