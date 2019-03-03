#include <stdio.h>

int main()
{
    double h,h2,u,d,f;
    int a;
    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f))
    {
        if(!h) return 0;
        a=0;
        h2=0;
        f=u*f/100;
        while(h2<=h)
        {

            a++;
            u-=f;
        }
        if(h<0) printf("success on day %d\n", a);
        else printf("failure on day %d\n", a);
    }
}
