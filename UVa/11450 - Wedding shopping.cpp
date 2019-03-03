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

int n,m, tp[22], p[22][22];
int dp[22][220];

int getAns(int in, int taken) {
    if(taken > m) return INT_MIN;
    if(in == n) return 0;
    if(dp[in][taken] != -1) return dp[in][taken];

    int ans = INT_MIN;
    for(int i=0; i<tp[in]; i++) {
        int temp = getAns(in+1, taken+p[in][i]);
        ans = max(ans, p[in][i]+temp);
    }
    return dp[in][taken] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &m,&n);
        for(int i=0; i<n; i++) {
            scanf("%d", &tp[i]);
            for(int j=0; j<tp[i]; j++) scanf("%d", &p[i][j]);
        }
        int ans = getAns(0,0);
        if(ans < 0) printf("no solution\n");
        else printf("%d\n", ans);
    }

    return 0;
}
