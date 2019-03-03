#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        double a,b,c,d, x, s, atr, h;
        scanf("%lf %lf %lf %lf", &a,&b,&c,&d);
        if(c > a) {
            double tmp = c;
            c = a;
            a = tmp;
        }

        x = a - c;
        s = (x+b+d) / 2.0;
        atr = sqrt(s * (s-x) * (s-b) * (s-d));
        h = 2*atr / x;

        printf("Case %d: %.10lf\n", t, 0.5*(a+c)*h );

    }
    return 0;
}
