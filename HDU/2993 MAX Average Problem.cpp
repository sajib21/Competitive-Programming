#include<bits/stdc++.h>
#define pii     pair<int,int>
#define ff      first
#define ss      second
#define x       ff
#define y       ss
#define LIM     100000
#define sqr(x)  x * x

using namespace std;

int n,k, minPos, a[LIM+10];
pii pnt[LIM+10];
int cnt[LIM+100];
pii temp[LIM+100];

double area(pii a, pii b, pii c) {
    return 0.5*((a.x-b.x)*(b.y-c.y) - (b.x-c.x)*(a.y-b.y)) ;
}
double dist(pii a, pii b) {
    return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}

bool cmp(pii a, pii b) {
    if(area(pnt[0], a, b) > 0) return true;
    else if(area(pnt[0], a, b) < 0) return false;
    else return dist(pnt[0], a) < dist(pnt[0], b);
}

double cone(pii A, pii B, pii C) {
    double a = sqrt(dist(B,C)) , b = sqrt(dist(C,A)) , c = sqrt(dist(A,B));
    return acos( 1.0 * (sqr(a) + sqr(c) - sqr(b)) / (2*c*a) );
}

double grahamScan() {
    sort(pnt+1, pnt+n, cmp);

    for(int i=0; i<n; i++) cout << pnt[i].x << ' ' << pnt[i].y << endl;

    memset(cnt, 0, sizeof cnt);
    temp[0] = pnt[0];
    int i=1,j = 1;
    for( ; i<n; i++) if(pnt[i].x != temp[j-1].x || pnt[i].y != temp[j-1].y) {
        cnt[j] = i;
        temp[j++] = pnt[i];
        break;
    }

    for(; i<n; i++) {
        if(pnt[i].x == pnt[i-1].x && pnt[i].y == pnt[i-1].y) continue;
        while(j > 1 && area(temp[j-2], temp[j-1], pnt[i]) <= 0) j--;
        cnt[j] = i;
        temp[j++] = pnt[i];
    }

    cout << "HULL" << endl;
    for(int i=0; i<j; i++) cout << temp[i].x << ' ' << temp[i].y << ' ' << cnt[i] << endl;

    double ans = 0;
    for(int p=0; p<j; p++) {
        int u = cnt[p] + k;
        cout << "CNT " << cnt[p] << ' ' << u << endl;
        int q = lower_bound(cnt, cnt+j, u) - cnt;
        if(q >= j) break;
//        pii tmp =
        ans = max(ans, 1.0* (temp[q].y - temp[p].y) / (temp[q].x - temp[p].x) );
        cout << p << ' ' << q << ' ' << ans << endl;
    }
    printf("%.2lf\n", ans);
//    return ans;
}

int main() {
    minPos = 0;
    scanf("%d %d", &n,&k);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) pnt[i] = pii(i, pnt[i-1].ss+a[i]);
    n++;
    grahamScan();
//    printf("%.2lf\n", grahamScan());

    return 0;
}

