#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,s, t;
    scanf("%d %d %d", &a, &b, &s);

    t= abs(a) + abs(b);

    if( s>=t && ( (t%2 && s%2) || (!(t%2) && !(s%2) )) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}
