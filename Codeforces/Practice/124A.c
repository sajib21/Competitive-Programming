#include <stdio.h>

int main()
{
    int n,a,b;
    scanf("%d %d %d", &n,&a,&b);

    if(a+b == n) printf("%d\n", b);
    else printf("%d\n", b+1);

    return 0;
}
