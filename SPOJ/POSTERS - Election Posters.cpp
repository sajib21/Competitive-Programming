#include<bits/stdc++.h>
#define LIM 10000000

using namespace std;

int n, segTree[4*LIM+100];
int color[40000+100];

void update(int node, int st, int ed, int l, int r, int val, int pre = 0) {

    if(pre) segTree[node] = pre;
    if(st > r || ed < l) return;
    if(st >= l && ed <= r) {
        segTree[node] = val;
        return;
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed)/2;
    update(lft, st, md, l, r, val, segTree[node]);
    update(rgt, md+1,ed,l, r, val, segTree[node]);
    segTree[node] = 0;
}

void query(int node, int st, int ed) {

    if(segTree[node]) {
        color[ segTree[node] ] = 1;
        return;
    }
    if(st >= ed) return;

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed)/2;
    query(lft, st, md);
    query(rgt, md+1,ed);
}

int main() {

    int t;
    scanf("%d", &t);
    while(t--) {

        memset(segTree, 0, sizeof(segTree));
        memset(color, 0, sizeof(color));

        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            int l,r;
            scanf("%d %d",&l,&r);
            update(1, 1,LIM, l,r, i);
        }
        query(1, 1,LIM);

        int ans = 0;
        for(int i=1; i<=n; i++) ans += color[i];

        printf("%d\n", ans);

//        for(int i=1; i<=10; i++) cout << segTree[i] << ' '; cout << endl;
    }
    return 0;
}
