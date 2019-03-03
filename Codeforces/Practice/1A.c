#include <stdio.h>


int main()
{
    long long int n,m,a;
    scanf("%lld %lld %lld", &n, &m, &a);

    printf("%lld\n", ((m+a-1)/a) * ((n+a-1)/a));

    return 0;
}
