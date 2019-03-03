#include <stdio.h>

int main()
{
    int n, m;
    int val, ex, i,j;
    scanf("%d", &n);
    while(n)
    {
        scanf("%d", &m);
        int num1[2000000], num2[2000000];
        int sum[2000000];
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &num1[i], &num2[i]);
        }
        ex=0;
        i=m-1;
        while(i>=0)
        {
            val=num1[i]+num2[i]+ex;
            ex=0;
            if(val<10) sum[i]=val;
            else
            {
                ex++;
                sum[i]=val-10;
            }
            i--;
        }
        if(ex)
        {
            printf("%d", ex);
            for(i=0; i<m; i++) printf("%d", sum[i]);
            putchar('\n');
        }
        else
        {
            for(i=0; i<m; i++)
            {
                if(sum[i]==0) continue;
                else
                {
                    for(j=i; j<m; j++) printf("%d", sum[j]);
                    putchar('\n');
                    break;
                }
            }
        }
        n--;

        if(n) putchar('\n');
    }
    return 0;
}
