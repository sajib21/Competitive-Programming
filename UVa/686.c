#include <stdio.h>
#include <math.h>

int isprime(int n)
{
    int i, rt=sqrt(n);
    for(i=2; i<=rt; i++) if(!(n%i)) return 0;
    return 1;
}

int main()
{
    int n, b,a, count;

    while(1)
    {

        scanf("%d", &n);
        if(!n) break;
        if(n==4)
        {
            printf("1\n");
            continue;
        }
        b=n-3;
        a=3;
        count=0;
        while(b>=a)
        {
            if((isprime(b)) && (isprime(a))) count++;
            b=b-2;
            a=a+2;
        }
        printf("%d\n", count);
    }
    return 0;
}
