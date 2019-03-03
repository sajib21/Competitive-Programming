#include <stdio.h>
#include <string.h>
int main()
{
    int a,j,i,size;
    char n[1000];
    while(scanf("%s",&n)!=0){
        if((n[0]-'0')==0){
            break;
        }
        size = strlen(n);
        j=0;
        for(i = 0;i<size; i++) {
            j =(j*10+n[i]-'0')%17;
        }
        if(j==0){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
