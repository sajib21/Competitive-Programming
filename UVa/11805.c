#include <stdio.h>

int main()
{
    int t,i, n, k, p, f;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d", &n, &k, &p);
        f= (p%n) + k;
        if(f>n) printf("Case %d: %d\n", i, f-n);
        else printf("Case %d: %d\n", i, f);
    }
    return 0;
}
