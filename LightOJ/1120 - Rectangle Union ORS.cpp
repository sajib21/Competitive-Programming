#include<bits/stdc++.h>
#define LIM 60006
#define OPEN 0
#define CLOSE 1
#define ll long long int

using namespace std;

struct range {
    int x, ymin, ymax, type;
};

bool cmp (range a, range b) {
    return a.x < b.x;
}

struct segment{
    int val,_and, _or;
    ll sum;
};

int n;
range ranges[LIM+10];
segment segTree[5*LIM]; /// LESS THAN 5 TIMES NILE WA DITASE KN?? RE O DEY NA ABR KMNE KI BUJHTASIO NA
int y[LIM+10], cy, compressY[LIM+10];

void update(int node, int st, int ed, int yMin, int yMax, int type) {

int lft = node << 1 , rgt = (node << 1)+1 , mid = (st+ed)/2;
    if(compressY[ed] < yMin || compressY[st] > yMax) return;
    if(compressY[st] >= yMin && compressY[ed] <= yMax) {

        if(type == OPEN) segTree[node].val++;
        else segTree[node].val--;

        if(segTree[node].val) segTree[node].sum = compressY[ed] - compressY[st];
        else segTree[node].sum = segTree[lft].sum + segTree[rgt].sum;
        return;
    }
    if (st + 1 >= ed) return;

    update(lft, st, mid, yMin, yMax, type);
    update(rgt, mid, ed, yMin, yMax, type);
    if(segTree[node].val) segTree[node].sum = compressY[ed] - compressY[st];
    else segTree[node].sum = segTree[lft].sum + segTree[rgt].sum;
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        memset(segTree, 0, sizeof(segTree));

        scanf("%d", &n);
        int yy = 0;
        for(int i=0; i<2*n; i+=2) {
            int xa,ya, xb,yb;
            scanf("%d %d %d %d", &xa,&ya,&xb,&yb);
            ranges[i].x = xa;
            ranges[i].ymin = ya;
            ranges[i].ymax = yb;
            ranges[i].type = OPEN;
            ranges[i+1].x = xb;
            ranges[i+1].ymin = ya;
            ranges[i+1].ymax = yb;
            ranges[i+1].type = CLOSE;
            y[yy++] = ya;
            y[yy++] = yb;
        }
        sort(ranges, ranges+2*n, cmp);
        sort(y, y+yy);

        compressY[1] = y[0]; cy=1;
        for(int i=1; i<yy; i++) if(y[i] != y[i-1]) compressY[++cy] = y[i];
        ll ans = 0;

        update(1, 1,cy, ranges[0].ymin,ranges[0].ymax, ranges[0].type);
        for(int i=1; i<2*n; i++) {
            if(ranges[i].x > ranges[i-1].x) {
                ans += (ll)(ranges[i].x - ranges[i-1].x) * segTree[1].sum;
            }
            update(1, 1,cy, ranges[i].ymin, ranges[i].ymax, ranges[i].type);
        }
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;

}
