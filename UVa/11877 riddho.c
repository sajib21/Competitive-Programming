#include <stdio.h>
int main(){
    int n;
    int c=0;
    while(scanf("%d",&n)==1){
        if(n==0)
        break;
        c=0;
        while(n>=3){

            n=n-3;
            c++;
            n++;
            }
    if(n==2)
        printf("%d\n",(c+1));
    else
        printf("%d\n",c);
    }
return 0;
}
