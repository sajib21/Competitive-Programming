#include <stdio.h>
#include <math.h>

double con = 4 - 2*acos(0.0) ;

int main()
{
    int t,T;
    double r;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", t, r*r*con);
    }
    return 0;
}
