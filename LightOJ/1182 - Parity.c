#include <stdio.h>

int main()
{
    long long int t,T, n, sum;
    scanf("%lld", &T);
    for(t=1; t<=T; t++)
    {
        sum=0;
        scanf("%lld", &n);
        while(n)
        {
            if(n%2) sum++;
            n/=2;
        }
        if(sum%2) printf("Case %lld: odd\n",t);
        else printf("Case %lld: even\n", t);
    }
    return 0;
}
