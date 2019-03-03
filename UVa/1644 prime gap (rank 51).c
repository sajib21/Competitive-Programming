#include <stdio.h>

int isprime(int n)
{
    int  i;
    for(i=2; i*i<=n; i++)  if(!(n%i)) return 0;
    return 1;
}
int main()
{
    int n, temp;
    while((scanf("%d", &n)))
    {
        if(n==0) break;
        if(!isprime(n))
        {
            if(n%2)
            {
                temp=n+2;
                while(!isprime(temp)) temp=temp+2;
                n=n-2;
                while(!isprime(n)) n=n-2;
            }
            else
            {
                temp=n+1;
                while(!isprime(temp)) temp=temp+2;
                n=n-1;
                while(!isprime(n)) n=n-2;
            }
            printf("%d\n", temp-n);
        }
        else printf("0\n");
    }
    return 0;
}
