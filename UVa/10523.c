#include <stdio.h>
#include <math.h>

int main()
{
    long double n,a, i,j, sum=0;
    while(scanf("%lf %lf", &n, &a)!=EOF)
    {
        sum=0;
        for(i=1; i<=n; i++) sum+=i*pow(a,i);
        printf("%.0lf\n", sum);
    }
    return 0;
}
