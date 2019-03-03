#include <stdio.h>

int rung[100005], height[100005], time[10000007];

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int high(int check, int max)
{
    int i,j;
    if(!check || !time[check]) return max;
    else if(time[check]>1) return max+1;
    else if(time[check]==1)
    {
        return high(check-1, max);
    }
}

int main()
{



    int t,T, n, i,j, max, h,co;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        max=0;
        scanf("%d", &n);
        for(i=1, j=0; i<=n; i++)
        {
            scanf("%d", &rung[i]);
            h=rung[i]-rung[i-1];
            if(!time[h])
            {
                j++;
                height[j]=h;
                if(h>max)
                {
                    max=h;
                    co=j-1;
                }
            }
            time[h]++;
        }

        for(i=1; i<=co; i++)
        {
            time[height[i]]--;
            height[i]=0;
        }

        qsort(height, j+1, sizeof(int), cmpfunc);

        printf("Case %d: %d\n", t, high( height[j], height[j]));

        for(i=0; i<=n+20; i++)
        {
            time[height[i]]=0;
            height[i]=0;
        }

        for(i=0; i<=20; i++) printf("%d ", time[i]);
        printf("\n");

    }
    return 0;
}
