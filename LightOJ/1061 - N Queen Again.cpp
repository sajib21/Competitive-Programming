
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

struct info{
    int x,y,z;
    info() {}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};

bool col[10], diagl[30], diagr[30];
int pat[10];
vector<vii>valid;

void getQueen(int r) {
    if(r == 8) {
        vii ans;
        for(int i=0; i<8; i++) ans.pb(pat[i]);
        valid.pb(ans);
        return;
    }

    for(int c=0; c<8; c++) {
        if(col[c] || diagl[r+c] || diagr[r+7-c]) continue;
        col[c] = diagl[r+c] = diagr[r+7-c] = 1;
        pat[r] = c;
        getQueen(r+1);
        col[c] = diagl[r+c] = diagr[r+7-c] = 0;
    }
}

char grid[10][10];
vector<info>seq;
int v, dp[1 << 8];

int getMin(int in, int mask) {
    if(in == 8) {
        return 0;
    }
    if(dp[mask] != -1) return dp[mask];
    int ans = INT_MAX;
    for(int i=0; i<8; i++) {
        if(chkBit(mask, i)) continue;
        if(seq[in].x == i && seq[in].y == valid[v][i]) ans = min(ans, getMin(in+1, setBit(mask, i)));
        else if(seq[in].x == i || seq[in].y == valid[v][i] || abs(seq[in].x-i) == abs(seq[in].y-valid[v][i]) ) ans = min(ans, 1+getMin(in+1, setBit(mask, i)));
        else ans = min(ans, 2+getMin(in+1, setBit(mask, i)));
    }
    return dp[mask] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    getQueen(0);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        seq.clear();
        for(int i=0; i<8; i++) scanf("%s", grid[i]);

        for(int i=0; i<8; i++) for(int j=0; j<8; j++) if(grid[i][j] == 'q') seq.pb(info(i,j));

        int ans = INT_MAX;
        for(v=0; v<valid.size(); v++) {
            memset(dp, -1, sizeof(dp));
            int tmp = getMin(0,0);
            ans = min(ans, tmp);
        }
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
