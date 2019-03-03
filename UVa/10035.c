#include <stdio.h>

int main()
{
    unsigned long int a,b;
    while(1)
    {
        unsigned long int count=0, temp=0;
        scanf("%lu %lu", &a, &b);
        if(!a && !b) break;

        while(a || b)
        {
            if(a%10+b%10+temp<10) temp=0;
            else
            {
                count++;
                temp=1;
            }
            a=a/10;
            b=b/10;
        }

        if(!count) printf("No carry operation.\n");
        else if(count==1) printf("1 carry operation.\n");
        else printf("%lu carry operations.\n", count);
    }
    return 0;
}
