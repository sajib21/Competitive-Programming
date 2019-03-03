#include <stdio.h>

int main()
{
    long long int t,T, n, i,j,x, fact[25]={1,1}, ans[22];
    for(i=2; i<21; i++) fact[i]=fact[i-1]*i;
    scanf("%lld", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld", &n);
        i=20; x=0;
        while(i>=0 && n)
        {
            if(fact[i]<=n)
            {
                ans[x++]=i;
                n-=fact[i];
            }
            i--;
        }

        printf("Case %lld: ", t);

        if(!n)
        {
            x--;
            printf("%lld!", ans[x--]);
            while(x>=0) printf("+%lld!", ans[x--]);
            printf("\n");
        }
        else printf("impossible\n");
    }
    return 0;
}
