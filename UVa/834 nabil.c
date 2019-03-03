#include<stdio.h>

main()
{
    int num, den;

    while(scanf("%d%d", &num ,&den) == 2)
    {
        int n = 0, r[100] = {0};

        printf("[");

        while(1){
            r[n] = num/den;
            num = num%den;
            num = num + den;
            den = num - den;
            num = num - den;

            printf("%d", r[n]);

            if(n == 0)
                printf(";");
            else
                printf(",");

            n++;

            if(den%num == 0)
            {
                printf("\b]\n");
                break;
            }
        }
    }
}
