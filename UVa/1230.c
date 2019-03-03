#include <stdio.h>

long long int bigmod (long long int b, long long int p, long long int m)
{
    long long int r;

            if(!p) return 1;
            else if(p%2)
            {
                p=p-1;
                return (bigmod(b,p,m)*(b%m))%m;
            }
            else
            {
                p=p/2;
                r=bigmod(b,p,m);
                return ((r%m)*(r%m))%m;
            }
}

int main()
{
    long long int b,p,m;
    long long int n;
    scanf("%lld", &n);
    while(n)
    {
        scanf("%lld %lld %lld", &b,&p,&m);
        printf("%lld\n", bigmod(b,p,m));
        n--;
    }
    return 0;
}
