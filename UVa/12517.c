#include <stdio.h>

int main()
{
    int m, n,i;
    while((scanf("%d %d", &m, &n)))
    {
        if(!m && !n) break;
        int sum=0;
        for(i=m; i<=n; i++)
        {
            m=i;
            while(m)
            {
                sum=sum+m%10;
                m=m/10;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
