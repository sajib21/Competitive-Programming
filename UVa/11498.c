#include <stdio.h>

int main()
{
    int n, ox,oy, x,y;
    while(scanf("%d", &n))
    {
        if(!n) return 0;
        scanf("%d %d", &ox, &oy);

        while(n)
        {
            scanf("%d %d", &x, &y);
            if(x==ox || y==oy) printf("divisa\n");
            else if(x<ox && y>oy) printf("NO\n");
            else if(x>ox && y>oy) printf("NE\n");
            else if(x>ox && y<oy) printf("SE\n");
            else if(x<ox && y<oy) printf("SO\n");
            n--;
        }
    }
    return 0;
}
