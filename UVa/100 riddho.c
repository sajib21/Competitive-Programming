#include <stdio.h>

int main()
{
    int i, j, n, len=1, max=0;
    while((scanf("%d %d", &i, &j))==2){

    for(n=i; n<=j;)
    {
        do
        {
            if(n%2) n=3*n+1;
            else n=n/2;
            len++;
        } while(n>1);

        if(len>max) max=len;
    }
    printf("%d %d %d", i, j, max);
    }

    return 0;
}
