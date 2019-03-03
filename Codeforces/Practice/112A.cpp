#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s1[110], s2[110];

    scanf("%s", s1);
    scanf("%s", s2);

    for(int i=0; s1[i]!='\0'; i++)
        s1[i]=toupper(s1[i]);
    for(int i=0; s2[i]!='\0'; i++)
        s2[i]=toupper(s2[i]);

    printf("%d\n", strcmp(s1, s2));
    return 0;
}
