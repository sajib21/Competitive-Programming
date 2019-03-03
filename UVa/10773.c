#include <stdio.h>
#include <math.h>
int main()
{
    int t, i;
    double  P,d, v, u;
    scanf("%d", &t);

    for(i=1; i<=t; i++)
    {
        scanf("%lf %lf %lf", &d, &v, &u);
        if(u>v && u>0 && v>0)
        {
            P=( d*(1/(sqrt( u*u*1.0-  v*v*1.0))-1/u));
            printf("Case %d: %0.3lf\n", i, P);
        }
        else printf("Case %d: can't determine\n", i);
    }
    return 0;
}
