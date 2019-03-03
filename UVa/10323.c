#include <stdio.h>

int main()
{
    long long int n, f;
    while((scanf("%lld", &n))!=EOF)
    {
        if(n<0)
        {
            if(((n)%2)) printf("Overflow!\n");
            else printf("Underflow!\n");
        }
        else
        {
            if(n>=8.0 && n<=13.0)
            {
                f=1;
                while(n)
                {
                    f=f*n;
                    n--;
                }
                printf("%lld\n", f);
            }
            else if(n<8.0) printf("Underflow!\n");
            else  printf("Overflow!\n");
        }
    }
    return 0;
}
