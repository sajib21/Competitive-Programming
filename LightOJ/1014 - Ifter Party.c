#include <stdio.h>
#include <math.h>

int div[1000006], div2[1000006];

int main()
{
    int t,T, p,l, i,j,k, mi, lim;
    scanf("%d", &T);
    for(t=1;t<=T; t++)
    {
        scanf("%d %d", &p, &l);
        mi=p-l;

        printf("Case %d:", t);

        if(mi<=l)
        {
            printf(" impossible\n");
            continue;
        }

        lim=sqrt(mi);

        j=0; k=0;
        for(i=1; i<=lim; i++)
        {
            if(!(mi%i) && mi/i>l )
            {
                div[j]=mi/i;
                if(i>l && i!=div[j]) {div2[k]=i; k++;}
                j++;
            }
        }

        for(i=0; i<k; i++) printf(" %d", div2[i]);
        while(j--) printf(" %d", div[j]);
        printf("\n");

    }
    return 0;
}
