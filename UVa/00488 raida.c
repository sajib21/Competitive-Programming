#include <stdio.h>
int main()
{
    int a,f,t,i,j,k,l;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d",&a,&f);
        for(k=1;k<=f;k++){
            for(j=1;j<=a;j++){
                for(l=1;l<=j;l++){
                    printf("%d",j);
                }
                printf("\n");
        }
            for(j=a-1;j>=1;j--){
                for(l=1;l<=j;l++){
                    printf("%d",j);
                }
                printf("\n");
            }
            if(i!=t || k!=f){
                printf("\n");
            }
        }
    }
    return 0;
}
