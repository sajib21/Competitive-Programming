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

char a[101], b[101], c[101];
int as,bs,cs;
int dp[101][101][101][3];

//vector<char>vc;

ll getCnt(int in, int lft, int rgt, int con) {
//    cout << "INFO " << ' ' << lft << ' ' << rgt << ' ' << in << ' ' << con << endl; getchar();
    if(in == cs) {
//        for(int i=0; i<vc.size(); i++) cout << vc[i] ; cout << endl; //getchar();
        return 1;
    }
    if(lft == as && rgt == bs) return 0;
    if(dp[in][lft][rgt][con] != -1) return dp[in][lft][rgt][con];

    ll ans = 0;
    if(con != 1) {
        if(lft < as) {
            if(a[lft] == c[in]) {
//                vc.pb(a[lft]);
                ans = (ans + getCnt(in+1, lft+1, rgt, 0)) % MOD;
//                vc.pop_back();
            }
            ans = (ans + getCnt(in, lft+1, rgt, 2)) % MOD;
        }
    }
    if(con != 2){
        if(rgt < bs) {
            if(b[rgt] == c[in]) {
//                vc.pb(b[lft]-'a'+'A');
                ans = (ans + getCnt(in+1, lft, rgt+1, 0)) % MOD;
//                vc.pop_back();
            }
            ans = (ans + getCnt(in, lft, rgt+1, 1)) % MOD;
        }
    }
//    if(in == 0 && (lft || rgt)) cout << in << ' ' << lft << ' ' << rgt << ' ' << ans << endl;
    return dp[in][lft][rgt][con] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof dp);
//        memset(a, 0, sizeof a);
//        memset(b, 0, sizeof b);
//        memset(c, 0, sizeof c);
        scanf("%s %s %s", a, b, c);
        as = strlen(a); bs = strlen(b); cs = strlen(c);
//        bs = 0; as = 0; b[0] = b[1] = b[2] = a[0] = a[1] = a[2] = 0;
//        bs = 0; b[0] = b[1] = b[2] = 0;
//        as = 0;
//        a[0] = a[1] = 0; //b[1] = 0;
        printf("Case %d: %d\n", t, getCnt(0,0,0, 0));
    }

    return 0;
}
