#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int ara[2000005];
main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        for(i=0;i<n;i++){
            scanf("%d",&ara[i]);
        }
        qsort(ara, n, sizeof(int), cmpfunc);
        printf("%d",ara[0]);
        for(i=1;i<n;i++){
            printf(" %d",ara[i]);
        }
        printf("\n");
    }
    return 0;
}
