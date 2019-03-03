#include <stdio.h>

int main()
{
    int t,i, press;
    char c;
    scanf("%d", &t);
    getchar();
    for(i=1; i<=t; i++)
    {

        c=1;
        press=0;
        while(c!='\n')
        {
            scanf("%c", &c);
            if(c==' ' || c=='a' || c=='d' || c=='g' || c=='j' || c=='m' || c=='p' || c=='t' || c=='w') press++;
            else if(c=='b' || c=='e' || c=='h' || c=='k' || c=='n' || c=='q' || c=='u' || c=='x') press+=2;
            else if(c=='c' || c=='f' || c=='i' || c=='l' || c=='o' || c=='r' || c=='v' || c=='y') press+=3;
            else if(c=='s' || c=='z' ) press+=4;
        }
        printf("Case #%d: %d\n", i, press);
    }
    return 0;
}
