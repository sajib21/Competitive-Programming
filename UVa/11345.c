#include <stdio.h>

int main()
{
    int t,i, m ;
    scanf("%d", &t);

    for(i=1; i<=t; i++)
    {
        int x1=-10000,y1=-10000, x2=10000,y2=10000, xt1,yt1,xt2,yt2;
        scanf("%d", &m);
        while(m)
        {
            scanf("%d %d %d %d", &xt1, &yt1, &xt2, &yt2);
            if(xt1>x1) x1=xt1;
            if(yt1>y1) y1=yt1;
            if(xt2<x2) x2=xt2;
            if(yt2<y2) y2=yt2;
            m--;
        }
        if(x2<=x1 || y2<=y1) printf("Case %d: %d\n",i, 0);
        else printf("Case %d: %d\n", i, (x2-x1)*(y2-y1));
    }
    return 0;
}
