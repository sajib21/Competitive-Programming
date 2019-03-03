#include <stdio.h>

int main()
{
    int T ,i, j, n, o, len, max;

    while ((scanf("%d %d", &i, &j))!=EOF)
    {
        max=0;
        if(i<j)
        {
            for(n=i; n<=j; n++)
            {
                len=1;
                o=n;
                while(o!=1)
                {
                    if(o%2==1) o=3*o+1;
                    else o=o/2;
                    len++;
                }
                if(len>max) max=len;
            }
            printf("%d %d %d\n", i, j, max);
        }
        else
        {
            for(n=j; n<=i; n++)
            {
                len=1;
                o=n;
                while(o!=1)
                {
                    if(o%2==1) o=3*o+1;
                    else o=o/2;
                    len++;
                }
                if(len>max) max=len;
            }
            printf("%d %d %d\n", i, j, max);
        }
    }
    return 0;
}
