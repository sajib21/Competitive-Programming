#include<bits/stdc++.h>
#define LIM 1000006
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

struct info{
    int x;
    int lft, rgt;
    info() {x = lft = rgt = 0;}

};

int NODES = 0;
int n, a[LIM], m, x,y,k;
vi num;

int root[LIM];
info segTree[LIM*20];

void update(int node, int pre, int st, int ed, int p) {
    segTree[node] = segTree[pre];
    if(st == p && ed == p) {
        segTree[node].x++;
        return;
    }
    int lft=segTree[node].lft, rgt=segTree[node].rgt, md = (st+ed) / 2;
    if(p <= md) {
        lft = segTree[node].lft = ++NODES;
        update(segTree[node].lft, segTree[pre].lft, st,md, p);
    }
    else {
        rgt = segTree[node].rgt = ++NODES;
        update(segTree[node].rgt, segTree[pre].rgt, md+1,ed, p);
    }
    lft=segTree[node].lft, rgt=segTree[node].rgt;
    segTree[node].x = segTree[lft].x + segTree[rgt].x;
}

int query(int node, int pre, int st, int ed, int k) {
    if(st == ed) return st;
    int lft,rgt, md = (st+ed) / 2;
    int a = segTree[node].lft, b = segTree[pre].lft;
    int v = segTree[a].x - segTree[b].x;
    if(k <= v) return query(a, b, st,md, k);
    else       return query(segTree[node].rgt, segTree[pre].rgt, md+1,ed, k-v);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        num.pb(a[i]);
    }
    sort(all(num));
    for(int i=1; i<=n; i++) a[i] = lower_bound(all(num), a[i]) - num.begin() + 1;

    for(int i=1; i<=n; i++) {
        root[i] = ++NODES;
        update(root[i], root[i-1], 1, n, a[i]);
    }

    while(m--) {
        scanf("%d %d %d", &x,&y,&k);
        int v = query(root[y], root[x-1], 1,n, k);
        printf("%d\n", num[ v-1 ] );
    }
}
