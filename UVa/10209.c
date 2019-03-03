#include <stdio.h>
#include <math.h>

int main()
{
    double a, a1, a2, a3;
    while((scanf("%lf", &a))!=EOF)
    {
        a1=a*a*(1-sqrt(3)+(acos(-1)/3));
        a2=a*a*(2*sqrt(3)-4+(acos(-1)/3));
        a3=a*a*(4-sqrt(3)-(2*acos(-1)/3));
        printf("%.3lf %.3lf %.3lf\n", a1 , a2, a3);
    }
    return 0;
}
