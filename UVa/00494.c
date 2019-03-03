#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int i;

    while(gets(str))
    {
        int count=0;
        for(i=0; i<strlen(str); i++)
        {
            if(((str[i]>='a' && str[i]<='z') || (str[i]>='A' &&str[i]<='Z')) && !((str[i+1]>='a' && str[i+1]<='z') || (str[i+1]>='A' && str[i+1]<='Z')))
                count++;
        }

        printf("%d\n", count);
    }
    return 0;
}
