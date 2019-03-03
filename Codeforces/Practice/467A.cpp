#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a,b, cnt=0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &a,&b);
        if(b-1>2) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
