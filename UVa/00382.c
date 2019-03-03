#include <stdio.h>

int check(int n)
{
    int i, sum=0;
    for(i=1; i<=n/2; i++) if(!(n%i)) sum=sum+i;
    if(n==sum) printf("%d  PERFECT\n", n);      //we could just use printf("%5d...") here in all these printf's to make them all in line!!
    else if(n>sum) printf("%d  DEFICIENT\n", n);
    else printf("%d  ABUNDANT\n", n);
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
        if(num[i]<10000) printf(" ");   //this is a very non-efficient process to keep all numbers in line!!
        if(num[i]<1000) printf(" ");    //however, 18thfeb, 2015 i found a much more better and the real way to do it in the teach yourself C book
        if(num[i]<100) printf(" ");     // check the check funcion!!
        if(num[i]<10) printf(" ");
        check(num[i]);
    }
    return 0;
}
