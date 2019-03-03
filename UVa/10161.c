#include <stdio.h>
#include <math.h>

int main()
{
    int n, corner, root;
    while((scanf("%d", &n))==1)
    {
        if(n==0) break;

        root=ceil(sqrt(n));
        corner=root*root-root+1;

        if(n==corner) printf("%d %d\n", root, root);
        else
        {
            if(root%2)
            {
                if(n>corner) printf ("%d %d\n", root+corner-n, root);
                else printf("%d %d\n", root, root+n-corner);
            }

            else
            {
                if(n>corner) printf("%d %d\n", root, root+corner-n);
                else printf("%d %d\n", root+n-corner, root);
            }
        }
    }
    return 0;
}
