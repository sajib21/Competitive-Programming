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

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

int n,m, target;
vii graph[17];
int dp[1 << 16];
bool graphMat[17][17];

void printBin(int n) {

    if(!n) return;
    printBin(n>>1);
    cout << n%2;
}

bool vis[16][1 << 16];
bool sub[1 << 16];

void dfs(int u, int mask) {
    vis[u][mask] = 1;
    sub[mask] = 1;
    int sz = graph[u].size();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        if(!vis[v][ setBit(mask,v) ]) dfs(v, setBit(mask, v));
    }
}

int getMin(int mask) {
    if(!mask) return 0;
    if(dp[mask] != -1) return dp[mask];

    int ans = 20;
    for(int vmask = mask; vmask; vmask = mask&(vmask-1)) {
        if(sub[vmask]) ans = min(ans, 1+getMin(mask ^ vmask) );
    }
    return dp[mask] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &m);
        for(int i=0; i<=n; i++) graph[i].clear();
        target = (1 << n) - 1;
//        cout << target << endl;
//        printBin(target) ; cout << endl;
        memset(dp, -1, sizeof dp);
        memset(sub, 0, sizeof sub);
        memset(vis, 0, sizeof vis);

        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            u--; v--;
            graph[u].pb(v);
        }

        for(int i=0; i<n; i++) dfs(i, setBit(0, i));

//        cout << "BUG" << endl;

        printf("Case %d: %d\n", t, getMin(target));


    }

    return 0;
}
