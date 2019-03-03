#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char num[1000] ;
    int n, d;

        while((gets(num)))
        {
            if(num[0]-'0'==0 && num[1]=='\0') break;
            n=strlen(num);
            d=(num[n-1]-'0');
            num[n-1]='\0';
            if((atoi(num)-5*d)%17==0) printf("1\n");
            else printf("0\n");
        }
    return 0;
}
