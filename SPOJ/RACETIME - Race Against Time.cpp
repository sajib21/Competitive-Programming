#include<bits/stdc++.h>
#define ll long long int
#define LIM 100000

using namespace std;

struct info {
    ll mx, cnt, mxCnt;
    info() {
        mx = 0, cnt = 0; mxCnt = 0;
    }
};

ll ara[LIM+10];
info segTree[4*LIM + 10];

void initTree(int node, int st, int ed) {

    if(st == ed) {
        segTree[node].mx = ara[st];
        segTree[node].cnt = 0;
        segTree[node].mxCnt = 1;
        return;
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , mid = (st+ed)/2;
    initTree(lft, st, mid);
    initTree(rgt, mid+1, ed);
    if(segTree[lft].mx == segTree[rgt].mx) {
        segTree[node].mx = segTree[lft].mx;
        segTree[node].cnt = segTree[lft].cnt + segTree[rgt].cnt;
        segTree[node].mxCnt = segTree[lft].mxCnt + segTree[rgt].mxCnt;
    }
    else {
        segTree[node].mx = max(segTree[lft].mx , segTree[rgt].mx);
        segTree[node].cnt = segTree[lft].cnt + segTree[rgt].cnt;
        if(segTree[lft].mx > segTree[rgt].mx) {
            segTree[node].cnt += segTree[rgt].mxCnt;
            segTree[node].mxCnt = segTree[lft].mxCnt;
        }
        else {
            segTree[node].cnt += segTree[lft].mxCnt;
            segTree[node].mxCnt = segTree[rgt].mxCnt;
        }
    }
}

void update(int node, int st, int ed, int pos, int val) {

    if(st > pos || ed < pos) return;
    if(st == ed && st == pos) {
        segTree[node].mx = val;
        segTree[node].cnt = 0;
        return;
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , mid = (st+ed)/2;
    update(lft, st, mid, pos, val);
    update(rgt, mid+1, ed, pos, val);
    if(segTree[lft].mx == segTree[rgt].mx) {
        segTree[node].mx = segTree[lft].mx;
        segTree[node].cnt = segTree[lft].cnt + segTree[rgt].cnt;
        segTree[node].mxCnt = segTree[lft].mxCnt + segTree[rgt].mxCnt;
    }
    else {
        segTree[node].mx = max(segTree[lft].mx , segTree[rgt].mx);
        segTree[node].cnt = segTree[lft].cnt + segTree[rgt].cnt;
        if(segTree[lft].mx > segTree[rgt].mx) {
            segTree[node].cnt += segTree[rgt].mxCnt;
            segTree[node].mxCnt = segTree[lft].mxCnt;
        }
        else {
            segTree[node].cnt += segTree[lft].mxCnt;
            segTree[node].mxCnt = segTree[rgt].mxCnt;
        }
    }
}

ll query(int node, int st, int ed, int l, int r, int val) {

    if(st > r || ed < l) return 0;
    if(st >= l && ed <= r) {
        if(segTree[node].mx <= val) return segTree[node].cnt + segTree[node].mxCnt;
        else if(segTree[node].cnt == 0) return 0;
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , mid = (st+ed)/2;
    return query(lft, st,mid, l,r, val) + query(rgt, mid+1,ed, l,r, val);
}


int main() {

    int n,q;
    cin >> n >> q;
    for(int i=1; i<=n; i++) scanf("%lld", &ara[i]);
    initTree(1, 1,n);

    while(q--) {

        getchar();

        int ith,val, x,y;
        char c;
        scanf("%c", &c);
        if(c == 'M') {
            scanf("%d %d", &ith, &val);
            update(1, 1,n, ith, val);
        }
        else {
            scanf("%d %d %d", &x,&y,&val);
            printf("%lld\n", query(1, 1,n, x,y, val));
        }
    }

    return 0;
}
