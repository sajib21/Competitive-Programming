#include<bits/stdc++.h>
#define EPS 1e-9

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        double l,n,c;
        long double s, theta, sg;
        scanf("%lf %lf %lf", &l,&n,&c);
        s = (1+n*c)*l;

        long double lo = l/2.0, hi = 10000000000;
        long double x, rg;
        long double lg;
        while(lo < hi) {
            rg = (lo+hi)/2.0;
//            x = sqrt(rg*rg - l*l/4);
            theta = 2*asin(l/(lo+hi) ) ;
//            theta = 1.0 * s / rg;
//            lg = 2*rg*sin(theta/2.0);
            sg = rg*theta;
//            cout << rg << ' ' << x << ' ' << rg-x << ' ' << theta << ' ' << sg << endl;
//            if(fabs(sg-s) <= EPS) break;
            if(sg > s) lo = rg;
            else hi = rg;

            if(fabs(sg-s) <= EPS) break;
        }
        double ans = rg - sqrt(rg*rg - l*l/4.0) ;
        printf("Case %d: %.10lf\n", t, ans );
    }
    return 0;
}

