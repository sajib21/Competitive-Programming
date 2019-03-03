#include <stdio.h>

int main()
{
    int t, i,j, ok;
    scanf("%d", &t);
    int n[t][10];
    for(i=0; i<t; i++) for(j=0; j<10; j++) scanf("%d", &n[i][j]);

    printf("Lumberjacks:\n");
    for(i=0; i<t; i++)
    {
        ok=1;
        if(n[i][1]>n[i][0])
        {
            for(j=1; j<10; j++)
            {
                if(n[i][j]<n[i][j-1])
                {
                    ok=0;
                    printf("Unordered\n");
                    break;
                }
            }
            if(ok) printf("Ordered\n");
        }
        else
        {
            for(j=1; j<10; j++)
            {
                if(n[i][j]>n[i][j-1])
                {
                    ok=0;
                    printf("Unordered\n");
                    break;
                }
            }
            if(ok) printf("Ordered\n");
        }
    }
    return 0;
}

