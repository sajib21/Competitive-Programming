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
    int x,y,t;
    pnt() {}
    pnt(int xx, int yy) {
        x = xx; y = yy;
    }
};
bool cmp(pnt a, pnt b) {
    return a.y < b.y;
}
bool cmp2(pnt a, pnt b) {
    return a.x < b.x;
}

int n, h[110];
pnt pts[110];
int dp[105][105][105];

int getMax(int mn, int in, int mx) {
    if(in == n) return 0;
    if(dp[mn][in][mx] != -1) return dp[mn][in][mx];

    int ans = getMax(mn, in+1, mx);
    if(mn <= h[in] && h[in] <= mx) ans = max(ans, 1 + max( getMax(h[in], in+1, mx) , getMax(mn, in+1, h[in]) ) );

    return dp[mn][in][mx] = ans;
}

int main() {

//    freopen("1283 out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &pts[i].y);
            pts[i].x = i;
        }
        sort(pts, pts+n, cmp);
        for(int i=0, x=1; i<n; i++) {
            if(!i || pts[i].y != pts[i-1].y) pts[i].t = x++;
            else pts[i].t = pts[i-1].t;
        }
        sort(pts, pts+n, cmp2);
        for(int i=0; i<n; i++) h[i] = pts[i].t;
//for(int i=0; i<n; i++) cout << h[i] << ' '; cout << endl;


        printf("Case %d: %d\n", t, getMax(0, 0, 102));
    }
    return 0;
}
