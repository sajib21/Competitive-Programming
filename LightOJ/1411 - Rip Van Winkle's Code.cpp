#include<bits/stdc++.h>
#define LIM 250005
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
#define ll long long int

using namespace std;

struct info {
    ll x, y, z; int p; ///x = sum; y = propval; z = propcnt;
    info() { x = y = z = p = 0;}
    info(ll xx, ll yy, ll zz = 0, int pp = 0) {
        x = xx; y = yy; z = zz;
    }
};

int n,m, a[LIM];
info segTree[4*LIM];

void adjust(int node, ll a, ll n, ll d) {
    segTree[node].x += n * (2*a + (n-1)*d) / 2; ///arith series sum
    segTree[node].y += a;
    segTree[node].z += d;
    return;
}

void pushDown(int node, int st, int ed) {
    segVar;
    ll a = segTree[node].y;
    ll d = segTree[node].z;
    ll n;

    segTree[node].y = segTree[node].z = 0;

    if(st == ed) return;

    ///lft
    n = md-st+1;
    adjust(lft, a, n, d);

    ///rgt
    a += n*d;
    n = ed-md;
    adjust(rgt, a, n, d);
}

void update(int node, int st, int ed, int l, int r, ll a, ll d) {
    segVar;
    if(segTree[node].p && st != ed) {
        segTree[lft] = segTree[rgt] = info();
        segTree[lft].p = segTree[rgt].p = 1;
        segTree[node].p = 0;
    }
    pushDown(node, st, ed);

    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        a = a + (st-l)*d;
        ll n = (ed-st+1);
        adjust(node, a, n, d);
        return;
    }
    update(lft, st,md, l,r, a, d); update(rgt, md+1,ed, l,r, a, d);
    segTree[node].x = segTree[lft].x + segTree[rgt].x;
}

void update3(int node, int st, int ed, int l, int r, int p) {
    segVar;
    if(segTree[node].p && st != ed) {
        segTree[lft] = segTree[rgt] = info();
        segTree[lft].p = segTree[rgt].p = 1;
        segTree[node].p = 0;
    }
    pushDown(node, st, ed);

    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node] = info();
        segTree[node].p = 1;
        return;
    }

    update3(lft, st,md, l,r, p); update3(rgt, md+1,ed, l,r, p);
    segTree[node].x = segTree[lft].x + segTree[rgt].x;
}

ll query(int node, int st, int ed, int l, int r) {
    segVar;
    if(segTree[node].p && st != ed) {
        segTree[lft] = segTree[rgt] = info();
        segTree[lft].p = segTree[rgt].p = 1;
        segTree[node].p = 0;
    }
    if(segTree[node].y) pushDown(node, st, ed);

    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node].x;
    return query(lft, st,md, l,r) + query(rgt, md+1,ed, l,r);
}

int main() {
//    freopen("1411i.txt", "r", stdin);
//    freopen("1411o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &m);
        n = 250000;
//        n = 4;
        memset(segTree, 0, sizeof segTree);

        printf("Case %d:\n", t);

        char s[4]; int st, ed, v;

        while(m--) {
            scanf("%s", s);
            if(s[0] == 'x') break;
            if(s[0] == 'A') {
                scanf("%d %d", &st, &ed);
                update(1, 1,n, st,ed, 1, 1);
            }
            else if(s[0] == 'B') {
                scanf("%d %d", &st, &ed);
                update(1, 1,n, st,ed, (ed-st+1), -1);
            }
            else if(s[0] == 'C') {
                scanf("%d %d %d", &st, &ed, &v);
                update3(1, 1,n, st,ed, 1);
                update(1, 1,n, st,ed, v, 0);
            }
            else {
                scanf("%d %d", &st, &ed);
                printf("%lld\n", query(1, 1,n, st, ed));
            }
//            cout << "FIN" << endl;
//            for(int i=1; i<=16; i++) cout << i << ' ' << segTree[i].x << ' ' << segTree[i].y << ' ' << segTree[i].z << ' ' << segTree[i].p << endl;


        }
    }
}
