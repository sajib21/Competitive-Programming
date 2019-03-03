#include <stdio.h>

int main()
{
    int r,c, k,x;
    while(scanf("%d %d", &r, &c) && ( r || c))
    {
        if(r==1 || c==1) printf("%d knights may be placed on a %d row %d column board.\n", r+c-1 , r,c);
        else if(r==2 || c==2)
        {
            x=(r+c-2)%4;
            if(x<=2) printf("%d knights may be placed on a %d row %d column board.\n", (r+c-2)/4*4 + 2*x , r, c);
            else printf("%d knights may be placed on a %d row %d column board.\n", (r+c-2)/4*4 + 4 , r, c);
        }
        else printf("%d knights may be placed on a %d row %d column board.\n", (r*c+1)/2 , r, c);
    }
    return 0;
}
