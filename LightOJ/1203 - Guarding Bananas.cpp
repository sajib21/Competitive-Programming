#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

struct info {
    ll x,y;
    info() {}
    info(ll a, ll b) {
        x = a; y = b;
    }
};

int n, minPos;
info pnt[LIM+10];
info temp[LIM+100];

double area(info a, info b, info c) {
    return 0.5*((a.x-b.x)*(b.y-c.y) - (b.x-c.x)*(a.y-b.y)) ;
}
ll dist(info a, info b) {
    return sqr(a.x-b.x) + sqr(a.y-b.y);
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
    if(j<3) return 0;

    temp[j++] = temp[0];
    temp[j++] = temp[1];

    double mnn = 400;
    for(int i=0; i<j-2; i++) mnn = min(mnn, cone(temp[i], temp[i+1], temp[i+2]));

    return 180.0/pi * mnn;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        minPos = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%lld %lld", &pnt[i].x, &pnt[i].y);

        if(n < 3) printf("Case %d: 0\n", t);
        else printf("Case %d: %.10lf\n", t, grahamScan());
    }

    return 0;
}
