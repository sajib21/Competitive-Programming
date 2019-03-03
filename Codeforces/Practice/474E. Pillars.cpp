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
    ll x;
    int y,z;
    info() {x = y = z = 0;}
    info(ll xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        return x < b.x ;
    }
};
bool cmpx(info x, info y) {
    return x.x < y.x;
}
bool cmpy(info x, info y) {
    return x.y < y.y;
}

ll n,d;// segTree[4*LIM+10];
info h[LIM+100]; ll p=0;
info pnt[4*LIM+100];
map<ll,int>mp;

int par[LIM+100];
info segTree[10*LIM+100];

void update(int node, int st, int ed, int p, info v) {
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        segTree[node] = v;
        return;
    }
    segVar;
    update(lft, st,md, p, v); update(rgt, md+1,ed, p,v);
    segTree[node] = max(segTree[lft], segTree[rgt]);
}

info query(int node, int st, int ed, int l, int r) {
    if(l > r || ed < l || st > r) return info();
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    return max(query(lft, st,md, l,r) , query(rgt, md+1,ed, l,r));
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%I64d %I64d", &n,&d);
    for(int i=1; i<=n; i++) scanf("%I64d", &h[i].x);
    for(int i=1; i<=n; i++) {
        if(!mp[ h[i].x ]) { p++; pnt[p].x = h[i].x; pnt[p].y = p; mp[ h[i].x ] = 1; }
        if(h[i].x-d >= 0 && !mp[ h[i].x-d ]) { p++; pnt[p].x = h[i].x-d; pnt[p].y = p; mp[ h[i].x-d ] = 1; }
        if(!mp[ h[i].x+d ]) { p++; pnt[p].x = h[i].x+d; pnt[p].y = p; mp[ h[i].x+d ]=1; }
    }
    sort(pnt+1, pnt+p+1, cmpx);
    for(int i=1; i<=p; i++) mp[ pnt[i].x ] = i;
    for(int i=1; i<=n; i++) h[i].z = mp[ h[i].x ];
//    sort(pnt+1, pnt+n+1, cmpy);

//    for(int i=1; i<=p; i++) cout << pnt[i].x << ' ' ; cout << endl;
//    for(int i=1; i<=p; i++) cout << mp[ pnt[i].x ] << ' ' ; cout << endl;
//    for(int i=1; i<=n; i++) cout << h[i].x << ' ' ; cout << endl;
//    for(int i=1; i<=n; i++) cout << h[i].z << ' ' ; cout << endl;

    for(int i=1; i<=n; i++) {
        info ans,a,b;
        a = query(1, 1,p, 1,mp[ h[i].x-d ]) ;
        b = query(1, 1,p, mp[ h[i].x+d ], p);
        ans = max(a,b);
        ans.x++;
//        cout << "QRY IN " << 1 << ' ' << mp[ h[i].x-d ] << ' ' << a.x << ' ' << a.y << endl;
//        cout << "QRY IN " << mp[ h[i].x+d ] << ' ' << p << ' ' << b.x << ' ' << b.y << endl;
        par[i] = ans.y;
        ans.y = i;
//        cout << "UPDATING IN " << h[i].z << ' ' << ans.x << ' ' << ans.y << endl; getchar();
        update(1, 1,p, h[i].z, ans );
    }

    ll ans = segTree[1].x ; int last = segTree[1].y;
    stack<int>stk;
    while(last) {
//        cout << last << endl; getchar();
        stk.push(last);
        last = par[last];
    }

    printf("%I64d\n", ans);
    while(!stk.empty()) {
        printf("%d", stk.top());
        stk.pop();
        if(!stk.empty()) printf(" ");
    }
    printf("\n");

    return 0;
}
