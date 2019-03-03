#include <stdio.h>
#include <math.h>

int main()
{
    int n, x,y, i;
    float f, rt;

    while(scanf("%d", &n)==1)
    {
        if(!n) break;

        rt=pow(n, 1/3.0);
        for(i=1; i<60; i++)
        {
            f=pow(n+i*i*i, 1/3.0);
            if(f==(int)f)
            {
                printf("%.0lf %d\n", f, i);
                goto done;
            }
        }
        printf("No solution\n");
        done: continue;
    }
    return 0;
}
