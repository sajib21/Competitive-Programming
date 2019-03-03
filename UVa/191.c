#include <stdio.h>

double check(double x, double y, double x1, double y1, double x2, double y2)
{
    double det;


    if(y1==y2) det=y-y1;
    else if(x1==x2) det=x-x1;
    else det=(1.0*(y-y1)/(y1-y2)-(1.0*(x-x1)/(x1-x2)));
    if(det<0.0) return -1.0;
    else if(!det) return 0.0;
    else return 1.0;
}

int main()
{
    double n, lx1,ly1,lx2,ly2, x1,y1,x2,y2, cp1,cp2;
    scanf("%lf", &n);
    while(n)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &lx1,&ly1,&lx2,&ly2, &x1,&y1,&x2,&y2);

        if(ly1==ly2 && lx1==lx2)
        {
            if(lx1>=x1 && lx1<=x2 && ly1<=y1 && ly2>=y2) printf("T\n");
            else if(lx1>=x2 && lx1<=x1 && ly1<=y2 && ly2>=y1) printf("T\n");
            else printf("F\n");
            continue;
        }

        cp1=check(x1, y1, lx1,ly1,lx2,ly2);
        cp2=check(x2, y2, lx1,ly1,lx2,ly2);

        if(!cp1 || !cp2) printf("T\n");
        else if(cp1!=cp2) printf("T\n");
        else
        {
            cp1=check(x2, y1, lx1,ly1,lx2,ly2);
            cp2=check(x1, y2, lx1,ly1,lx2,ly2);

            if(!cp1 || !cp2) printf("T\n");
            else if(cp1!=cp2) printf("T\n");
            else printf("F\n");
        }
        n--;
    }
    return 0;
}
