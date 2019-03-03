#include <stdio.h>

int main()
{
    int t,T, i, e;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %d", &i, &e);
        printf("Case %d: %d\n", t, 19 + 4*(i + abs(i-e)));
    }
    return 0;
}
