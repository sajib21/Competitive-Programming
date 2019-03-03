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
    int id, res; ll x,y;
    info() {}
    info(int i, ll a, ll b) {
        id = i ; x = a; y = b;
    }
};

int n, minPos;
info pnt[LIM+10];
info temp[LIM+100];

ll area(info a, info b, info c) {
    return (a.x-b.x)*(b.y-c.y) - (b.x-c.x)*(a.y-b.y) ;
}
ll dist(info a, info b) {
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}

bool cmp(info a, info b) {


    if(area(pnt[0], a, b) > 0) return true;
    else if(area(pnt[0], a, b) < 0) return false;
    else {
        return dist(pnt[0], a) < dist(pnt[0], b);
    }
}
bool cmp2(info a, info b) {
    return a.id < b.id ;
}

int main() {

//    freopen("1285 out", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        minPos = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%lld %lld", &pnt[i].x, &pnt[i].y) , pnt[i].id = i;

        minPos = 0;
        for(int i=0; i<n; i++) if(pnt[i].x < pnt[minPos].x || (pnt[i].x == pnt[minPos].x && pnt[i].y > pnt[minPos].y)) minPos = i;
        swap(pnt[0], pnt[minPos]);

        sort(pnt+1, pnt+n, cmp);

        for(int i=0; i<n; i++) pnt[i].res = i;

        bool possible = false;
        for(int i=2; i<n; i++) if(area(pnt[0], pnt[i-1], pnt[i])) {
            possible = true ; break;
        }
        if(area(pnt[n-1], pnt[0], pnt[1])) possible = true;

        printf("Case %d:\n", t);
        if(!possible) printf("Impossible\n");
        else {

            int i;
            for(i=n-1; i>1; i--) if(area(pnt[0], pnt[i], pnt[i-1])) break;
            reverse(pnt+i, pnt+n);

            printf("%d", pnt[0].id);
            for(int i=1; i<n; i++) printf(" %d", pnt[i].id);
            printf("\n");
        }
    }

    return 0;
}

