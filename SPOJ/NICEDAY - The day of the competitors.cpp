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

info rnk[LIM+100];
info segTree[4*LIM+10];

info mini(info a, info b) {
    return info( min(a.x,b.x), min(a.y,b.y), min(a.z,b.z) );
}

info init(int node, int st, int ed) {
    if(st == ed) return segTree[node] = rnk[st];
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    return segTree[node] = mini(segTree[lft], segTree[rgt]);
}

int bs(int x) {
    int lo = 1, hi = n+1, md;
    while(lo < hi) {
        md = (lo+hi) >> 1;
        if(rnk[md].x < x) hi = md;
        else lo = md+1;
    }
    return lo;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int p=0; p<3; p++) for(int i=1; i<=n; i++) scanf("%d", &a[p][i]);
        for(int i=1; i<=n; i++) rnk[i] = info(a[0][i], a[1][i], [2][i]);
        sort(rnk+1, rnk+n+1, cmpx);
        init(1, 1,n);

        for(int i=1; i<=n; i++) {
            int pos = bs(a[0][i]);

        }
    }

    return 0;
}
