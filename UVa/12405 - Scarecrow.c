#include <stdio.h>

int main()
{
    int T,t, n, i,j, sc=0;
    char f[105];

    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        sc=0;
        scanf("%d", &n);
        scanf("%s", f);

        for(i=0; i<n; )
        {
            if(f[i]=='.')
            {
                sc++;
                f[i]=f[i+1]=f[i+2]='#';
                i+=3;
            }
            else i++;
        }

        printf("Case %d: %d\n", t, sc);
    }

    return 0;
}
