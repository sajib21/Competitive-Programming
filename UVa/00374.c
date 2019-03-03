#include <stdio.h>

int main()
{
    long long int b,p,m;
    long long int r;

    while((scanf("%lld %lld %lld", &b, &p, &m))==3)
    {

        r=1;
        while(p)
        {
            r=((r*b)%m);
            p--;
        }
        printf("%lld\n", r);
    }
    return 0;
}
