#include<bits/stdc++.h>
#define LIM 1000006
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

using namespace std;

int n, a[LIM], q, segTree[LIM*4];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = a[st];
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1, ed);
    segTree[node] = __gcd(segTree[lft], segTree[rgt]);
}

void update(int node, int st, int ed, int p, int v) {
//    cout << node << ' ' << st << ' ' << ed << ' ' << p << ' ' << v << endl; getchar();
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        segTree[node] = v;
//        cout << "UPed " << node << ' ' << st << ' ' << ed << ' ' << segTree[node] << endl; getchar();
        return;
    }
    segVar;
    update(lft, st,md, p,v); update(rgt, md+1,ed , p , v);
    segTree[node] = __gcd(segTree[lft], segTree[rgt]);
//    cout << "UP " << node << ' ' << st << ' ' << ed << ' ' << segTree[node] << endl; getchar();

}

int query(int node, int st, int ed, int l, int r, int x, int c = 0) {
    if(ed < l || st > r) return 0;
//    cout << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << x << ' ' << c << ' ' << segTree[node] << endl; getchar();
    if(st >= l && ed <= r) {
        if(segTree[node]%x == 0) return 0;
        else c = 1;
        if(st == ed) return 1;
    }
    segVar;
    int a = 0,b = 0;
    a = query(lft, st,md, l,r,x, c);
    if(a < 2) b = query(rgt, md+1,ed, l,r,x, c);
//    cout << "OUT " << node << ' ' << a+b << endl; getchar();
    return a+b;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    init(1, 1,n);
    scanf("%d", &q);
    while(q--) {
        int c, x,y,z;
        scanf("%d", &c);
        if(c == 1) {
            scanf("%d %d %d", &x,&y,&z);
            if(query(1, 1,n, x,y, z) < 2) printf("YES\n");
            else printf("NO\n");
        }
        else {
            scanf("%d %d", &x,&y);
            update(1, 1,n, x,y);
        }
    }
}
