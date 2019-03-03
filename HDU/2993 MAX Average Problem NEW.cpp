#include<bits/stdc++.h>
#define pii     pair<int,int>
#define ff      first
#define ss      second
#define x       ff
#define y       ss
#define LIM     100000
#define sqr(x)  x * x
#define vii     vector<int>
#define pb      push_back
#define pp      pop_back

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

int main() {
    minPos = 0;
    scanf("%d %d", &n,&k);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) pnt[i] = pii(i, pnt[i-1].ss+a[i]);
    n++;

    cout << "DATA" << endl;
    for(int i=0; i<n; i++) cout << pnt[i].x << ' ' << pnt[i].y << endl;

    vii.pb(0)
    int i=0, j = k;
    double ans = 1.0 * (pnt[j].y-pnt[i].y) / (pnt[j].x-pnt[i].x);
    cout << ans << endl;



    while(j < n) {
        double a = 1.0 * (pnt[j+1].y-pnt[i].y) / (pnt[j+1].x-pnt[i].x);
        double b = 1.0 * (pnt[j+1].y-pnt[j].y) / (pnt[j+1].x-pnt[j].x);

        if(j+1-i >= k) ans = max(ans, a);
        if(j+1-j >= k) ans = max(ans, b);

        cout << i << ' ' << j << ' ' << a << ' ' << b << ' ' << ans << endl;

        if(a >= b) j++;
        else i++;

        if(i == j) j++;
//        if(a < b) i++;
//        else {i++; j++;}
//        if(j < n-1) j++;

    }
    printf("%.2lf\n", ans);

    return 0;
}

