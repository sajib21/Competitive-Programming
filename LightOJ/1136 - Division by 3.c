#include <stdio.h>

int main()
{
    long long int t,T, a,b;
    scanf("%lld", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld", &a, &b);
        a--;

        printf("Case %lld: %lld\n",t, (b*2)/3 - (a*2)/3);
    }
    return 0;
}
