#include <stdio.h>

int main()
{
    int t,T, n;
    char name[10];
    scanf("%d", &T);
    for(t=1;t<=T; t++)
    {
        scanf("%d %s", &n, name);
        getchar();
        if(name[0]=='A')
        {
            if(!((n-1)%3)) printf("Case %d: Bob\n", t);
            else printf("Case %d: Alice\n", t);
        }
        else
        {
            if(!(n%3)) printf("Case %d: Alice\n", t);
            else printf("Case %d: Bob\n", t);
        }
    }
    return 0;
}
