#include <stdio.h>

int main()
{
    int n, k, t, r;

    while((scanf("%d %d", &n, &k))!=EOF)
    {
        t=0;
        r=0;
        while(n>0)
        {
            t=t+n;
            n=(n+r)/k;
            r=n%k;
        }
        printf("%d\n", t);
    }
    return 0;
}
