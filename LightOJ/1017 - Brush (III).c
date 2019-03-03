#include <stdio.h>

int hori[105], n;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int rec(int a, int w)
{
    int sum=0, i, max=0;
    if(a>=n) return 0;
    for(i=a; i<n; i++ )
    {
        sum = hori[i] + rec(i+w, w);
        if(sum>max) max=sum;
    }
    return max;
}

int main()
{
    int t,T,w,k, i,j, y[105], x, wid, lim, moves, sum;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %d %d", &n, &w, &k);
        for(i=0; i<n; i++) scanf("%*d %d", y[i]);

        qsort(y, n, sizeof(int), cmpfunc);

        for(i=0, x=0; ; x++)
        {
            wid=y[i]+w-1;
            for(j=i+1; j<n; j++)
            {
                if(y[j]>wid)
                {
                    hori[x]=j-i;
                    i=j;
                    break;
                }
            }
            if(j==n)
            {
                hori[x]=j-i;
                break;
            }
        }

        for(i=0, lim= n - w*(k-1) ; i<lim; i++)
        {
            sum=hori[i];
            for(moves=1; moves<k; moves++)
            {
                for(j=i+ moves*w; j<lim+w*moves; j++)
            }


        }

    }

    return 0;
}
