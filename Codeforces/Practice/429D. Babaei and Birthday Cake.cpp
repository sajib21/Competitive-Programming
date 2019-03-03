#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int
#define pi acos(-1)
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
#define EPS 1e-9

using namespace std;

struct info {
    int r,h, x,y; /// x=id, y=sorted id
    ll a;
    info() {}
    info(int rr, int hh, int xx, int yy=0) {
        r = rr; h = hh; x = xx; y = yy;
        a = 1LL*r*r*h;
    }
    double area() {
        return pi*r*r*h;
    }
};

bool cmpx(info a, info b) {
    return a.x < b.x;
}
bool cmpv(info a, info b) {
    return a.a < b.a;
}

int n;
info a[LIM];
double segTree[4*LIM];

double query(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return 0.0;
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    return max( query(lft, st,md, l,r) , query(rgt, md+1,ed, l,r) ) ;
}

void update(int node, int st, int ed, int p, double v) {
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        segTree[node] = max(v, segTree[node]);
        return;
    }
    segVar;
    update(lft, st,md, p, v); update(rgt, md+1,ed, p, v);
    segTree[node] = max(segTree[lft], segTree[rgt]);
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d %d", &a[i].r, &a[i].h);
        a[i].x = i;
        a[i].a = 1LL * a[i].r * a[i].r * a[i].h;
//        cout << a[i].area() << endl;
    }
    sort(a+1, a+n+1, cmpv);

    int in = 0;
    for(int i=1; i<=n; i++) {
        if(a[i].a > a[i-1].a) {
            a[i].y = ++in;
        }
        else a[i].y = in;
    }
//    for(int i=1; i<=n; i++) cout << a[i].x << ' ' ; cout << endl;
    sort(a+1, a+n+1, cmpx);

//    for(int i=1; i<=n; i++) cout << a[i].y << ' ' ; cout << endl;

    for(int i=1; i<=n; i++) {
        int st = 0, ed = a[i].y-1;
        double cur = query(1, 0,in, st,ed);
        update(1, 0,in, a[i].y, cur+a[i].area());
    }

    printf("%.8f\n", segTree[1]);
}
