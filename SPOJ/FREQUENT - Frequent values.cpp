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
    int x,y,z; ///prefix,suffix,best
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

int n,q, ara[LIM+100];
info segTree[4*LIM+100];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = info(1,1,1);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt,md+1,ed);

    segTree[node].z = max( segTree[lft].z , segTree[rgt].z ) ;
    segTree[node].x = segTree[lft].x; segTree[node].y = segTree[rgt].y;

    if(ara[md] == ara[md+1]) {
        segTree[node].z = max( segTree[lft].y+segTree[rgt].x , segTree[node].z );
        if(ara[st] == ara[md]) segTree[node].x += segTree[rgt].x;
        if(ara[ed] == ara[md]) segTree[node].y += segTree[lft].y;
    }
}

info query(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return info(0,0,0);
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    info q1,q2, ans;
    q1 = query(lft, st,md, l,r);
    q2 = query(rgt, md+1,ed, l,r);

    if(md < l) return q2;
    if(md >= r) return q1;

    ans.z = max( q1.z , q2.z ) ;
    ans.x = q1.x; ans.y = q2.y;

    if(ara[md] == ara[md+1]) {
        ans.z = max( q1.y+q2.x , ans.z );
        if(ara[st] == ara[md]) ans.x += q2.x;
        if(ara[ed] == ara[md]) ans.y += q1.y;
    }
    return ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
//    scanf("%d", &T);
    for(int t=1; ; t++) {
        scanf("%d", &n); if(!n) return 0;
        scanf("%d", &q);
        for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
        init(1, 1,n);

        while(q--) {
            int l,r;
            scanf("%d %d", &l,&r);
            printf("%d\n", query(1, 1,n, l,r).z );
        }
    }

    return 0;
}
