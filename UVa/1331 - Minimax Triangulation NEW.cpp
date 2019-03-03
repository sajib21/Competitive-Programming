#include<bits/stdc++.h>
#define MX 100000000
#define EPS 1e-6

using namespace std;

int n, x[55], y[55];
bool dr[55][55];
long double dp[55][55];

long double area(int a, int b, int c) { return 0.5*((x[a]-x[b])*(y[b]-y[c]) - (x[b]-x[c])*(y[a]-y[b])) ; }

bool chk(int lft, int rgt, int i) {
    double p,q,r,s;
    p = area(lft, i, i-1); q = area(lft, i, i-2);
    if( (p < 0 && q > 0) || (p > 0 && q < 0) ) return false;
    p = area(rgt, i, i-1); q = area(rgt, i, i-2);
    if( (p < 0 && q > 0) || (p > 0 && q < 0) ) return false;
    return true;
}

long double f(int lft, int rgt) {
    if(abs(lft-rgt) == 1) return 0;
    if(dr[lft][rgt]) return dp[lft][rgt];
    long double ans = MX;

    for(int i=lft+1; i<rgt; i++) {
//        if(i > lft+1 && !chk(lft, rgt, i)) continue;
        long double a = f(lft,i) , b = f(i,rgt), c = fabs(area(lft, i, rgt) ), d;
//        if(a+EPS < b) d = b;
//        else d = a;
//        if(c > d+EPS) d = c;
//        if(d+EPS < ans) ans = d;

        ans = min(ans, max( c , max( a , b ) ) );
    }
    dr[lft][rgt] = 1;
    return dp[lft][rgt] = ans;
}

int main() {
//    freopen("1331i.txt", "r", stdin);
//    freopen("1331o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
        memset(dr, 0, sizeof dr);
        printf("%.1lf\n", (double) f(0, n-1));
    }
    return 0;
}

