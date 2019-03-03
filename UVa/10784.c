#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    long double n;

    while(1)
    {
        scanf("%d", &N);
        if(N==0) break;

        n=(-3.0+sqrt(9.0+8.0*N))/2.0;

        if(n==(int) n) printf("%d\n", (int) n+3);
        else printf("%d\n",(int) n+4);
    }
    return 0;
}

