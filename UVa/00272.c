#include <stdio.h>
#include <string.h>

int main()
{
    char line[100000];
    char line2[100000];
    int i;
    int count=0;
    while((gets(line))!=EOF)
    {
        int n=0;
        for(i=0; i<strlen(line); i++)
        {
            if(line[i]=='"')
            {
                count++;
                if(count%2)
                {
                    line2[n]='`';
                    n++;
                    line2[n]='`';
                    n++;
                }
                else
                {
                    line2[n]='\'';
                    n++;
                    line2[n]='\'';
                    n++;
                }
            }
            else
            {
                line2[n]=line[i];
                n++;
            }
        }
        line2[n]='\0';
        puts(line2);
    }
    return 0;
}
