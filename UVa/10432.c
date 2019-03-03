#include <stdio.h>
#include <math.h>

int main()
{
    double r, n, pi=acos(-1);

    while((scanf("%lf %lf", &r, &n))!=EOF)
    {
        printf("%.3lf\n", n/2.0*r*r*sin(2*pi/n));
    }
    return 0;
}
