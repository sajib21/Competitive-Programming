#include <stdio.h>
#include <math.h>
main()
{
    long int N,i,sum,j;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%ld",&N)==1 && N!=0)
    {
        sum=1;
        for(i=2;i<=sqrt(N);i++)
        {
            j=N/i;
            if(N%i==0)
                sum=sum+i+j;
        }
        if(sum==N)
            printf("%5ld PERFECT\n",N);
        else if(sum>N)
            printf("%5ld ABUNDANT\n",N);
        else
            printf("%5ld DEFICIENT\n",N);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
