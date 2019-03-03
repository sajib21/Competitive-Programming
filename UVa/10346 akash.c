#include <stdio.h>

int main()
{
    int n, k;

    while((scanf("%d %d", &n, &k))!=EOF)
    {
        printf("%d\n", n+ (n-1)/(k-1));
    }
    return 0;
}
