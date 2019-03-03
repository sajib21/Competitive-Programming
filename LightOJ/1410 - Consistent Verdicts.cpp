#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;


struct pnt{
    int x,y;
    pnt() {}
    pnt(int xx, int yy) {
        x = xx; y = yy;
    }
};
ll dist(pnt a, pnt b) {
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}

int n;
pnt pnts[707];
ll dists[490005]; /// take ll if necessary

int main() {

//    freopen("1203 in.txt", "r", stdin);
//    freopen("1203 out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &pnts[i].x , &pnts[i].y);
        int c=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                dists[c++] = dist(pnts[i], pnts[j]);
            }
        }
        sort(dists, dists+c);
        int p=1;
        for(int i=1; i<c; i++) if(dists[i] != dists[i-1]) dists[p++] = dists[i];
        printf("Case %d: %d\n", t, p+1);
    }
    return 0;
}
