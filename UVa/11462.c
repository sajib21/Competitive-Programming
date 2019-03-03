#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, i,j;

    while((scanf("%d", &n)))
    {
        if(n==0) break;
        char age[n][3], t[3];
        for(i=0; i<n; i++) scanf("%s", &age[i]);

        for(i=0; i<n-1; i++) for(j=i+1; j<n; j++) if(atoi(age[i])>atoi(age[j]))
        {
            strcpy(t,age[i]);
            strcpy(age[i],age[j]);
            strcpy(age[j],t);
        }
        printf("%s", age[0]);
        for(i=1; i<n; i++) printf(" %s", age[i]);
        printf("\n");
         printf("%d\n", sizeof(int));
    }

    return 0;
}
