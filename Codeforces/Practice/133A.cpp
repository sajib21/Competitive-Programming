#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    char s[110];
    scanf("%s", &s);

    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
