#include <stdio.h>

int main()
{
    int n;

        while(((scanf("%d", &n))==1))
        {
            if(n) printf("%d\n", n/2);
            else break;
    }
    return 0;
}
