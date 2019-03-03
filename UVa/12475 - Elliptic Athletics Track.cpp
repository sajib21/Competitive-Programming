#include<bits/stdc++.h>
#define pi acos(-1)
#define sqr(x) ( (x) * (x) )

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int a,b;
        scanf("%d %d", &b,&a);

        double ans = 0;
        double x=0, y=b;

        while(a*a*(y-.5) >= b*b*(x+1)) {
            double xx = x+.0001;
            double yy = b * sqrt( 1 - xx*xx/(a*a) );

//            cout << xx << ' ' << yy << endl;

            ans += sqrt( sqr(x-xx) + sqr(y-yy) );

            x = xx; y = yy;

        }

        while(y > 0) {
            double yy = max(0.0,y-.0001);
            double xx = a * sqrt( 1 - yy*yy/(b*b) );

//            cout << xx << ' ' << yy << endl;

            ans += sqrt( sqr(x-xx) + sqr(y-yy) );

            x = xx; y = yy;

        }

        printf("Case %d: %.7f\n", t, 4*ans );
    }
}
