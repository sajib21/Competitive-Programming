#include <stdio.h>

int main()
{
    int count=1, n=1;

    while(count<=1500)
    {
        n=n+1;
        if(!(n%2) || !(n%3) || !(n%5)) count++;
    }
}
