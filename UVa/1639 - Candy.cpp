#include<bits/stdc++.h>
#define LIM 200000
#define EPS 1e-9
using namespace std;

long double lg[LIM+100] = {};
int n;
double p;
long double logC(int n, int m) {
    return lg[n] - lg[m] - lg[n-m];
}
int main() {

//    cout << exp(1) << endl;

    lg[0] = 0;
    for(int i=1; i<=LIM; i++) lg[i] = lg[i-1] + log(i);

    int t = 1;
    while(scanf("%d %lf", &n,&p) != EOF) {
        double ans = 0;

        long double p1,p2;
        p1 = log(p); p2 = log(1-p);

        for(int i=1; i<=n; i++) {
            ans += i*exp( logC(2*n-i, n) + (n+1)*p1 + (n-i)*p2 );
            ans += i*exp( logC(2*n-i, n) + (n+1)*p2 + (n-i)*p1 );


        }
        printf("Case %d: %.6lf\n", t++, ans);
    }
    return 0;
}
