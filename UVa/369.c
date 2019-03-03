#include <stdio.h>

int main()
{
    long long int n,k,k1;
    while((scanf("%lld %lld", &n, &k))==2)
    {
        if(!n && !k) break;

        k1=n-k;
        if(k1>k) k1=k;

        if(k1==0 || n==k1)
        {
            printf("%lld things taken %lld at a time is 1 exactly.\n",n,k);
            continue;
        }

        double comb=1.0, i;
        for (i = 1.0; i <= k1; i++)
        {
            comb*= (n - k1 + i);
            comb/=i;
        }

        printf("%lld things taken %lld at a time is %.0lf exactly.\n",n,k, comb);
    }
    return 0;
}
