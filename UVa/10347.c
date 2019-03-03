#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c;
    double s;

    while((scanf("%lf %lf %lf", &a, &b, &c))==3)
    {
            s=(a+b+c)/2.0;
            s=s*(s-a)*(s-b)*(s-c);
            if(s<=0) printf("%.3lf\n", -1.0);
            else printf("%.3lf\n", (4.0/3.0)*sqrt(s));
    }
    return 0;
}
