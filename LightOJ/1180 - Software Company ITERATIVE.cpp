/// NORMALLY IT TAKES N^5 BUT WE HAVE TO MAKE IT IN N^4
/// WE WILL OPTIMIZE THE INNER N^2 LOOP.
/// INSTEAD IF CHECKING THE WHOLE (0,0) TO (R-1,C-1) GRID, WE WILL ONLY CHECK THE R-RP ROW AND C-CP COLUMN

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

int n,m, dp[103][103], prev[103][103];
int ratea[103], rateb[103];

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) scanf("%d %d", &ratea[i], &rateb[i]);

        for(int i=0; i<=m; i++) for(int j=0; j<=m; j++) prev[i][j] = 55555;
        for(int i=0; i<=m; i++) for(int j=0; j<=m; j++) dp[i][j]   = 55555;
        prev[0][0] = 0;

        for(int i=0; i<n; i++) {

            for(int row=0; row<=m; row++) {
                int rp = 0;
                int cp = 0;
                for(int col=0; col<=m; col++) {
                    while( rp < row && max( prev[ row-rp-1 ][ col ] , (rp+1)*ratea[i] ) <= max( prev[ row-rp ][ col ] , (rp)*ratea[i] ) ) rp++;
                    while( cp < col && max( prev[ row ][ col-cp-1 ] , (cp+1)*rateb[i] ) <= max( prev[ row ][ col-cp ] , (cp)*rateb[i] ) ) cp++;

                    for(int r=0; r<=rp; r++) dp[row][col] = min( dp[row][col] , max( prev[ row-r ][ col-cp ] , r*ratea[i] + cp*rateb[i] ) ) ;
                    for(int c=0; c<=cp; c++) dp[row][col] = min( dp[row][col] , max( prev[ row-rp ][ col-c ] , rp*ratea[i] + c*rateb[i] ) ) ;
                }
            }

            for(int row=0; row<=m; row++)
                for(int col=0; col<=m; col++)
                    prev[row][col] = dp[row][col];
        }

        printf("Case %d: %d\n", t, prev[m][m]);
    }

    return 0;
}
