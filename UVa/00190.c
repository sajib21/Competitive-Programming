#include <stdio.h>
#include <math.h>

int main()
{
    double ax,ay,bx,by,cx,cy,  det, c,d,e, h,k,r;

    while((scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy)))
    {
        det=ax*(by-cy)+bx*(cy-ay)+cx*(ay-by);
        c=-((ax*ax+ay*ay)*(by-cy)+(bx*bx+by*by)*(cy-ay)+(cx*cx+cy*cy)*(ay-by))/det;
        d= ((ay*ay+ax*ax)*(bx-cx)+(by*by+bx*bx)*(cx-ax)+(cy*cy+cx*cx)*(ax-bx))/det;
        e= ((ax*ax+ay*ay)*(bx*cy-cx*by)+(bx*bx+by*by)*(cx*ay-ax*cy)+(cx*cx+cy*cy)*(ax*by-bx*ay))/det;

        h=-c/2;
        k=-d/2;
        r=(h*h+k*k-e);

        if(r<=0) break;
        r=sqrt(r);
        printf("(x - %.3lf)^2 + (y - %.3lf)^2 = %.3lf^2\n", h, k, r);
        printf("x^2 + y^2 + %.3lfx + %.3lfy + %.3lf = 0\n", c, d, e);
    }
}



