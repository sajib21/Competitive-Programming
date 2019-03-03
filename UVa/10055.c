#include <stdio.h>

int main()
{
    long int i, j;

    while((scanf("%ld %ld", &i, &j))!=EOF)
    {
        if(i>j) printf("%ld\n", i-j);
        else printf("%ld\n", j-i);
    }
    return 0;
}
