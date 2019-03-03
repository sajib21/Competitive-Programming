#include <stdio.h>

int main()
{
    int h, m;
    float ang;

    while(1)
    {
        scanf("%d:%d", &h,&m);
        if(!h && !m) break;
        ang=(30.0*h-5.5*m);

        if(ang<0) ang=-1*ang;

        if(ang>180.0) printf("%0.3f\n", 360-ang);
        else printf("%0.3f\n", ang);
    }
    return 0;
}
