#include<bits/stdc++.h>
#define LIM 250005
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
#define ll long long int

using namespace std;

struct info {
    ll x, y, z; ///x = sum; y = propval; z = propcnt;
    info() {}
    info(ll xx, ll yy, ll zz = 0) {
        x = xx; y = yy; z = zz;
    }
};

int n,m, a[LIM];
info segTree[4*LIM];

void pushDown1(int node, int st, int ed);
void pushDown2(int node, int st, int ed);
void pushDown3(int node, int st, int ed);

void adjust(int node, ll a, ll n, ll d, ll t) {
    if(t == 3) segTree[node].x = 0;
    segTree[node].x += n * (2*a + (n-1)*d) / 2; ///arith series sum
    segTree[node].y = a;
    segTree[node].z = t;
    return;
}

void pushDown1(int node, int st, int ed) {
    segVar;
    ll a = segTree[node].y;
    ll n;

    segTree[node].y = segTree[node].z = 0;

    if(st == ed) return;

    ///lft
    if(segTree[lft].z == 1) pushDown1(lft, st, md);
    if(segTree[lft].z == 2) pushDown2(lft, st, md);
    if(segTree[lft].z == 3) pushDown3(lft, st, md);
    n = md-st+1;
    adjust(lft, a, n, 1, 1);

    ///rgt
    if(segTree[rgt].z == 1) pushDown1(rgt, md+1, ed);
    if(segTree[rgt].z == 2) pushDown2(rgt, md+1, ed);
    if(segTree[rgt].z == 3) pushDown3(rgt, md+1, ed);
    a += n;
    n = ed-md;
    adjust(rgt, a, n, 1, 1);
}

void pushDown2(int node, int st, int ed) {
    segVar;
    ll a = segTree[node].y;
    ll n;

    segTree[node].y = segTree[node].z = 0;

    if(st == ed) return;

    ///rgt
    if(segTree[rgt].z == 1) pushDown1(rgt, md+1, ed);
    if(segTree[rgt].z == 2) pushDown2(rgt, md+1, ed);
    if(segTree[rgt].z == 3) pushDown3(rgt, md+1, ed);
    n = ed-md;
    adjust(rgt, a, n, 1, 2);

    ///lft
    if(segTree[lft].z == 1) pushDown1(lft, st, md);
    if(segTree[lft].z == 2) pushDown2(lft, st, md);
    if(segTree[lft].z == 3) pushDown3(lft, st, md);
    a += n;
    n = md-st+1;
    adjust(lft, a, n, 1, 2);
}

void pushDown3(int node, int st, int ed) {
    segVar;
    ll a = segTree[node].y;
    ll n;

    segTree[node].y = segTree[node].z = 0;

    if(st == ed) return;

    ///rgt
    if(segTree[rgt].z == 1) pushDown1(rgt, md+1, ed);
    if(segTree[rgt].z == 2) pushDown2(rgt, md+1, ed);
    if(segTree[rgt].z == 3) pushDown3(rgt, md+1, ed);
    n = ed-md;
    adjust(rgt, a, n, 0, 3);

    ///lft
    if(segTree[lft].z == 1) pushDown1(lft, st, md);
    if(segTree[lft].z == 2) pushDown2(lft, st, md);
    if(segTree[lft].z == 3) pushDown3(lft, st, md);
    n = md-st+1;
    adjust(lft, a, n, 0, 3);
}

void update1(int node, int st, int ed, int l, int r) {
    if(segTree[node].z == 1) pushDown1(node, st, ed);
    if(segTree[node].z == 2) pushDown2(node, st, ed);
    if(segTree[node].z == 3) pushDown3(node, st, ed);

    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        ll a = st-l+1;
        ll n = (ed-st+1);
        adjust(node, a, n, 1, 1);
        return;
    }
    segVar;
    update1(lft, st,md, l,r); update1(rgt, md+1,ed, l,r);
    segTree[node].x = segTree[lft].x + segTree[rgt].x;
}

void update2(int node, int st, int ed, int l, int r) {
    if(segTree[node].z == 1) pushDown1(node, st, ed);
    if(segTree[node].z == 2) pushDown2(node, st, ed);
    if(segTree[node].z == 3) pushDown3(node, st, ed);

    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        ll a = r-ed+1;
        ll n = (ed-st+1);
        adjust(node, a, n, 1, 2);
        return;
    }
    segVar;
    update2(lft, st,md, l,r); update2(rgt, md+1,ed, l,r);
    segTree[node].x = segTree[lft].x + segTree[rgt].x;
}

void update3(int node, int st, int ed, int l, int r, int v) {
    if(segTree[node].z == 1) pushDown1(node, st, ed);
    if(segTree[node].z == 2) pushDown2(node, st, ed);
    if(segTree[node].z == 3) pushDown3(node, st, ed);

    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        ll a = v;
        ll n = (ed-st+1);
        adjust(node, a, n, 0, 3);
        return;
    }
    segVar;
    update3(lft, st,md, l,r, v); update3(rgt, md+1,ed, l,r, v);
    segTree[node].x = segTree[lft].x + segTree[rgt].x;
}

ll query(int node, int st, int ed, int l, int r) {
    if(segTree[node].z == 1) pushDown1(node, st, ed);
    if(segTree[node].z == 2) pushDown2(node, st, ed);
    if(segTree[node].z == 3) pushDown3(node, st, ed);

    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node].x;
    segVar;
    return query(lft, st,md, l,r) + query(rgt, md+1,ed, l,r);
}

int main() {
//    freopen("1411o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &m);
        n = 25000;
        memset(segTree, 0, sizeof segTree);

        printf("Case %d:\n", t);

        char s[4]; int st, ed, v;

        while(m--) {
            scanf("%s", s);
            if(s[0] == 'x') break;
            if(s[0] == 'A') {
                scanf("%d %d", &st, &ed);
                update1(1, 1,n, st,ed);
            }
            else if(s[0] == 'B') {
                scanf("%d %d", &st, &ed);
                update2(1, 1,n, st,ed);
            }
            else if(s[0] == 'C') {
                scanf("%d %d %d", &st, &ed, &v);
                update3(1, 1,n, st,ed, v);
            }
            else {
                scanf("%d %d", &st, &ed);
                printf("%lld\n", query(1, 1,n, st, ed));
            }
        }
    }
}
