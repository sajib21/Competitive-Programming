#include <stdio.h>
#include <math.h>
int main()
{
    double l,w,h,tanth;

    while((scanf("%lf %lf %lf %lf", &l, &w, &h, &tanth))==4)
    {
        tanth=tan(tanth*acos(-1)/180.0);

        if(tanth<=h/l) printf("%.3lf mL\n", l*w*(h-0.5*l*tanth));
        else printf("%.3lf mL\n", 0.5*h*h*w/tanth);
    }

    return 0;
}
