#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 500
#define segVar int lft = noed << 1, rgt = (node << 1) + 1 , md =  (st+ed)/2;
#define pdd     pair<double,double>
#define mpr     make_pair

using namespace std;

struct range {
    double x, ymin, ymax, type;
};

bool cmp (range a, range b) {
    return a.x < b.x;
}

struct segment{
    int val,_and, _or;
    double sum;
};

int n;
range ranges[LIM+10];
segment segTree[5*LIM]; /// LESS THAN 5 TIMES NILE WA DITASE KN?? RE O DEY NA ABR KMNE KI BUJHTASIO NA
double y[LIM+10]; int cy;
double  compressY[LIM+10];
map<double,int>mpy;

void update(int node, int st, int ed, double yMin, double yMax, int type) {

int lft = node << 1 , rgt = (node << 1)+1 , mid = (st+ed)/2;
    if(compressY[ed] < yMin || compressY[st] > yMax) return;
    if(compressY[st] >= yMin && compressY[ed] <= yMax) {

        if(type == 1) segTree[node].val++;
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

//    freopen("688i.txt", "r", stdin);
//    freopen("688o.txt", "w", stdout);

    int T;
//    cin >> T;
    for(int t=1; ; t++) {
        memset(segTree, 0, sizeof(segTree));

        scanf("%d", &n); if(!n) return 0;
        int yy = 0;
        for(int i=0; i<2*n; i+=2) {
            double xa,ya, xb,yb;
            double x,Y,r;
            scanf("%lf %lf %lf", &x,&Y,&r);
            xa = x-r; ya = Y-r; xb = x+r; yb = Y+r;
            ranges[i].x = xa; ranges[i].ymin = ya; ranges[i].ymax = yb; ranges[i].type = 1;
            ranges[i+1].x = xb; ranges[i+1].ymin = ya; ranges[i+1].ymax = yb; ranges[i+1].type = -1;
            y[yy++] = ya; y[yy++] = yb;
        }
        sort(ranges, ranges+2*n, cmp);
        sort(y, y+yy);

//        cout << "RANGES" << endl;
//        for(int i=0; i<2*n; i++) cout << ranges[i].x << ' ' << ranges[i].ymin << ' ' << ranges[i].ymax << endl;

        compressY[1] = y[0]; cy=1;
        for(int i=1; i<yy; i++) if(y[i] != y[i-1]) compressY[++cy] = y[i];
        double ans = 0;
        for(int i=1; i<=cy; i++) mpy[ compressY[i] ] = i;

        update(1, 1,cy, ranges[0].ymin,ranges[0].ymax, ranges[0].type);
//        cout << "INITED" << endl;
        for(int i=1; i<2*n; i++) {
//            cout << segTree[1].sum << endl;
            if(ranges[i].x > ranges[i-1].x) {
                ans += (ranges[i].x - ranges[i-1].x) * segTree[1].sum;
            }
            update(1, 1,cy, ranges[i].ymin, ranges[i].ymax, ranges[i].type);

//            cout <<segTree[1].sum << ' ' << ans << endl; getchar();
        }
        printf("%d %.2lf\n", t, ans);
    }

    return 0;

}
