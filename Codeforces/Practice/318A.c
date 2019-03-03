#include <stdio.h>

int main()
{
    long long int n, k, h;
    scanf("%lld %lld", &n, &k);

    h=(n+1)/2;

    if(k <= h) printf("%lld\n", 2*k - 1);
    else printf("%lld\n", 2*(k-h));

    return 0;
}
