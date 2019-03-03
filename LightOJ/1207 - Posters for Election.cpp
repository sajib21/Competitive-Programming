#include<bits/stdc++.h>
#define LIM 100000
using namespace std;

int n, segTree[8*LIM];
int color[2*LIM];

void update(int node, int st, int ed, int l, int r, int color, int preColor=0) {

    if(preColor) segTree[node] = preColor;
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node] = color;
        return;
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , mid = (st+ed)/2;
    update(lft, st,mid, l,r, color, segTree[node]);
    update(rgt, mid+1, ed, l,r, color, segTree[node]);
    segTree[node] = 0;
}

void query(int node, int st, int ed) {

    if(segTree[node]) {
        color[ segTree[node] ] = 1;
        return;
    }
    if(st >= ed) return;

    int lft = node << 1 , rgt = (node << 1) + 1 , mid = (st+ed)/2;
    query(lft, st,mid);
    query(rgt, mid+1, ed);
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        memset(segTree, 0, sizeof(segTree));
        memset(color, 0, sizeof(color));

        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            int l,r;
            scanf("%d %d", &l,&r);
            update(1, 1,2*n, l,r, i);
        }
        query(1, 1,2*n);
        int ans = 0;
        for(int i=1; i<=2*n; i++) ans += color[i];

        printf("Case %d: %d\n", t,ans);
    }

    return 0;

}
