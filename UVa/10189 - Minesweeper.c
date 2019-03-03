#include <stdio.h>

int f[105][105], ans[105][105];
int main()
{
    int n,m, i,j, t=1;
    char c;

    while(scanf("%d %d", &n, &m) && n && m)
    {
        getchar();
        if(t!=1)
            printf("\n");
        for(i=1; i<=n; i++)
        {
            f[i][0]=0;
            for(j=1; j<=m; j++)
            {
                scanf("%c", &c);
                if(c!='*') f[i][j]=0;
                else f[i][j]=1;
            }
            getchar();
            f[i][m+1]=0;
        }
        for(j=0; j<=m; j++) f[i][j]=0;
        f[i][m+1]=0;

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(!f[i][j])
                {
                    ans[i][j]=f[i-1][j-1]+f[i-1][j]+f[i-1][j+1] + f[i][j-1]+f[i][j]+f[i][j+1] + f[i+1][j-1]+f[i+1][j]+f[i+1][j+1];
                }
            }
        }

        printf("Field #%d:\n", t++);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {

                if(!f[i][j]) printf("%d", ans[i][j]);
                else printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
