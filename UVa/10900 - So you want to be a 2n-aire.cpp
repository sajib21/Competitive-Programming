#include<bits/stdc++.h>
#define EPS 1e-9
#define sqr(x) ( (x) * (x) )
using namespace std;

int n, pwr[32];
double t, dp[32];

int main() {
    pwr[0] = 1;
    for(int i=1; i<=30; i++) pwr[i] = 2*pwr[i-1];

    while(scanf("%d %lf", &n,&t)) {
        if(!n && !t) return 0;

        memset(dp, 0, sizeof dp);
        dp[n+1] = pwr[n]; // cout << "BASE " << dp[n+1] << endl;
        for(int i=n; i>0; i--) {
            double a = pwr[i-1] / dp[i+1]; // cout << a << endl;
            if(t <= a) dp[i] += ( min(a, 1.0) - t )*pwr[i-1]; // cout << ' ' << dp[1] << endl;
            if(a <= 1) dp[i] += ( 1 - sqr(max(a, t)) )*dp[i+1]/2.0; // cout << ' ' << dp[1] << endl;
            dp[i] /= (1-t);
        }
        printf("%.3lf\n", dp[1]);
    }
    return 0;
}
