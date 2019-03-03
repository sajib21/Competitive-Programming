#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a,b,c, s, cnt=0;
    scanf("%d", &n);

    while(n--)
    {
        scanf("%d %d %d", &a,&b,&c);
        s=a+b+c;
        if(s>1) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
