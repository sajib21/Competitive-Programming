#include<bits/stdc++.h>
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define LIM 103

using namespace std;

char dir[] = {'N', 'W', 'S', 'E' };

struct info{
    int x,y,z;
    info() {x = y = z = 0;}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};

int m,n,q;
//char grid[LIM+10][LIM+10];
//int val[LIM+10][LIM+10];
info segTree[4*LIM+10][4*LIM+10];
int x,y, xa,ya,xb,yb, v;

void updateX(int node, int st, int ed, int stC, int edC, int lr, int rr, int lc, int rc, int val);
void updateY(int row, int node, int stR, int edR, int st, int ed, int l, int r, int val);
int queryX(int node, int st, int ed, int stC, int edC, int lr, int rr, int lc, int rc);
int queryY(int row, int node, int stR, int edR, int st, int ed, int l, int r, int prop=0);

void updateX(int node, int st, int ed, int stC, int edC, int lr, int rr, int lc, int rc, int val) {
    cout << "UpX " << node << ' ' << st << ' ' << ed << ' ' << stC << ' ' << edC << ' ' << lr << ' ' << rr << ' ' << lc << ' ' << rc << ' ' << val << endl;
    getchar();
    if(ed < lr || st > rr) return;
    if(st >= lr && ed <= rr) {
        updateY(node, 1, st,ed, stC,edC, lc,rc, val);
        return;
    }
    segVar;
    updateX(lft, st, md, stC, edC, lr, rr, lc, rc, val);
    updateX(rgt,md+1,ed, stC, edC, lr, rr, lc, rc, val);
}
void updateY(int row, int node, int stR, int edR, int st, int ed, int l, int r, int val) {
    cout << "UpY " << row << ' ' << node << ' ' << stR << ' ' << edR << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << val << endl;
    getchar();
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[row][node].x ^= (((edR-stR+1)*(ed-st+1))%2)*val;
        segTree[row][node].y ^= val;
        cout << "INFO " << row << ' ' << node << ' ' << segTree[row][node].x << ' ' << segTree[row][node].y << endl;
        getchar();
        return;
    }
    segVar;
    updateY(row, lft, stR,edR, st,md, l,r, val );
    updateY(row, rgt,stR,edR,md+1,ed, l,r, val );
    segTree[row][node].x = segTree[row][lft].x ^ segTree[row][rgt].x;
}

int queryX(int node, int st, int ed, int stC, int edC, int lr, int rr, int lc, int rc) {
    if(ed < lr || st > rr) return 0;
    if(st >= lr && ed <= rr) return queryY(node, 1, st,ed, stC,edC, lc,rc);
    segVar;
    return queryX(lft, st,md, stC,edC, lr,rr, lc,rc) ^ queryX(rgt, md+1,ed, stC,edC, lr,rr, lc,rc);
}
int queryY(int row, int node, int stR, int edR, int st, int ed, int l, int r, int prop) {
    cout << "QryY " << row << ' ' << node << ' ' << stR << ' ' << edR << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << prop << endl;
    getchar();
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) {
        cout << "OUT " << row << ' ' << node << ' ' << (segTree[row][node].x ^ (((edR-stR+1)*(ed-st+1)%2)*prop)) << endl;
        getchar();
        return segTree[row][node].x ^ (((edR-stR+1)*(ed-st+1)%2)*prop);
    }
    segVar;
    return queryY(row, lft, stR,edR, st,md, l,r, prop^segTree[row][node].y ) ^
            queryY(row, rgt, stR,edR, md+1,ed, l,r, prop^segTree[row][node].y);
}

int main() {
    scanf("%d", &n);
    scanf("%d", &q);
    while(q--) {
        int c;
        scanf("%d", &c);
        if(c == 2) {
            scanf("%d %d %d %d %d", &xa,&ya,&xb,&yb,&v);
//            printf("UP %d %d %d %d %d", &xa,&ya,&xb,&yb,&v);
            updateX(1, 1,n, 1,n, xa,xb, ya,yb, v);
        }
        else {
            scanf("%d %d %d %d", &xa,&ya, &xb,&yb);
            int an = queryX(1, 1,n, 1,n, xa,xb, ya,yb) ;
            printf("%d\n", an);
        }
    }

    return 0;
}

/*
3 55
2 1 1 2 2 1
2 1 3 2 3 2
2 3 1 3 3 3
1 2 2 3 3
1 2 2 3 2
*/

