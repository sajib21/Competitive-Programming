///USED UPDATE IN QUERY

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
    int x,y,z;
    info() {}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};
bool cmpx(info x, info y) {
    return x.x < y.x;
}

int n,q;
info seg[LIM+10], qry[LIM+10];
int pnt[4*LIM+10];
map<int,int>mp;
int flag[4*LIM+10];

info segTree[16*LIM+10];

void update(int node, int st, int ed, int l, int r, int prop = 0) {
    segTree[node].x += prop;
    segTree[node].y += prop;
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node].x++;
        segTree[node].y++;
        return;
    }
    segVar;
    update(lft, st, md, l,r, segTree[node].y); update(rgt, md+1,ed, l,r, segTree[node].y);
    segTree[node].x = max(segTree[lft].x, segTree[rgt].x);
    segTree[node].y = 0;
}

int query(int node, int st, int ed, int l, int r, int prop=0) {
    segTree[node].x += prop;
    segTree[node].y += prop;
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node].x;
    segVar;
    int ans =  max( query(lft, st,md, l,r, segTree[node].y) , query(rgt, md+1,ed, l,r, segTree[node].y) );
    segTree[node].y = 0;
    return ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d", &n);
    int j=0;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &seg[i].x, &seg[i].y);
        pnt[j++] = seg[i].x; pnt[j++] = seg[i].y;
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        int a,b;
        scanf("%d %d", &qry[i].x, &qry[i].y);
        pnt[j++] = qry[i].x; pnt[j++] = qry[i].y;
    }

    sort(pnt, pnt+j, cmpx);
    int i=1;
    for(int k=1; i<j && k<j; k++) if(pnt[k] != pnt[k-1]) pnt[i++] = pnt[k];
    j = i;
    for(int i=0; i<j; i++) mp[ pnt[i] ] = i+1;
    for(int i=0; i<n; i++) seg[i].x = mp[ seg[i].x ] , seg[i].y = mp[ seg[i].y ];
    for(int i=0; i<q; i++) qry[i].x = mp[ qry[i].x ] , qry[i].y = mp[ qry[i].y ];

    for(int i=0; i<n; i++) {
//        cout << "BUG " << seg[i].x << ' ' << seg[i].y << endl;
        update(1, 1,j, seg[i].x, seg[i].y);
    }

    for(int i=0; i<q; i++) {
        printf("%d\n", query(1, 1,j, qry[i].x, qry[i].y));
    }




    return 0;
}
