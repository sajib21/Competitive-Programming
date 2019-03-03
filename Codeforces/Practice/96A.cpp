#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char f=-1, str[200];
    int cnt=0;
    scanf("%s", str);
    for(int i=0; str[i]!='\0'; i++)
    {
        if(f!=str[i])
        {
            f=str[i];
            cnt=1;
        }
        else
        {
            cnt++;
        }
        if(cnt==7)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
