#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2

using namespace std;

int n,m, a[LIM];
int segTree[4*LIM];
ll sumTree[4*LIM];

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = sumTree[node] = a[st];
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = max(segTree[lft], segTree[rgt]);
    sumTree[node] = sumTree[lft] + sumTree[rgt];
}

void update1(int node, int st, int ed, int l, int r, int x) {
    if(ed < l || st > r || segTree[node] < x) return;
    if(st == ed) {
        segTree[node] %= x;
        sumTree[node] %= x;
        return;
    }
    segVar;
    update1(lft, st,md, l,r, x);
    update1(rgt, md+1,ed, l,r, x);
    segTree[node] = max(segTree[lft], segTree[rgt]);
    sumTree[node] = sumTree[lft] + sumTree[rgt];
}

void update2(int node, int st, int ed, int p, int x) {
    if(ed < p || st > p) return;
    if(st == p && ed == p) {
        segTree[node] = sumTree[node] = x;
        return;
    }
    segVar;
    update2(lft, st,md, p, x); update2(rgt, md+1,ed, p, x);
    segTree[node] = max(segTree[lft], segTree[rgt]);
    sumTree[node] = sumTree[lft] + sumTree[rgt];
}

ll query(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return sumTree[node];
    segVar;
    return query(lft, st,md, l,r) + query(rgt, md+1,ed, l,r);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    init(1, 1,n);

    while(m--) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int l,r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(1, 1,n, l,r));
        }
        else if(t == 2) {
            int l,r,x;
            scanf("%d %d %d", &l, &r, &x);
            update1(1, 1,n, l,r, x);
        }
        else {
            int p,x;
            scanf("%d %d", &p,&x);
            update2(1, 1,n, p, x);
        }
    }
}
