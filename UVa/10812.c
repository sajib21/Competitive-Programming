#include <stdio.h>

int main()
{
    short int n, s, d;
    scanf("%d", &n);

    while(n)
    {
        scanf("%hd %hd", &s, &d);
        if(s>=d && s%2==d%2) printf("%hd %hd\n",(s+d)/2, (s-d)/2);
        else printf("impossible\n");
        n--;
    }
    return 0;
}
