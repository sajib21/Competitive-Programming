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
    return x.x > y.x;
}
bool cmpy(info x, info y) {
    return x.y < y.y;
}

int bs_upper_bound(info a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x <= a[mid].x) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int n;
info b[LIM+10];
int dp[LIM+10];

int getMin(int in) {
    if(in == n) return 0;
    if(dp[in] != -1) return dp[in];
    return dp[in] = b[in].z-in-1 + getMin(b[in].z);
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d %d", &b[i].x, &b[i].y );
    sort(b, b+n, cmpx);
    for(int i=0; i<n; i++) b[i].z = bs_upper_bound(b, n, b[i].x-b[i].y) ;
//    for(int i=0; i<n; i++) cout << b[i].x << ' ' << b[i].y << ' ' << b[i].z << endl;

    int ans = n;
    for(int i=0; i<n; i++) ans = min(ans, i+getMin(i));

//    for(int i=0; i<n; i++) cout << dp[i] << endl;

    printf("%d\n", ans);

    return 0;
}
