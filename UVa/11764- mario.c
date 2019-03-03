#include <stdio.h>

int main()
{
    int t,i, w, h,next, high, low;
    scanf("%d", &t);
    for(i=1;i<=t; i++)
    {
        high=0;
        low=0;
        scanf("%d", &w);
        scanf("%d", &h);
        while(w>1)
        {
            scanf("%d", &next);
            if(next>h) high++;
            else if(next<h) low++;
            h=next;
            w--;
        }
        printf("Case %d: %d %d\n", i, high, low);
    }
    return 0;
}
