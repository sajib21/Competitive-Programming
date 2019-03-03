#include <stdio.h>

int main()
{
    int r,c, b;

    while(scanf("%d %d %d", &r, &c, &b) && (r || c || b)) printf("%d\n", ( (r-7)*(c-7)+b)/2);
    return 0;
}
