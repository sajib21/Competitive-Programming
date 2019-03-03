#include<bits/stdc++.h>
#define MX 100000000
using namespace std;

int n, x[55], y[55];
bool dr[55][55];
double dp[55][55];

double area(int a, int b, int c) { return 0.5*((x[a]-x[b])*(y[b]-y[c]) - (x[b]-x[c])*(y[a]-y[b])) ; }

double f(int lft, int rgt) {
    cout << lft << ' ' << rgt << endl; getchar();
    if(lft+2 == rgt) {
        return fabs(area(lft, lft+1, lft+2));
    }
    if(dr[lft][rgt]) return dp[lft][rgt];
    double ans = MX;
    for(int i=lft+2; i<rgt-1; i++) ans = min(ans, max(f(lft,i),f(i,rgt)) );
    if(lft != 0 || rgt != n) ans = min(ans, max(f(lft,rgt-1),f(rgt-1,rgt)) );
    return dp[lft][rgt] = ans;
}

int main() {
    double q = MX;
//    cout << q << endl;
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
        if(n < 3) {
            printf("0.0\n");
            continue;
        }
        if(n == 3) {
            printf("%.1lf\n", area(0,1,2));
            continue;
        }
        x[n] = x[0]; y[n] = y[0];
        memset(dr, 0, sizeof dr);
        printf("%.1lf\n", f(0, n));
    }
}
