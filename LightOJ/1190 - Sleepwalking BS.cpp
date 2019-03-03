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
    int x,y;
    info() {}
    info(int a, int b) {
        x = a; y = b;
    }
};

int n,q, minPos;
info pnt[LIM+10];

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

int main() {

//    freopen("1203 out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        minPos = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &pnt[i].x, &pnt[i].y);

        int minPos = 0;
        for(int i=0; i<n; i++) if(pnt[i].x < pnt[minPos].x || (pnt[i].x == pnt[minPos].x && pnt[i].y > pnt[minPos].y)) minPos = i;
        swap(pnt[0], pnt[minPos]);
        sort(pnt+1, pnt+n, cmp);

        scanf("%d", &q);
        printf("Case %d:\n", t);
        while(q--) {
            scanf("%d %d", &pnt[0].x, &pnt[0].y);

            int lo = 1 , hi =


            if(place) printf("Yes\n");
            else printf("No\n");
        }


    }

    return 0;
}

