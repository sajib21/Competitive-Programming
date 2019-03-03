#include <stdio.h>

int banana[202][102];

int main()
{
    int n,t,T , i,j, k;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d", &n);
        scanf("%d", &banana[0][0]);

        scanf("%d", &banana[1][0]);
        banana[1][0]+=banana[0][0];

        scanf("%d", &banana[1][1]);
        banana[1][1]+=banana[0][0];

        for(i=2; i<n; i++)
        {
            scanf("%d", &banana[i][0]);
            banana[i][0]+=banana[i-1][0];
            for(j=1; j<i; j++)
            {
                scanf("%d", &banana[i][j]);
                if(banana[i-1][j-1]>banana[i-1][j]) banana[i][j]+=banana[i-1][j-1];
                else banana[i][j]+=banana[i-1][j];
            }
            scanf("%d", &banana[i][i]);
            banana[i][i]+=banana[i-1][i-1];
        }
        for(i=n-2, k=n; i>=0 ; i--, k++)
        {
            for(j=0; j<=i; j++)
            {
                scanf("%d", &banana[k][j]);
                if(banana[k-1][j]>banana[k-1][j+1]) banana[k][j]+=banana[k-1][j];
                else banana[k][j]+=banana[k-1][j+1];
            }
        }
        /*for(i=0; i<n; i++)
        {
            for(j=0; j<=i; j++) printf("%d ", banana[i][j]);
            printf("\n");
        }
        for(i=n-2, k=n; i>=0 ; i--, k++)
        {
            for(j=0; j<=i; j++) printf("%d ",banana[k][j]);
            printf("\n");
        }*/

        printf("Case %d: %d\n", t, banana[2*n-2][0]);
    }

    return 0;
}
