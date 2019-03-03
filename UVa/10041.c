#include <stdio.h>
#include <math.h>

int main()
{
    int t, n, i,j, temp, sum;
    scanf("%d", &t);

    while(t)
    {
        scanf("%d", &n);
        int r[n];

        for(i=0; i<n; i++) scanf("%d", &r[i]);

        for(i=0; i<n-1; i++) for(j=i+1; j<n; j++) if(r[i]<r[j])
        {
            temp=r[i];
            r[i]=r[j];
            r[j]=temp;
        }
        temp=r[n/2];
        sum=0;
        for(i=0; i<n; i++) sum=sum+fabs(r[i]-temp);

        printf("%d\n", sum);

        t--;
    }
}
