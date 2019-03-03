#include <stdio.h>
#include <string.h>

int main()
{
    char str[6];
    int n=1;

    while(n)
    {
        gets(str);
        if(strcmp(str, "*")==0) break;
        else if(!strcmp(str, "Hajj")) printf("Case %d: Hajj-e-Akbar\n", n);
        else printf("Case %d: Hajj-e-Asghar\n", n);
        n++;
    }
    return 0;
}
