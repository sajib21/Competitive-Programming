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

int w,b;
bool vis[1010][1010];
double dp[1010][1010];

double f(int rw, int rb) {
    if(rw < 0 || rb < 0) return 0;
    if(!rw) return 0;
    if(!rb) return 1;
    if(vis[rw][rb]) return dp[rw][rb];
    vis[rw][rb] = 1;

    double ans = 1.0 * rw / (rw+rb);
//    if(rb > 1)

    if(rb > 2) ans += 1.0 * rb/(rw+rb) * (rb-1)/(rw+rb-1) * (rb-2)/(rw+rb-2) * f(rw, rb-3);
    if(rb > 1 && rw > 0) ans += 1.0 * rb/(rw+rb) * (rb-1)/(rw+rb-1) * (rw)/(rw+rb-2) * f(rw-1, rb-2);

    return dp[rw][rb] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    memset(vis, 0, sizeof vis);

    scanf("%d %d", &w,&b);
    printf("%.10lf\n", f(w,b));

    return 0;
}
