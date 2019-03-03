#include <stdio.h>
#include <string.h>

int main()
{
    char i;
    char ch;
    int len;
    while(scanf("%c", &ch)) ///better algo but they made the EOF in a way which work only with scanf(%s)
    {
        if(ch=='\n') putchar(ch);
        else putchar(ch-7);
    }
    return 0;
}
