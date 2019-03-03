#include <stdio.h>

int main()
{
    long long int n,r, p;
    while((scanf("%lld %lld", &n, &r))==2)
    {
        p=1;
        while(r)
        {
            p=p*n;
            while((p%10)==0) p=p/10;
            if(p>10000000000) p=p%10000000000;
            n--;
            r--;
        }
        printf("%lld\n", p%10);
    }
    return 0;
}
