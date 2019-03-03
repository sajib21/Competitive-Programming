#include <stdio.h>

int main()
{
    unsigned long long int n, ans;
    while(scanf("%llu", &n)!=EOF)
    {

        if(n==0) break;
        ans=10*n/9;
        if(!(n%9)) printf("%llu %llu\n", ans-1, ans);
        else printf("%llu\n", 10*n/9);
    }
    return 0;
}
