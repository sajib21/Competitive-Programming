#include <stdio.h>

int main()
{
    long long int t,T, w, a;
    scanf("%lld", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld", &w);
        if(w%2) printf("Case %d: Impossible\n", t);
        else
        {
            a=1;
            while(!(w%2))
            {
                w/=2;
                a*=2;
            }
            printf("Case %lld: %lld %lld\n",t, w, a);
        }
    }
    return 0;
}
