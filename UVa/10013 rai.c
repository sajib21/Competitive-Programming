#include <stdio.h>
int a1[2000000],a2[2000000],a3[2000000];
int main()
{
    long int i,j,m,t,d,r;
    (scanf("%ld",&t);

        for(i=0; i<t; i++)
        {
            scanf("%ld",&m);
            {
                for(j=0; j<m; j++)
                {
                    scanf("%d%d",&a1[j],&a2[j]);
                }
                r=0;
                for(j=m-1; j>=0; j--)
                {
                    d=a1[j]+a2[j]+r;
                    if(d>9)
                    {
                        a3[j]=d-10;
                        r=1;
                    }
                    else
                    {
                        a3[j]=d;
                        r=0;
                    }
                }
                for(j=0; j<m; j++)
                {
                    printf("%d",a3[j]);
                }
                printf("\n");
                if(i!=t-1)
                {
                    printf("\n");
                }
            }
        }
    return 0;
}
