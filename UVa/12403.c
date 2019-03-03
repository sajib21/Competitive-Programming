#include <stdio.h>

int main()
{
    long long int sum=0;
    int am;
    char t;
    char op[7];
    scanf("%d", &t);

    while(t)
    {
        scanf("%s", op);
        if(op[0]=='d')
        {
            scanf("%d", &am);
            sum=sum+am;
        }
        else printf("%d\n", sum);
        t--;
    }
    return 0;
}
