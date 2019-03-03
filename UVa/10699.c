#include <stdio.h>
#include <math.h>
int main()
{
    int n, i,j, rt, count;

    while((scanf("%d", &n)))
    {
        count=0;
        j=n;
        if(!n) break;
        rt=n/2;
        for(i=2; i<=rt; i++)
        {
            if(j%i==0)
            {
                count++;
                while(!(j%i)) j=j/i;
            }
        }
        if(n==j) count++;
        printf("%d : %d\n", n, count);
    }
    return 0;
}
