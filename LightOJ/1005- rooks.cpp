#include <stdio.h>

long long int choose(long long int n,long long int r,long long int k)
{
    long long int c=1;
    while(r<=k)
    {
        c=c * n/r*n;
        n--; r++;

    }
    return c;
}

int main()
{
    long long int t,T, n,k;
    scanf("%lld", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld", &n, &k);
        if(k>n) printf("Case %d: 0\n", t);
        else printf("Case %lld: %lld\n",t, choose(n,1,k));
    }

    return 0;
}
