#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, ra, rb;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(!a && !b) break;

        ra=sqrt(a-1);
        rb=sqrt(b);

        printf("%d\n", rb-ra);
    }
    return 0;
}
