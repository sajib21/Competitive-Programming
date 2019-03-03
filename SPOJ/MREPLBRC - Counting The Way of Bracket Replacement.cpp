///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             100000
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

int n;
char str[303];
ll dp[213][213];
bool boro = false;

bool chk(char a, char b) {
    return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']') || (a=='?' && b=='?') ||
        ((a=='(' || a=='{' || a =='[') && b=='?') || (a=='?' && (b==')' || b=='}' || b==']'));
}

ll ff(int l, int r) {
//    cout << l << ' ' << r << endl; getchar();
    if(l > r) return 1;
//    if(str[l] == ')' || str[r] == '(') return 0;
    if(dp[l][r] != -1) return dp[l][r];

    ll ans = 0;
    for(int i=l+1; i<=r; i+=2) if(chk(str[l], str[i])) {
//        cout << "IN " << ' ' << l << ' ' << r << ' ' << i << endl; getchar();
        int t = 1; if(str[l] == '?' && str[i] == '?') t = 3;
        ans += t*ff(l+1,i-1)*ff(i+1,r);
        if(ans >= MOD) {
            boro = true;
            ans %= MOD;
        }
    }
//    cout << "FROM " << l << ' ' << r << ' ' << ans << endl; getchar();
    return dp[l][r] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    memset(dp, -1, sizeof dp);

//    cout << chk( '(', ')' ) << ' ' << chk( '?', ')' ) << endl;

    scanf("%d", &n);
    scanf("%s", &str);
    ll ans = ff(0, n-1);
    if(boro) printf("%05lld\n", ans );
    else printf("%lld\n", ans);

    return 0;
}
