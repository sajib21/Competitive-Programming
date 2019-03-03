#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char word[10];
    scanf("%d", &n);
    while(n)
    {
        scanf("%s", &word);
        if(strlen(word)==5) printf("3\n");
        else
        {
            int o=0, t=0;
            for(i=0; i<strlen(word); i++)
            {
                if(word[i]=='o' || word[i]=='n' || word[i]=='e') o++;
                else if(word[i]=='t' || word[i]=='w' || word[i]=='o') t++;
            }
            if(o>t) printf("1\n");
            else printf("2\n");
        }
        n--;
    }
    return 0;

}
