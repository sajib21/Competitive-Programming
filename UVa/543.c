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
    int n, b,a;

    while(1)
    {
        scanf("%d", &n);
        if(!n) break;
        b=n-3;
        a=3;
        while(b>=a)
        {
            if(!(isprime(b)) || !(isprime(a)))
            {
                b=b-2;
                a=a+2;
            }
            else break;
        }
        if(b>=a) printf("%d = %d + %d\n", n, a, b);
    }
    return 0;
}
