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
#define     pll             pair<ll,ll>
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

///BITMASK
int setBit(int mask, int pos) { return mask  (1 << pos) ; } int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

///DIRECTION ARRAY
/*


int dirR[] = {+1, +2, +2, +1, -1, -2, -2, -1} ;
int dirC[] = {+2, +1, -1, -2, -2, -1, +1, +2} ;

*/

int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};

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

void printBin(int n) { if(!n) return; printBin(n>>1); cout << n%2; }

int nm grid[17][17], masks[17];
int dp[17][1 << 16];

int f(int in, int premask) {
    if(in == n) return 0;
    if(dp[in][premask] != -1) return dp[in][premask];

    int curmask = masks[in], nxtmask = masks[in+1];
    int maskmat[3] = {premask, curmask, nxtmask};



}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &grid[i][j]);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                masks[i] = masks[i]*2 + grid[i][j];
            }
        }

        int ans = f(0,0);
        cout << ans << endl;

    }

    return 0;
}

/*
tokenize
string str = strr;
//            cout << str << endl;

            stringstream ss(str);
            int ans = 1;
            while (ss >> str)

            */

