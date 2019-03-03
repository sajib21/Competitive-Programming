#include <stdio.h>

int main()
{
    long long int i, j, k, n, ansa, ansm;

    while(scanf("%lld", &n))
    {
        if(n==-1) break;
        ansa=1;
        ansm=0;
        i=0;
        j=1;
        while(n)
        {
            k=i+j;
            i=j;
            j=k;
            ansm=ansa;
            ansa=ansa+k;
            n--;
        }

        printf("%lld %lld\n",ansm, ansa);
    }
    return 0;
}
