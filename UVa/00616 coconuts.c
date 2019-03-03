#include <stdio.h>
#include <math.h>

int main()
{
    int c,max,found = 0,i,j,ans;

    while(scanf("%d", &c)&&c!=-1)
    {
        found = 0 ;
        max = sqrt(c) +1;
        for(i = max ; i >= 2 ; i--)
        {
            ans = c;
            for(j = 0 ; j < i && ans%i ==1; j++)
            {
                ans -= ans / i + 1;
            }
            if(ans%i==0 && j==i)
            {
                found = 1;
                break;
            }
        }
        if(found)
        {
            printf("%d coconuts, %d people and 1 monkey\n", c,i);
        }
        else
        {
            printf("%d coconuts, no solution\n", c);
        }
    }
    return 0;
}
