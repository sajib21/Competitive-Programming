#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        double a,b,c, oa,ob,oc, s, area, R, GH;
        scanf("%lf %lf %lf %lf", &a, &oa,&ob,&oc);
        b = a*oa/ob;
        c = a*oa/oc;

        s = (a+b+c)/2.0;
        area = sqrt( s*(s-a)*(s-b)*(s-c) );

        R = a*b*c / (4*area);
        GH = 2 * sqrt( R*R - (a*a+b*b+c*c)/9.0 );

        printf("%.3f %.3f\n", area, GH);

    }
}
