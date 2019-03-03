#include <stdio.h>

char M[ 1003 ];
int n, s;

int main()
{
    int N;

    scanf("%d",&N);
    while ( N-- )
    {
        gets( M );
        gets( M );
        scanf("%d",&n);
        bool ok = true;
        for (int i=0; i<n; i++)
        {
            scanf("%d",&s);
            if ( !ok ) continue;
            int mod = 0;
            for (int k=0; M[k]; k++)
            {
                mod *= 10;
                mod += M[k]-'0';
                mod %= s;
            }
            if ( mod ) ok = false;
        }
        if ( ok ) printf("%s - Wonderful.\n",M);
        else printf("%s - Simple.\n",M);
    }

    return 0;
}
