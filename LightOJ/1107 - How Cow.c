#include <stdio.h>

int main()
{
    int t,T, n, x1,y1,x2,y2, x,y;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
        scanf("%d", &n);

        printf("Case %d:\n", t);

        while(n--)
        {
            scanf("%d %d", &x,&y);
            if(x1<x && x<x2 && y1<y && y<y2) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
