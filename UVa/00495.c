#include <stdio.h>

int main()
{
    int n;

    while(scanf("%d", &n)!=EOF)
    {

        unsigned long long int s=0, i=-1, j=1, k=0;
        while(s<=n)
        {
        k=i+j;
        i=j;
        j=k;
        s++;
        }
    printf("%lld\n", k);
    }

    return 0;
}
