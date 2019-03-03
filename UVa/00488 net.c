#include<stdio.h>
int main()
{
int n,a,f,i,j,k,t;
while(scanf("%d",&n)==1)
    {
    for(t=0;t<n;t++)
        {
        scanf("%d %d",&a,&f);
        for(k=0;k<f;k++)
            {
            for(i=0;i<a;i++)
                {
                for(j=0;j<i+1;j++)
                    {
                    printf("%d",i+1);
                    }
                printf("\n");
                }
            for(i=a;i>1;i--)
                {
                for(j=i-1;j>0;j--)
                    {
                    printf("%d",i-1);
                    }
                printf("\n");
                }
            if(t!=n-1 || k!=f-1) printf("\n");
            }
        }
    }
return 0;
}
