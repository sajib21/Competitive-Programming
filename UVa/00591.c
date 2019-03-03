#include <stdio.h>

int main()
{
    int n, i=1, j, b, hos[50], count;

    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;

        b=0;
        count=0;
        for(j=0; j<n; j++)
        {
            scanf("%d", &hos[j]);
            b=b+hos[j];
        }
        b=b/n;
        for(j=0; j<n; j++) if(hos[j]>b) count=count+hos[j]-b;

        printf("Set #%d\n", i);
        printf("The minimum number of moves is %d.\n", count);
        printf("\n");

        i++;
    }
    return 0;
}
