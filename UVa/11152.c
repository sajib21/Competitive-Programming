#include <stdio.h>
#include <math.h>
#define pi 3.141592653589793
int main()
{
    int a, b, c;
    double s, rout, rin, tri, inarea;
    while(scanf("%d %d %d", &a, &b, &c)==3)
    {
        s=(a+b+c)/2.0;
        tri=sqrt(s*(s-a)*(s-b)*(s-c));

        rout=(a*b*c)/(4.0*tri);
        rin=(tri/s);

        inarea=(pi*rin*rin);

        printf("%.4lf %.4lf %.4lf\n", (pi*rout*rout)-tri, tri-inarea, inarea);
    }
    return 0;
}
