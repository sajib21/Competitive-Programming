#include <stdio.h>

int main()
{
    int n, m;
    int val, ex, i,j;
    scanf("%d", &n);
    while(n)
    {
        scanf("%d", &m);
        int num1[m], num2[m];
        char sum[m+3];
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
            if(val<10) sum[i]=val+'0';
            else
            {
                ex++;
                sum[i]=val-10+'0';
            }
            i--;
        }
        sum[m]='\0';
        if(ex)
        {
            printf("1");
            puts(sum);
        }
        else
        {
            for(i=0; i<m; i++)
            {
                if(sum[i]=='0') continue;
                else
                {
                    for(j=i; j<m; j++) printf("%c", sum[j]);
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
