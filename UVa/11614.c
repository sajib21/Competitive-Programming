#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    long long int n, i;
    scanf("%d", &t);
    while(t)
    {
        scanf("%lld", &n);
        i=(-1+sqrt(1+8*n))/2;
        printf("%lld\n",i);
        t--;
    }
    return 0;
}
