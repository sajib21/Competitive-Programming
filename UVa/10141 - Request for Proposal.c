#include <stdio.h>
#include <string.h>

int main()
{
    int t=1, n,p, i,j, r, rcmp;
    double price, pcmp;
    char name[90], ans[90];

    while(1)
    {

        scanf("%d %d", &n, &p);
        getchar();
        if(!n && !p) break;


        if(t!=1) printf("\n");
        pcmp=0;
        rcmp=0;
        for(i=0; i<n; i++)
        {
            gets(name);
            puts(name);
        }


        for(i=0; i<p; i++)
        {

            gets(name);

            scanf("%lf %d", &price, &r);
            getchar();

            if(r>rcmp)
            {
                pcmp=price;
                rcmp=r;
                strcpy(ans, name);
                printf("rcmp %d\n", rcmp);
            }
            else if(r==rcmp)
            {
                if(price<pcmp)
                {
                    pcmp=price;
                    rcmp=r;
                    strcpy(ans, name);

                }
            }



            for(j=0; j<r; j++) gets(name);

        }

        printf("RFP #%d\n%s\n", t++, ans);
    }
}
