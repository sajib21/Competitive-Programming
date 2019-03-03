#include <stdio.h>

int main()
{
    int n, m,i, j,k,temp, count;
    char bin[32];
    while((scanf("%d", &n)))
    {
        m=n;
        count=0;
        if(!n) break;
        i=0;
        while(n)
        {
            if(!(n%2)) bin[i]='0';
            else
            {
                bin[i]='1';
                count++;

            }
            i++;
            n/=2;
        }
        j=0;
        k=i-1;
        while(j<i/2 )
        {
            temp=bin[j];
            bin[j]=bin[k];
            bin[k]=temp;
            j++;
            k--;
        }

        bin[i]='\0';
        printf("The parity of %s is %d (mod 2).\n",bin, count);
    }
    return 0;
}
