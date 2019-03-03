#include <stdio.h>
#include <string.h>
int main()
{
    char j,i,size;
    char n[102];
    while(scanf("%s",&n)){
        if((n[0]=='0') && n[1]=='\0'){
            break;
        }
        size = strlen(n);
        j=0;
        for(i = 0;i<size; i++) {
            j = (j*10+n[i]-'0')%17;
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
