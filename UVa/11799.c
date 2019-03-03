#include <stdio.h>

int main()
{
    int t,i, n, h,s;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d", &n);
        scanf("%d", &h);
        while(n>1)
        {
            scanf("%d", &s);
            if(s>h) h=s;
            n--;
        }
        printf("Case %d: %d\n", i, h);
    }
    return 0;
}
