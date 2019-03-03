#include<stdio.h>
#include<ctype.h>
#include <string.h>
char ch, last;
int main()
{
    while(scanf("%c", &ch)==1)
    {
        if(isalpha(ch))
        {
                if(ch=='A' ||ch=='E' ||ch=='I' ||ch=='O' ||ch=='U' ||ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u')
                {
                    while(isalpha(ch))
                    {
                        putchar(ch);
                        ch=getchar();
                    }
                    printf("ay");
                }
                else
                {
                    last=ch;
                    ch=getchar();
                    while(isalpha(ch))
                    {
                        putchar(ch);
                        ch=getchar();
                    }
                    printf("%cay", last);
                }
        }
        putchar(ch);
    }
}
