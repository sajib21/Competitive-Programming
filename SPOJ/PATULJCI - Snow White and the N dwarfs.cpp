///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             300000
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
    int in,seg, x,y,z;
    info() {in = seg = x = y = z = 0;}
    info(int ii, int ss, int xx, int yy = 0, int zz = 0) {
        in = ii; seg = ss; x = xx; y = yy; z = zz;
    }
};
bool cmpx(info x, info y) {
    return (x.seg == y.seg && x.y < y.y) || x.seg < y.seg;
}
bool cmpy(info x, info y) {
    return x.in < y.in;
}

int n,c,seg,m, a[LIM+10];
int cnt[LIM/3 + 10];

info qry[LIM+10];

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d %d", &n,&c);
    seg = sqrt(n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &qry[i].x, &qry[i].y);
        qry[i].in = i;
        qry[i].seg = qry[i].x/seg;
    }
    sort(qry, qry+m, cmpx);

    int lft = 0, rgt = 0;
    for(int i=0; i<q; i++) {

    }

    return 0;
}
