///HEADERS
#include    <bits/stdtr1c++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100005
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

int r,g, mx;
unordered_map<int,int>h[200005];
bool vis[10100][10100];
int cnt = 0;

int f(int in, int red) {
//    cnt++;
    int green = in*(in+1)/2 - red;
    cout << "IN " << in+1 << ' ' << red << ' ' << green << ' ' << vis[in][red] << endl; getchar();
    vis[in][red] = 1;
    if(red > r || green > g) return INT_MIN;
    cnt++;
//    if(h[red].find(in) != h[red].end()) return h[red][in];
    return max( 0, max( 1+f(in+1,red+in+1), 1+f(in+1,red) ) );
}

int gg(int in, int red) {
    int green = in*(in+1)/2 - red;
    if(red > r || green > g) return 0;
    if(in == mx) return 1;
//    if(h[red].find(in) != h[red].end()) return h[red][in];
    return (gg(in+1,red+in+1) + gg(in+1,red))%MOD ;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d %d", &r,&g);
//    memset(h, -1, sizeof h);

    cout << f(0,0) << endl;
    cout << cnt << endl;
//    mx = f(0, 0); //cout << mx << endl;
////    memset(h, -1, sizeof h);
//    for(int i=0; i<=200000; i++) h[i].clear();
//
//    printf("%d\n", gg(0, 0));

    return 0;
}
