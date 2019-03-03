///given A B P points in 3D , output minimum distance from P to AB

#include<bits/stdc++.h>

using namespace std;

int x1, Y1, z1, x2, y2, z2, x, y, z;

double distanceWithP(double mx1, double my1, double mz1) {
    return sqrt( (mx1-x)*(mx1-x) + (my1-y)*(my1-y) + (mz1-z)*(mz1-z) );
}

double shortDis() {
    double lo = 0, hi = 1;
    int xd = (x2-x1), yd = (y2-Y1), zd = (z2-z1);
    for(int i=0; i<50; i++) {
        double m1 = lo + (hi-lo)/3, m2 = hi - (hi -lo)/3;
        double m1x = x1 + xd*m1, m1y = Y1 + yd*m1, m1z = z1 + zd*m1;
        double m2x = x1 + xd*m2, m2y = Y1 + yd*m2, m2z = z1 + zd*m2;

        if(distanceWithP(m1x,m1y,m1z) < distanceWithP(m2x,m2y,m2z)) hi = m2;
        else lo = m1;
    }
    double m1 = lo + (hi-lo)/3, m2 = hi - (hi -lo)/3;
    double m1x = x1 + xd*m1, m1y = Y1 + yd*m1, m1z = z1 + zd*m1;
    return distanceWithP(m1x,m1y,m1z);
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {
        scanf("%d %d %d %d %d %d %d %d %d", &x1, &Y1, &z1, &x2, &y2, &z2, &x, &y, &z);
        printf("Case %d: %.10lf\n", t, shortDis());
    }

    return 0;

}
