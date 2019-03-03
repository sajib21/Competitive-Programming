#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    int div[100], rem, set, i, j, len ;
    char num[1002];
    scanf("%d", &t);

    while(t)
    {
        scanf("%s", num);
        len=strlen(num);
        scanf("%d", &set);

        for(i=0; i<set; i++) scanf("%d", &div[i]);

            rem=0;
            for(i=0; i<set; i++)
            {
                for(j=0; j<len; j++) rem=(rem*10+num[j]-'0')%div[i];
                if(rem)
                {
                    printf("%s - Simple.\n", num);
                    break;
                }
            }

        if(!rem) printf("%s - Wonderful.\n", num);
        t--;
    }
    return 0;
}

