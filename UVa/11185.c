#include <stdio.h>

int main()
{
    int n, i, j;
    char ter[25], temp;
    while((scanf("%d", &n)))
    {
        if(n<0) break;
        if(!n)
        {
            printf("0\n");
            continue;
        }
        i=0;
        while(n)
        {
            ter[i]=(n%3)+'0';
            n=n/3;
            i++;
        }
        ter[i]='\0';
        i--;
        j=0;
        while(j<i)
        {
            temp=ter[j];
            ter[j]=ter[i];
            ter[i]=temp;
            j++;
            i--;
        }

        printf("%s\n", ter);
    }
    return 0;
}
