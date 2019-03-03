#include <stdio.h>

int main()
{
    int a,b, dif;
    while((scanf("%d %d", &a, &b))==2)
    {
        if(a==-1 && b==-1) break;
        printf("%d %d\n", a,b);
        dif=abs(b-a);
        if(dif<=50) printf("%d\n", dif);
        else printf("%d\n", 100-dif);

    }
    return 0;

}
