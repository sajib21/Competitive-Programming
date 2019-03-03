#include <stdio.h>
main()
{
    double x1,x2,x3,x4,y1,y2,y3,y4,d1,d2,d3,c1,c2,x,y,dy1,dx1,dy2, dx2,C1,C2,C3;
    int T,t;
    scanf("%d",&T);
    printf("INTERSECTING LINES OUTPUT\n");
    for(t = 1; t <= T; t++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        d1 = (y2 - y1) / (x2 - x1);
        d2 = (y3 - y4) / (x3 - x4);
        d3 = (y3 - y2) / (x3 - x2);
        c1 = d1 * x1 - y1;
        c2 = d2 * x3 - y3;
        C1 =  (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        C2 = (x2 - x3) * (y1 - y4) - (y2 - y3) * (x1 - x4);
        C3 = (x1 - x3) * (y2 - y4) - (y1 - y3) * (x2 - x4);
        if(C1 == 0 && C2 == 0 && C3 == 0) {
        printf("LINE\n");
        continue;
        }
        else if(C1 == 0 ) {
        printf("NONE\n");
        continue;
        }

















        else
        {
            x = (c1 - c2) / (d1 - d2);
            y = d1 * x - c1;
            if(x1 == x2) x = x1;
           if(y1 == y2) y = y2;
           if(x3 == x4 ) x = x3;
           if(y3 == y4) y = y3;




        }



        printf("POINT %0.2lf %0.2lf\n",x,y);
        if(t == T)
        {
            printf("END OF OUTPUT\n");
        }



    }
    return 0;



}
