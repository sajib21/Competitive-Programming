#include <stdio.h>

int main()
{
    int n,i, c, df, cn;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d", &c, &df);
        printf("Case %d: %.2lf\n", i, df*5.0/9.0+c);
    }
    return 0;
}
