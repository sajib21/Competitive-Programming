#include <stdio.h>
#include <string.h>

int main()
{
    int t, n,i,j,k,l, temp, side=0;
    char ara[27][27];
    scanf("%d", &t);
    getchar();
    putchar('\n');

    while(t)
    {
        side=0;
        gets(ara[0]);
        n=strlen(ara[0]);
        for(i=1; i<n; i++) gets(ara[i]);

        for(i=0; i<n; i++) for(j=0; j<n; j++) if(ara[i][j]=='1')
        {
            temp=0;
            for(l=j; ara[i][l]=='1' && l<n; l++) temp++;
            if(n-i<temp) temp=n-i;
            for(k=i; k<i+temp; k++) for(l=j; l<j+temp; l++) if(ara[k][l]=='0') temp=l-j;
            if(temp>side) side=temp;
        }
        printf("%d\n", side*side);
        t--;
        if(t) printf("\n");
    }
    return 0;
}
