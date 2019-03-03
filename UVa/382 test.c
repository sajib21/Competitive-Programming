#include <stdio.h>

int check(int n)
{
    int i, sum=0;
    for(i=1; i<=n/2; i++) if(!(n%i)) sum=sum+i;
    if(n==sum) return 0;
    else if(n>sum) return -1;
    else return 1;
}

int main()
{
    int num[101], i;
    for(i=0; ; i++)
    {
        scanf("%d", &num[i]);
        if(num[i]==0) break;
    }
    printf("PERFECTION OUTPUT\n");
    for(i=0; ; i++)
    {
        if(num[i]==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        if(num[i]>10000)
    }
}
