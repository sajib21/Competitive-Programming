#include <stdio.h>
#include <string.h>

int main()
{
    char ch, last;
    while(scanf("%c", &ch)==1)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        {
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            {
                while((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
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
                while((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
                {
                    putchar(ch);
                    ch=getchar();
                }
                printf("%cay", last);
            }
        }
        putchar(ch);
    }
    return 0;
}
