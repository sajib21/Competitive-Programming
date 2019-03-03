#include <stdio.h>

int main()
{
    int n,i, r, x1, x2, y;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &r);
        x1=-1*9*r/4;
        x2=11*r/4;
        y=3*r/2;

        printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n", i, x1, y, x2, y, x2, -1*y, x1, -1*y);
    }
    return 0;
}
