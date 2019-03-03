#include <stdio.h>
#include <math.h>
int main()
{
    int t, l;
    double ca;

    scanf("%d", &t);

    while(t)
    {
        scanf("%d", &l);
        ca= acos(-1)*l*l/25.0;
        printf("%.2lf %.2lf\n", ca, 3.0*l*l/5.0-ca);
        t--;
    }

    return 0;

}
