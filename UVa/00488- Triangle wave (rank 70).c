#include <stdio.h>

int main()
{
    int t, h, f;
    scanf("%d", &t);

    while(t)
    {
        scanf("%d %d", &h, &f);

            if(h==9)
            {
                while(f>1)
                {
                    printf("1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n999999999\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1\n\n");
                    f--;
                }
                printf("1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n999999999\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1\n");
            }
            else if(h==8)
            {
                while(f>1)
                {
                    printf("1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1\n\n");
                    f--;
                }
                printf("1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1\n");
            }
            else if(h==7)
            {
                while(f>1)
                {
                    printf("1\n22\n333\n4444\n55555\n666666\n7777777\n666666\n55555\n4444\n333\n22\n1\n\n");
                    f--;
                }
                printf("1\n22\n333\n4444\n55555\n666666\n7777777\n666666\n55555\n4444\n333\n22\n1\n");
            }
            else if(h==6)
            {
                while(f>1)
                {
                    printf("1\n22\n333\n4444\n55555\n666666\n55555\n4444\n333\n22\n1\n\n");
                    f--;
                }
                printf("1\n22\n333\n4444\n55555\n666666\n55555\n4444\n333\n22\n1\n");
            }
            else if(h==5)
            {
                while(f>1)
                {
                    printf("1\n22\n333\n4444\n55555\n4444\n333\n22\n1\n\n");
                    f--;
                }
                printf("1\n22\n333\n4444\n55555\n4444\n333\n22\n1\n");
            }
            else if(h==4)
            {
                while(f>1)
                {
                    printf("1\n22\n333\n4444\n333\n22\n1\n\n");
                    f--;
                }
                printf("1\n22\n333\n4444\n333\n22\n1\n");
            }
            else if(h==3)
            {
                while(f>1)
                {
                    printf("1\n22\n333\n22\n1\n\n");
                    f--;
                }
                printf("1\n22\n333\n22\n1\n");
            }
            else if(h==2)
            {
                while(f>1)
                {
                    printf("1\n22\n1\n\n");
                    f--;
                }
                printf("1\n22\n1\n");
            }
            else if(h==1)
            {
                while(f>1)
                {
                    printf("1\n\n");
                    f--;
                }
                printf("1\n");
            }

        t--;
        if(t) printf("\n");
    }
    return 0;
}
