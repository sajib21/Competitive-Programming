#include<bits/stdc++.h>

using namespace std;

int setBit(int mask, int p) { return mask | (1 << p); }
int chkBit(int mask, int p) { return mask & (1 << p); }

int n,r;
double p[33], dp[22][1 << 20];
bool dr[22][1 << 20];

double f(int in, int mask) {
//    cout << "STATE CHK " << in << ' ' << mask << endl;
    int taken = __builtin_popcount(mask);
//    if(taken == r) return 1;
    if(in == n) return (taken == r);
    if(dr[in][mask]) return dp[in][mask];
//    dr[mask] = 1;

//    cout << "STATE INN " << in << ' ' << mask << endl; getchar();

    double ans = 0;

    if(chkBit(mask, in)) ans = p[in]*f(in+1, mask);
    else {
        if(taken < r) ans += p[in]*f(in+1, setBit(mask, in));
        ans += (1-p[in])*f(in+1, mask);
    }

    dr[in][mask] = 1;
    return dp[in][mask] = ans;
}

int main() {
//    cout << setBit(0,0) << endl;
    int T;
//    scanf("%d", &T);
    for(int t=1; ; t++) {
        memset(dr, 0, sizeof dr);
        scanf("%d %d", &n, &r);
        if(!n) return 0;
        for(int i=0; i<n; i++) scanf("%lf", &p[i]);
        printf("Case %d:\n", t);
//        for(int i=0; i<n; i++) {
//            cout << i << ' ' ;
//
//            cout << f(0, setBit(0, i) ) << ' ' ;
//            cout << f(0,0) << ' ' << endl;
//        }
        for(int i=0; i<n; i++) printf("%.6lf\n", f(0, setBit(0, i) ) / f(0, 0) );
    }
    return 0;
}
