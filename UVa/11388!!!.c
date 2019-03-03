#include <stdio.h>
#include <math.h>
int main()
{
    int t, g, l, a, b;
    scanf("%d", &t);
    while(t)
    {
        scanf("%d %d", &g, &l);
        for(a=g; a<=sqrt(g*l); a++)
        {
            b=g*l/a;
            if(a%g==0 && b%g==0)
            {
                printf("%d %d\n",(int) a, (int) b);
                break;
            }
            else printf("%d\n", -1);
        }
        t--;
    }
    return 0;
}
