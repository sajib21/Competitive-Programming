#include <stdio.h>
#include <math.h>

int main()
{
    int n, temp, i, root, isprime;
    while((scanf("%d", &n)))
    {
        if(n==0) break;

        root=sqrt(n);
        for(i=2; i<=root; i++)  if(!(n%i))
        {
            isprime=0;
            break;
        }
        if(n%i) isprime=1;

        if(!isprime)
        {
            if(n%2)
            {
                temp=n+2;
                root=sqrt(temp);
                for(i=2; i<=root; i++)  if(!(temp%i))
                {
                    isprime=0;
                    break;
                }
                if(temp%i) isprime=1;
                while(!isprime)
                {
                    temp=temp+2;
                    root=sqrt(temp);
                    for(i=2; i<=root; i++)  if(!(temp%i))
                    {
                        isprime=0;
                        break;
                    }
                    if(temp%i) isprime=1;
                }
                n=n-2;
                root=sqrt(n);
                for(i=2; i<=root; i++)  if(!(n%i))
                {
                    isprime=0;
                    break;
                }
                if(n%i) isprime=1;
                while(!isprime)
                {
                    n=n-2;
                    root=sqrt(n);
                    for(i=2; i<=root; i++)  if(!(n%i))
                    {
                        isprime=0;
                        break;
                    }
                    if(n%i) isprime=1;
                }
            }

            else
            {
                temp=n+1;
                root=sqrt(temp);
                for(i=2; i<=root; i++)  if(!(temp%i))
                {
                    isprime=0;
                    break;
                }
                if(temp%i) isprime=1;
                while(!isprime)
                {
                    temp=temp+2;
                    root=sqrt(temp);
                    for(i=2; i<=root; i++)  if(!(temp%i))
                        {
                            isprime=0;
                            break;
                        }
                    if(temp%i) isprime=1;
                }
                n=n-1;
                root=sqrt(n);
                for(i=2; i<=root; i++)  if(!(n%i))
                {
                    isprime=0;
                    break;
                }
                if(n%i) isprime=1;
                while(!isprime)
                {
                    n=n-2;
                    root=sqrt(n);
                    for(i=2; i<=root; i++)  if(!(n%i))
                    {
                        isprime=0;
                        break;
                    }
                    if(n%i) isprime=1;
                }
            }
            printf("%d\n", temp-n);
        }
        else printf("0\n");
    }
    return 0;
}
