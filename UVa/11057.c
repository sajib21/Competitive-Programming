#include <stdio.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int n,i,j, m,m2, t, a,b;
    while((scanf("%d", &n))!=EOF)
    {
        int bk[n];
        for(i=0; i<n; i++) scanf("%d", &bk[i]);
        scanf("%d", &m);
        qsort(bk, n, sizeof(int), cmpfunc);
        m2=m/2;

        i=0;
        while(bk[i]<=m2)
        {
            t=m-bk[i];
            for(j=i+1; j<n; j++)
            {
                if(bk[j]==t)
                {
                    a=bk[i];
                    b=bk[j];
                    break;
                }
            }
            i++;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", a,b);
    }
    return 0;
}
