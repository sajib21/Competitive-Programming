#include <stdio.h>
int main()
{
    int t,k,n,p,q,i,a[32],sum;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d %d",&n,&p,&q);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     for(i=0,sum=0;i<n;i++)
     {
         if(i>=p || sum+a[i]>q) break;
         else sum+=a[i];
     }


         printf("Case %d: %d\n",k,i);

    }
    return 0;
}
