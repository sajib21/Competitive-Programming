#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double ha, hb, hc, a;
    scanf("%d", &n);
    while(n)
    {
        scanf("%lf %lf %lf", &ha, &hb, &hc);
        a=(1/ha+1/hb+1/hc)*(1/ha+1/hb-1/hc)*(1/hb+1/hc-1/ha)*(1/hc+1/ha-1/hb);
        if(a<=0 || !ha || !hb || !hc)
        {
            printf("These are invalid inputs!\n");
            n--;
        }
        else printf("%.3lf\n", 1/sqrt(a));
    }
    return 0;
}
