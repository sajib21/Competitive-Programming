#include <stdio.h>

int main()
{
    int t, r,c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &r, &c);
        printf("%d\n", (r/3)*(c/3));
    }

    return 0;
}
