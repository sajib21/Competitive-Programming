///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     100000
#define     MOD     1000000007
#define     MAX     10000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

struct info{
    ll x,y,z;
    info() {x = -1; y = -1; z = -1;}
    info(ll xx, ll yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};

int n,q;
ll ara[LIM+10];
info segTree[4*LIM+10];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node].x = ara[st];
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1, ed);
    if(segTree[lft].x > segTree[rgt].x) {
        segTree[node].x = segTree[lft].x;
        segTree[node].y = max(segTree[lft].y, segTree[rgt].x);
    }
    else {
        segTree[node].x = segTree[rgt].x;
        segTree[node].y = max(segTree[lft].x, segTree[rgt].y);
    }
}
void update(int node, int st, int ed, int p, ll v) {
    if(ed < p || st > p) return;
    if(st >= p && ed <= p) {
        segTree[node].x = v;
        return;
    }
    segVar;
    update(lft, st,md, p,v); update(rgt, md+1, ed, p,v);
    if(segTree[lft].x > segTree[rgt].x) {
        segTree[node].x = segTree[lft].x;
        segTree[node].y = max(segTree[lft].y, segTree[rgt].x);
    }
    else {
        segTree[node].x = segTree[rgt].x;
        segTree[node].y = max(segTree[lft].x, segTree[rgt].y);
    }
}

info query(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return info();
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    info q1,q2, ans;
    q1 = query(lft, st,md, l,r); q2 = query(rgt, md+1, ed, l,r);
    if(q1.x > q2.x) {
        ans.x = q1.x;
        ans.y = max(q1.y, q2.x);
    }
    else {
        ans.x = q2.x;
        ans.y = max(q1.x, q2.y);
    }
    return ans;
}


int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &ara[i]);
    init(1, 1,n);
    scanf("%d", &q);
    while(q--) {
        getchar();
        char c;
        int x; ll y;
        scanf("%c %d %lld", &c, &x,&y);
        if(c == 'U') update(1, 1,n, x, y);
        else {
            info qry = query(1, 1,n, x,y);
            printf("%lld\n", qry.x+qry.y);
        }
    }


    return 0;
}

