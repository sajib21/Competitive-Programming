#include <stdio.h>

int cyc_len(int n)
{
    int count= 1;
    for(;n!=1;){
        if(n % 2 == 0){
        n=n/2;
        count++;
        }
        else{
            n=3*n+1;
            count++;
        }
     }
     return count;
}

main()
{
    int ans,i,j,a,p,temp=0,k;
    while((scanf("%d %d",&i,&j))!= EOF){
        temp=0;
        if(i>j){
            p=i;
            i=j;
            j=p;
            for(k=i;k<=j;k++){
                a= cyc_len(k);
                if(a>temp){
                    temp=a;
                }
            }
            printf("%d %d %d\n",j,i,temp);
        }
        else{
            for(k=i;k<=j;k++){
                a= cyc_len(k);
                if(a>temp){
                    temp=a;
                }
            }
            printf("%d %d %d\n",i,j,temp);
        }
    }
    return 0;
}
