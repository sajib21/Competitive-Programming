#include <stdio.h>
#include <string.h>

int main()
{
    char s[500000],t[500000];
    int i,j;
    while((scanf("%s %s", s,t))!=EOF)
    {
        int lens=strlen(s), len=strlen(t)-lens;
        int count=0, js;

        j=0;
        for(i=0; i<lens; i++)
        {
            js=len+i;
            for(; j<=js; j++)
            {
                if(s[i]==t[j])
                {
                    count++;
                    j++;
                    break;
                }
            }
            if(count!=i+1)
            {
                printf("No\n");
                break;
            }
        }
        if(count==lens) printf("Yes\n");
    }
    return 0;
}
