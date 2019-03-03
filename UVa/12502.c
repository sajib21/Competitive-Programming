#include <stdio.h>

int main()
{
    int t, x,y,z;
    scanf("%d", &t);
    while(t)
    {
        scanf("%d %d %d", &x, &y, &z);
        printf("%d\n", z*(2*x-y)/(x+y));
        t--;
    }
    return 0;
}
