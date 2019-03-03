/// problem perimeter of a convex round polygon
/// THE CURVY PARTS SUMS UP TO A CICLE :')

#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))

using namespace std;

struct info {
    ll x,y;
    info() {}
    info(ll a, ll b) {
        x = a; y = b;
    }
};

int n,d, minPos;
info pnt[LIM+10];
info temp[LIM+100];

double area(info a, info b, info c) {
    return 0.5*((a.x-b.x)*(b.y-c.y) - (b.x-c.x)*(a.y-b.y)) ;
}
double dist(info a, info b) {
    return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}

bool cmp(info a, info b) {
    if(area(pnt[0], a, b) > 0) return true;
    else if(area(pnt[0], a, b) < 0) return false;
    else return dist(pnt[0], a) < dist(pnt[0], b);
}

double cone(info A, info B, info C) {
    double a = sqrt(dist(B,C)) , b = sqrt(dist(C,A)) , c = sqrt(dist(A,B));
    return acos( 1.0 * (sqr(a) + sqr(c) - sqr(b)) / (2*c*a) );
}

double grahamScan() {
    minPos = 0;
    for(int i=0; i<n; i++) if(pnt[i].x < pnt[minPos].x || (pnt[i].x == pnt[minPos].x && pnt[i].y > pnt[minPos].y)) minPos = i;
    swap(pnt[0], pnt[minPos]);
    sort(pnt+1, pnt+n, cmp);

    temp[0] = pnt[0];
    int i=1,j = 1;
    for( ; i<n; i++) if(pnt[i].x != temp[j-1].x || pnt[i].y != temp[j-1].y) {
        temp[j++] = pnt[i];
        break;
    }

    for(; i<n; i++) {
        if(pnt[i].x == pnt[i-1].x && pnt[i].y == pnt[i-1].y) continue;
        while(j > 1 && area(temp[j-2], temp[j-1], pnt[i]) <= 0) j--;
        temp[j++] = pnt[i];
    }

    double perimeter = 0, totalArea = 0;
    for(int i=0; i<j; i++) perimeter += dist(temp[i], temp[ (i+1)%j ]);
    perimeter += 2*pi*d;
    return perimeter;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        minPos = 0;
        scanf("%d %d", &n, &d);
        for(int i=0; i<n; i++) scanf("%lld %lld", &pnt[i].x, &pnt[i].y);

        if(n < 1) printf("Case %d: 0\n", t);
        else printf("Case %d: %.10lf\n", t, grahamScan());
    }

    return 0;
}

