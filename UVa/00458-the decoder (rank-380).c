#include <stdio.h>
#include <string.h>

int main()
{
    char i;
    char ch[80];
    char len;
    while(gets(ch))
    {
        len=strlen(ch);
        for(i=0; i<len; i++)
        {
            ch[i]=ch[i]-7;
        }
        puts(ch);
    }
    return 0;
}
