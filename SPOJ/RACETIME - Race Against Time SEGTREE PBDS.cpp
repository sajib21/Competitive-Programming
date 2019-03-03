#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define pii pair<int,int>
#define LIM 100005
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;


using namespace std;
using namespace __gnu_pbds;


typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

char cmd[10];
int n,q,x,y,z, a[LIM];
ordered_set segTree[4*LIM];

void update(int node, int st, int ed, int p, int v, int c) {
    if(ed < p || st > p) return;
    if(c == 1) segTree[node].insert(pii(v,p));
    else segTree[node].erase(pii(v,p));
    if(st == p && ed == p) return;
    segVar;
    update(lft, st,md, p,v, c); update(rgt, md+1,ed, p,v, c);
}

int query(int node, int st, int ed, int l, int r, int v) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node].order_of_key(pii(v+1,0));
    segVar;
    return query(lft, st,md, l,r, v) + query(rgt, md+1,ed, l,r, v);
}

int main() {
    scanf("%d %d", &n,&q);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]), update(1, 1,n, i, a[i], 1);
    while(q--) {
        scanf("%s", cmd);
        if(cmd[0] == 'M') {
            scanf("%d %d", &x,&y);
            update(1, 1,n, x, a[x], 0);
            update(1, 1,n, x, y, 1);
            a[x] = y;
        }
        else {
            scanf("%d %d %d", &x,&y,&z);
            printf("%d\n", query(1, 1,n, x,y, z));
        }
    }
}
