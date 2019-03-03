#include <stdio.h>
#include <math.h>

int main()
{
    double R,n;
    int i,t;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf%lf",&R,&n);
        double ans=(R*sin(acos(-1.0)/n)/(sin(acos(-1.0)/n)+1));
        printf("Case %d: %lf\n",i,ans);
    }
    return 0;
}
