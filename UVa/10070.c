#include <stdio.h>

int d4(char str[n])
{
    int i;
    i= (str[n-2]-'0')*10 + (str[n-1]-'0');
    if(!(i%4)) return 1;
    return 0;
}

int check_leap(int n)
{
    if(!(n%400)) return 1;
    if(!(n%4) && (n%100)) return 1;

    return 0;
}

int main()
{
    int y;

    while((scanf("%d", &y))!=EOF)
    {
        if(check_leap(y)==1) printf("This is leap year.\n");
        if(!(y%15)) printf("This is huluculu festival year.\n");
        if(check_leap(y)==1 && !(y%55)) printf("This is buluculu festival year.\n");
        if(!check_leap(y) && (y%15)) printf("This is an ordinary year.\n");
        printf("\n");
    }
    return 0;
}
