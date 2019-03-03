#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        int i, root=sqrt(n), check=0, rev=0, temp=n;
        for(i=2; i<=root; i++)
        {
            if(!(n%i))
            {
                check++;
                printf("%d is not prime.\n", temp);
                break;
            }
        }
        if(!check)
        {
            while(n)
            {
                rev=rev*10+n%10;
                n=n/10;
            }
            if(rev!=temp)
            {
            root=sqrt(rev), check=0;
            for(i=2; i<=root; i++)
            {
                if(!(rev%i))
                {
                    check++;
                    printf("%d is prime.\n", temp);
                    break;
                }
            }
            if(!check) printf("%d is emirp.\n", temp);
            }
            else printf("%d is prime.\n", temp);
        }
    }
    return 0;
}
