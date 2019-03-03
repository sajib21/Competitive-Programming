#include <stdio.h>

int main()
{
    printf("INTERSECTING LINES OUTPUT\n");

    double n, x1,y1,x2,y2,x3,y3,x4,y4, m1,m2, c1,c2, x,y, perp1, perp2;
    scanf("%lf", &n);
    while(n)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

        perp1=0;
        perp2=0;
        if(x1==x2) perp1=1;
        if(x3==x4) perp2=1;
        if(perp1 || perp2)
        {
            if(perp1==perp2)
            {
                if(x1==x3) printf("LINE\n");
                else printf("NONE\n");
            }
            else
            {
                if(perp1)
                {
                    m2=(y3-y4)/(x3-x4);
                    c2=y3-m2*x3;
                    x=x1;
                    y=m2*x1+c2;
                    printf("POINT %.2lf %.2lf\n", x,y);
                }
                else
                {
                    m1=(y1-y2)/(x1-x2);
                    c1=y1-m1*x1;
                    x=x3;
                    y=m1*x3+c1;
                    printf("POINT %.2lf %.2lf\n", x,y);
                }
            }
        }
        else
        {
            m1=(y1-y2)/(x1-x2);
            m2=(y3-y4)/(x3-x4);
            c1=y1-m1*x1;
            c2=y3-m2*x3;

            if(m1==m2)
            {
                if(c1==c2 ) printf("LINE\n");
                else printf("NONE\n");
            }
            else
            {
                x=(c2-c1)/(m1-m2);
                y=m1*x+c1;
                printf("POINT %.2lf %.2lf\n", x,y);
            }

        }
        n--;
    }
    printf("END OF OUTPUT\n");
    return 0;
}
