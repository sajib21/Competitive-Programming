#include <stdio.h>

unsigned long int chkpal(unsigned long int n)
{
    unsigned long int i,j=0, ara[10];
    for(i=0; i<10; i++)
    {
        ara[i]=n%10;
        n=n/10;
        if(!n) break;
    }
    while(j<i)
    {
        if(ara[j]!=ara[i]) return 0;
        j++;
        i--;
    }
    return 1;
}

unsigned long int reverse(unsigned long int n)
{
    unsigned long int rev=0;
    while(n)
    {
        rev=rev*10+(n%10);
        n=n/10;
    }
    return rev;
}

int main()
{
    unsigned long int t, n, rev, count;
    scanf("%lu", &t);
    while(t)
    {
        count=0;
        scanf("%lu", &n);

        while(!chkpal(n))
        {
            rev=reverse(n);

            n=n+rev;
            count++;
        }
        printf("%lu %lu\n",count, n);
        t--;
    }
}
