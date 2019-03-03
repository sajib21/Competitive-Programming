#include <stdio.h>

int main()
{
    int h1, m1, h2, m2, total;
    while((scanf("%d %d %d %d", &h1, &m1, &h2, &m2)==4))
    {
        if(h1==0 && m1==0 && h2==0 && m2==0) break;
        total=(h2*60+m2)-(h1*60+m1);
        if(total<0) printf("%d\n", 1440+total);
        else printf("%d\n", total);
    }
    return 0;
}
