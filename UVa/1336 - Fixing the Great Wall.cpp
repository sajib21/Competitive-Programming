#include<bits/stdc++.h>
#define LIM 2000
#define MAX 1e15
#define ld long double

using namespace std;

struct info { /// location, damage, increase rate
    int x,y,z;
    info() {}
    info(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
};

bool cmp(info a, info b) {
    return a.x < b.x;
}

int n,v,xx, leftSum[LIM+10], rightSum[LIM+10];
info dam[LIM+10];
double dp[LIM+10][LIM+10][3];
int cs[LIM+10][LIM+10][3];
bool go[LIM+10][LIM+10][3];
int cases = 0;

double f(int lft, int rgt, int con) {
    if(lft < 0 || rgt >= n || rgt > LIM || rgt < 0 || lft > rgt) return MAX;
    if(lft < 0 || rgt >= n || con > 1 || v <= 0) return MAX;
    if(lft == 0 && rgt == n-1) return 0;
    if(cs[lft][rgt][con] == cases) return dp[lft][rgt][con];
    cs[lft][rgt][con] = cases;

    int raise = (lft? leftSum[lft-1] : 0 ) + (rgt<n-1? rightSum[rgt+1] : 0);
    double ans = MAX;

    if(lft > 0) {
        double l2l = 1.0*(dam[lft].x-dam[lft-1].x)/v;
        double r2l = 1.0*(dam[rgt].x-dam[lft-1].x)/v;
        if(!con) ans = min(ans, l2l*raise+dam[lft-1].y+f(lft-1, rgt, 0) );
        else     ans = min(ans, r2l*raise+dam[lft-1].y+f(lft-1, rgt, 0) );
    }
    if(rgt < n-1) {
        double l2r = 1.0*(dam[rgt+1].x-dam[lft].x)/v;
        double r2r = 1.0*(dam[rgt+1].x-dam[rgt].x)/v;
        if(!con) ans = min(ans, l2r*raise+dam[rgt+1].y+f(lft, rgt+1, 1) );
        else     ans = min(ans, r2r*raise+dam[rgt+1].y+f(lft, rgt+1, 1) );
    }

    go[lft][rgt][con] = 1;
    return dp[lft][rgt][con] = ans;
}

int main() {
//    freopen("1336i.txt", "r", stdin);
//    freopen("1336o.txt", "w", stdout);

    memset(cs, 0, sizeof cs);
    while(~scanf("%d %d %d", &n,&v,&xx)) {
        cases++;
        if(!n) return 0;
        for(int i=0; i<n; i++) scanf("%d %d %d", &dam[i].x, &dam[i].y, &dam[i].z);
        dam[n].x = xx; dam[n].y = 0; dam[n].z = 0;
        n++;
        std::sort(dam, dam+n, cmp);
        leftSum[0] = dam[0].z; for(int i=1; i<n; i++) leftSum[i] = leftSum[i-1] + dam[i].z;
        rightSum[n-1] = dam[n-1].z; for(int i=n-2; i>=0; i--) rightSum[i] = rightSum[i+1] + dam[i].z;

        int in = 0; for(int i=0; i<n; i++) if(dam[i].x == xx) {
            in = i;
            break;
        }

//        memset(go, 0, sizeof go);
        printf("%d\n", (int) floor(f(in, in, 0)) );
    }
}
