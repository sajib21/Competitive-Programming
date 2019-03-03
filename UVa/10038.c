#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    long long int d;

    while((scanf("%d", &n))==1)
    {
        int num[n];
        int dif[n-1];
        for(i=0; i<n; i++) scanf("%d", &num[i]);

        if(n==1) printf("Jolly\n");

        for(i=0; i<n-1; i++) dif[i]=0;

        for(i=1; i<n; i++)
        {
            d=fabs(num[i]-num[i-1]);
            if(d>n-1 || d==0)
            {
                printf("Not jolly\n");
                break;
            }
            else if(dif[d]==1)
            {
                dif[d]++;
                printf("Not jolly\n");
                break;
            }
            else dif[d]=1;
        }
        if(d<n && dif[d]==1) printf("Jolly\n");
    }
    return 0;
}
