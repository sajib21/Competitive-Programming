#include <stdio.h>

///KADANE'S ALGO TO GET MAX SUM SUB ARRAY

int main()
{
    int n, max=0, temp=0, a, i;
    while(scanf("%d", &n) && n)
    {
        max=0;
        temp=0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &a);
            temp+=a;

            if(temp<0) temp=0;

            if(temp>max)
            {
                max=temp;
            }

        }
        if(temp>max)
        {
            max=temp;
        }
        if(max>0) printf("The maximum winning streak is %d.\n", max);
        else printf("Losing streak.\n");
    }
    return 0;
}
