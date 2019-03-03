#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i,j,n, len=0, l=0;
    char word[105], temp[105], c;

    i=0;
    while(scanf("%c", &c))
    {

        if( !( (c>='a' && c<='z') || (c>='A' && c<='Z') || c=='-' ) )
        {

            temp[i]='\0';


            if(!strcmp(temp, "E-N-D"))
            {

                break;

            }

            if(i>len)
            {
                strcpy(word,temp);
                len=i;
            }

            strcpy(temp, "\n");
            i=0;
        }

        else
        {
            temp[i]=c;
            i++;
        }

    }

    i=0;
    while(i<len)
    {
        printf("%c", tolower(word[i++]));
    }

    printf("\n");


    return 0;
}
