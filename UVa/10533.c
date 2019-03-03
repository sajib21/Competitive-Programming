#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i;

    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int digit_sum(int n)
{
    int t=0;
    while(n)
    {
        t=t+n%10;
        n=n/10;
    }
    return t;
}

int main()
{
    int n, t1, t2, x;
    scanf("%lld", &n);

    while(n)
    {
        int count=0;
        scanf("%d %d", &t1, &t2);
        for(x=t1; x<=t2; x++) if(is_prime(x)==1) if(is_prime(digit_sum(x))==1) count++;

        printf("%d\n", count);
        n--;
    }
    return 0;
}
