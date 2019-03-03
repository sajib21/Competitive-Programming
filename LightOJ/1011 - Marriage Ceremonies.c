#include <stdio.h>

int mat[17][17], n;

int maxcomb()
{
    int i, sum=0;
    int flag[17];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(!flag[j])
            {
                sum=mat[i][j];
            }
        }
    }
}

int main()
{
    int t,T,i,j;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++) for(j=0; j<n; j++) scanf("%d", &mat[i][j]);

    }
}
