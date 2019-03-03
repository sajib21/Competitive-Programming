#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c;
    while(scanf("%c", &c) && c!='\n')
    {
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y') continue;

        printf(".%c", c);
    }

    printf("\n");

    return 0;
}
