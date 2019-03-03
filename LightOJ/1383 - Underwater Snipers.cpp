///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             10000
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
    ll x,y,z;
    info() {x = y = z = 0;}
    info(ll xx, ll yy = 0, ll zz = 0) {
        x = xx; y = yy; z = zz;
    }
};
bool cmpx(info x, info y) {
    return x.x < y.x;
}
bool cmpy(info x, info y) {
    return x.y < y.y;
}

int k,n,s; ll d;
info pt[LIM+10];

bool f(int y) {
    int p;
    ll x;
    int cnt=1;

    p = 0;
    if(pt[p].y - y > d) return false;
    x = sqrt(sqr(d) - sqr(y-pt[p].y) ) + pt[p].x;
//    if(y == 76905597) cout << "INX " << y << ' ' << p << ' ' << x << endl;

    while(p < n) {
        if(pt[p].y - y > d ) return false;
        if( -sqrt(sqr(d) - sqr(y-pt[p].y) ) + pt[p].x  > x) {
            cnt++;
            x = sqrt(sqr(d) - sqr(y-pt[p].y) ) - pt[p].x;
        }
        else {
            ll tt = sqrt(sqr(d) - sqr(y-pt[p].y) ) + pt[p].x;
            x = min( x, tt );
        }
//        if(y == 76905597) cout << "IN " << y << ' ' << p << ' ' << x << ' ' << cnt << endl;
        p++;
    }
//    if(y == 76905597) {cout << "FROM " << y << ' ' << cnt << endl; getchar();}
    return cnt <= s;
}

int bs() {
    ll lo = LONG_LONG_MIN, hi = k, md;
    for(int i=0; i<50; i++) {
        md = (lo+hi) >> 1;
//        cout << "CHK " << lo << ' ' << hi << endl; getchar();
        if(f(md)) hi = md;
        else lo = md+1;
    }
    return hi;
}

int main() {

//    freopen("1383i.txt", "r", stdin);
//    freopen("1383o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d %lld", &k,&n,&s,&d);
        for(int i=0; i<n; i++) scanf("%lld %lld",&pt[i].x, &pt[i].y);
        sort(pt, pt+n, cmpx);
//        cout << "BUG" << endl;
        int ans = bs();
        if(ans == k) printf("Case %d: impossible\n", t);
        else printf("Case %d: %d\n", t, k-ans);
    }

    return 0;
}
