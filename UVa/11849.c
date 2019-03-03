#include <stdio.h>

int main()
{
    int n,m, i,j;

    while((scanf("%d %d", &n, &m))==2)
    {
        if(!n && !m) break;
        int cd1[n], cd2[m];
        int count=0;
        for(i=0; i<n; i++) scanf("%d", &cd1[i]);
        for(i=0; i<m; i++) scanf("%d", &cd2[i]);

        j=0;
        for(i=0; i<n; i++)
        {
            if(cd1[i]>cd2[m-1]) break;
            for(j; j<m; )
            {
                if(cd1[i]==cd2[j])
                {
                    count++;
                    j=j++;
                    break;
                }
                else if(cd1[i]<cd2[j]) break;
                else j++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
