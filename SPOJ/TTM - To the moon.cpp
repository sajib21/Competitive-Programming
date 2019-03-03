#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int
#define segVar int lft = ++NODES, rgt = ++NODES, md = (st+ed)/2
using namespace std;

struct info{
    int x,y; ll z, p;
    info() {}
    info(int xx, int yy, ll zz, ll pp = 0) { x = xx; y = yy; z = zz; p = pp; }
};

int n,m, a[LIM], NODES,TIMES, root[LIM];
info tree[40*LIM];

int init(int st, int ed) {
    int node = ++NODES;
    if(st == ed) {
        tree[node].z = a[st];
        return node;
    }
    int lft,rgt, md = (st+ed)/2;
    lft = init(st,md);
    rgt = init(md+1,ed);
    tree[node] = info(lft, rgt, tree[lft].z+tree[rgt].z );
    return node;
}

void pushdown(int node, int st, int ed) {
    if(tree[node].p) {
        int lft,rgt, md = (st+ed)/2, p = tree[node].p;
        lft = ++NODES; rgt = ++NODES;
        tree[node].x = lft, tree[node].y = rgt;

        tree[lft] = tree[ tree[node].x ];
        tree[lft].z += (md-st+1)*p; tree[lft].p += p;
        tree[rgt] = tree[ tree[node].y ];
        tree[rgt].z += (ed-md)*p; tree[rgt].p += p;

        tree[node].p = 0;
    }
}

int update(int pre, int st, int ed, int l, int r, int d) {
//    cout << pre << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << d << endl;
//    getchar();


    int node = ++NODES;

    if(st == l && ed == r) {
        tree[node] = tree[pre];
        tree[node].z += (r-l+1)*d;
        tree[node].p += d;
        return node;
    }
    pushdown(pre, st,ed);

    int lft = tree[pre].x, rgt = tree[pre].y, md = (st+ed)/2;
//    tree[node] = tree[pre];
    if(r <= md) lft = update(tree[pre].x, st,md, l,r, d);
    else if(md <  l) rgt = update(tree[pre].y, md+1,ed,l,r,d);
    else {
        lft = update(tree[pre].x, st,md, l,md, d);
        rgt = update(tree[pre].y, md+1,ed, md+1,r, d);
    }
    tree[node] = info(lft,rgt, tree[lft].z+tree[rgt].z, 0);
//    cout << node << ' ' << tree[node].z << endl;
    return node;
}

ll query(int node, int st, int ed, int l, int r) {
    cout << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << tree[node].z << endl;
    getchar();
//    if(ed < l || st > r) return 0;
    if(st == l && ed == r) return tree[node].z;
    pushdown(node, st,ed);
    int lft = tree[node].x, rgt = tree[node].y, md = (st+ed)/2;
    if(r <= md) return query(lft, st,md, l,r);
    else if(l > md) return query(rgt, md+1,ed, l,r);
    return query(lft, st,md, l,md) + query(rgt, md+1,ed, md+1,r);
}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    root[TIMES] = init(1,n);

    while(m--) {
        char ch[3];
        int l,r, x;
        scanf("%s", ch);
        if(ch[0] == 'C') {
            scanf("%d %d %d", &l,&r,&x);
            ++TIMES;
            root[TIMES] = update(root[TIMES-1], 1,n, l,r, x);
        }
        else if(ch[0] == 'Q') {
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(root[TIMES], 1,n, l,r));
        }
        else if(ch[0] == 'H') {
            scanf("%d %d %d", &l,&r,&x);
            printf("%lld\n", query(root[x], 1,n, l,r));
        }
        else {
            scanf("%d", &x);
            TIMES = x;
        }
    }
}
