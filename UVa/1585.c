#include <stdio.h>

int main()
{
    int mark, i,t,count;
    char s[80];
    scanf("%d", &t);

    while(t)
    {
        scanf("%s", s);
        i=0;
        count=1;
        mark=0;
        while(s[i]!='\0')
        {
            if(s[i]=='O')
            {
                mark+=count;
                count++;
            }
            else count=1;
            i++;
        }
        printf("%d\n",mark);
        t--;
    }

}
