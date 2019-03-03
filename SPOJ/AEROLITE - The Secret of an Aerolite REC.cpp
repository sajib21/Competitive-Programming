///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             11380
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

int l1, l2,l3, D;
int dp[11][11][11][33][3];

int f(int a, int b, int c, int d, int con) {
//    if(!d) return 0;
//    cout << "IN  " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << con << endl; getchar();
    if(!a && !b && !c && !d) return 1;
    if(!a && !b && !c) return 0;
    if(!d) return 0;
    if(dp[a][b][c][d][con] != -1) return dp[a][b][c][d][con];
    int ans = 0;

//    cout << "KAM SHURU " << endl;

    if(a && d && con < 1) ans += f(a-1,b,c,d-1, 0);
    if(b && d && con < 2) ans += f(a,b-1,c,d-1, 1);
    if(c && d) ans += f(a,b,c-1,d-1, 2);

    for(int i=a; i>=0; i--) {
        for(int j=b; j>=0; j--) {
            for(int k=c; k>=0; k--) {
                if(i == a && j == b && k == c) continue;
                if(a-i == a && b-j == b && c-k == c) continue;
//                cout << "CALLER  " << a << ' ' << b << ' ' << c << ' ' << d << endl;
//                cout << "CALLING " << i << ' ' << j << ' ' << k << ' ' << d << endl;
//                cout << "CALLING " << a-i << ' ' << b-j << ' ' << c-k << ' ' << d << endl; getchar();
                int ta,tb;
                ta = f(i,j,k, d, con);
                tb = f(a-i,b-j,c-k, d, con);
                ans += ta*tb;
            }
        }
    }
//    cout << "OUT " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << con << endl; getchar();
    return dp[a][b][c][d][con] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    memset(dp, -1, sizeof dp);

    int T;
//    scanf("%d", &T);
    T = 10;
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d %d", &l1,&l2,&l3,&D);
        printf("%d\n", f(l1, l2, l3, D, 0));
    }

    while(1) {
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        cout << dp[a][b][c][d][e] << endl;
    }

    return 0;
}
