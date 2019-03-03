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
#define     ff              first
#define     ss              second
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

pii f(int in, int red, int green) {
    cnt++;
    pii ans = pii(0,1);
    if(red+in <= r) {
        pii temp = f(in+1, red+in, green); temp.ff++;
        if(temp.ff == ans.ff) ans.ss += temp.ss;
        if(temp.ff > ans.ff)  ans = temp;
    }
    if(green+in <= g) {
        pii temp = f(in+1, red, green+in); temp.ff++;
        if(temp.ff == ans.ff) ans.ss += temp.ss;
        if(temp.ff > ans.ff)  ans = temp;
    }
    return ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d %d", &r,&g);
//    memset(h, -1, sizeof h);

    pii ans = f(1, 0,0);
    cout << ans.ff << ' ' << ans.ss << endl;
    cout << cnt << endl;
//    mx = f(0, 0); //cout << mx << endl;
////    memset(h, -1, sizeof h);
//    for(int i=0; i<=200000; i++) h[i].clear();
//
//    printf("%d\n", gg(0, 0));

    return 0;
}
