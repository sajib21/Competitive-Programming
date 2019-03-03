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

int n,m, dp[110][110], prev[110][110];
int ratea[110], rateb[110];

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

//        cout << prev[10][10];
//
//        cout << "INIT" << endl;
//        for(int i=0; i<=m; i++) {
//            for(int j=0; j<=m; j++) {
//                printf("%6d", prev[i][j]);
//            }
//            cout << endl;
//        }

//        for(int i=0; i<=m; i++) prev[0][i] = ratea[0]*i;
//        for(int i=0; i<=m; i++) prev[i][0] = rateb[0]*i;


        for(int i=0; i<n; i++) {
            for(int row=0; row<=m; row++) {
//                int rp = 0;
//                int cp = 0;
                for(int col=0; col<=m; col++) {
//                    int rp = 0;
//                    int cp = 0;
//                    while( rp < row && max( prev[ row-rp-1 ][ col ] , (rp+1)*ratea[i] ) <= max( prev[ row-rp ][ col ] , (rp)*ratea[i] ) ) rp++;
//                    while( cp < col && max( prev[ row ][ col-cp-1 ] , (cp+1)*rateb[i] ) <= max( prev[ row ][ col-cp ] , (cp)*rateb[i] ) ) cp++;

                    for(int rp=0; rp<=row; rp++) {
                        for(int cp=0; cp<=col; cp++) {
                            dp[row][col] = min( dp[row][col] , max( prev[ row-rp ][ col-cp ] , rp*ratea[i] + cp*rateb[i] ) ) ;
                        }
                    }

//                    dp[row][col] = min( dp[row][col] , min( max( prev[ row-rp ][ col ] , (rp)*ratea[i] ) , max( prev[ row ][ col-cp ] , (cp)*rateb[i] ) ) );
//                    cout << "AT " << row << ' ' << col << ' ' << rp << ' ' << cp << endl;
                }
            }

            for(int row=0; row<=m; row++)
                for(int col=0; col<=m; col++)
                    prev[row][col] = dp[row][col];

//            cout << "AFTER " << i << " TH MAN" << endl;
//            for(int i=0; i<=m; i++) {
//                for(int j=0; j<=m; j++) {
//                    printf("%6d", prev[i][j]);
//                }
//                cout << endl;
//            }
        }

        printf("Case %d: %d\n", t, prev[m][m]);
    }

    return 0;
}
