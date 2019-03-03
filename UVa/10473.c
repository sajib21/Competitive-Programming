#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int l, i, dec;
    char n[12];
    while(1)
    {
        gets(n);
        if(n[0]=='-') break;

        l=strlen(n);
        if(n[0]=='0' && n[1]=='x')
        {
            dec=0;
            for(i=2;i<l;i++)
            {
                if(n[i]=='A') dec=dec*16+10;
                else if(n[i]=='B') dec=dec*16+11;
                else if(n[i]=='C') dec=dec*16+12;
                else if(n[i]=='D') dec=dec*16+13;
                else if(n[i]=='E') dec=dec*16+14;
                else if(n[i]=='F') dec=dec*16+15;
                else dec=dec*16+n[i]-'0';
            }
            printf("%d\n",dec);
        }
        else printf("0x%X\n", atoi(n));
    }
    return 0;
}
