#include<bits/stdc++.h>
#define pi acos(-1)

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        double cx,cy, ax,ay, bx,by;
        scanf("%lf %lf %lf %lf %lf %lf", &cx,&cy, &ax,&ay, &bx, &by);

        double a = sqrt((bx-cx)*(bx-cx) + (by-cy)*(by-cy));
        double b = sqrt((cx-ax)*(cx-ax) + (cy-ay)*(cy-ay));
        double c = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));

        double deg = acos( (a*a+b*b-c*c) / (2*a*b) );
        double r = a;

//        cout << deg * 180/pi << ' ' << sqrt(a2) << ' ' << sqrt(b2) << ' ' << sqrt(c2) << endl;

        printf("Case %d: %.10lf\n", t, deg * r );
    }

    return 0;
}
