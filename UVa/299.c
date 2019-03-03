#include <stdio.h>

int main()
{
    int t, n,i,j, count, temp;
    scanf("%d", &t);
    while(t)
    {
        count=0;
        scanf("%d", &n);
        int ara[n];
        for(i=0; i<n; i++) scanf("%d", &ara[i]);
        for(i=0;i<n-1; i++) for(j=i+1; j<n; j++) if(ara[i]>ara[j])
        {
            count++;
            temp=ara[i];
            ara[i]=ara[j];
            ara[j]=temp;
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
        t--;
    }
    return 0;
}
