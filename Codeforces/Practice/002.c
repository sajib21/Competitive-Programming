#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld", &n);
    if(n%2) printf("-%lld\n", (n+1)/2 );
    else printf("%lld\n", (n+1)/2);

    return 0;
}
