#include <stdio.h>

int main()
{
    int t,i, n, a,b, j, rt, count;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d", &n);
        count=0;
        printf("Case #%d: %d",i,n);


        for(j=2; j<=n; j++)
        {
            if(!(n%j))
            {
                printf(" = %d * %d", j,n/j);
                count++;
            }
            if(count==2)
            {
                break;
            }
        }
        putchar('\n');
    }
    return 0;

}
