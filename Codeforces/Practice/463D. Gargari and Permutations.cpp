///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);

using namespace std;

struct info{
    int x,y,z;
    info() {x = y = z = 0;}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};
bool cmpx(info x, info y) {
    return x.x < y.x;
}
bool cmpy(info x, info y) {
    return x.y < y.y;
}

int n,k, pos[6][1010], per[6][1010];
vii graph[1010];

int dp[1010];

int f(int u) {
    if(dp[u] != -1) return dp[u];
    int sz = graph[u].size(), ans = 0;
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        ans = max(ans, f(v));
    }
    return dp[u] = ans + 1;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n,&k);

    for(int i=1; i<=k; i++) {
        for(int j=1; j<=n; j++) {
                int x;
            scanf("%d", &x);
            pos[i][x] = j;
            per[i][j] = x;
        }
    }

    for(int u=1; u<=n; u++) {
        for(int v=1; v<=n; v++) {
            if(u != v) {
                bool f = true;
                for(int i=1; i<=k && f; i++) if(pos[i][u] > pos[i][v]) f = false;
                if(f) graph[u].pb(v);
            }
        }
    }

    int ans = 0;
    for(int u=1; u<=n; u++) ans = max(ans, f(u));

    printf("%d", ans);

    return 0;
}
