#include <stdio.h>

int main()
{
    int a1,a2,a3, b1,b2,b3, c1,c2,c3, comb, i,j,k, tot, sub;
    while((scanf("%d %d %d %d %d %d %d %d %d", &a1,&a2,&a3, &b1,&b2,&b3, &c1,&c2,&c3))==9)
    {
        tot=a1+a2+a3+ b1+b2+b3+ c1+c2+c3;

        sub=a1+b2+c3;
        i=1;
        k=2;

        comb=a1+b3+c2;
        if(comb>sub)
        {
            sub=comb;
            i=2;
            k=1;
        }
        else if(comb==sub)
        {
            j=i;
            if(k>1) k=1;
        }

        comb=a2+b1+c3;
         if(comb>sub)
        {
            sub=comb;
            i=3;
            k=5;
        }
        else if(comb==sub)
        {
            j=i;
            if(k>5) k=5;
        }


        comb=a2+b3+c1;
        if(comb>sub)
        {
            sub=comb;
            i=4;
            k=6;
        }
        else if(comb==sub)
        {
            j=i;
            if(k>6) k=6;
        }

        comb=a3+b1+c2;
         if(comb>sub)
        {
            sub=comb;
            i=5;
            k=3;
        }
        else if(comb==sub)
        {
            j=i;
            if(k>3) k=3;
        }

        comb=a3+b2+c1;
         if(comb>sub)
        {
            sub=comb;
            i=6;
            k=4;
        }
        else if(comb==sub)
        {
            j=i;
            if(k>4) k=4;
        }

        if(i==j)
        {
            if(k==1) printf("BCG %d\n", tot-sub );
            else if(k==2) printf("BGC %d\n", tot-sub);
            else if(k==3) printf("CBG %d\n", tot-sub);
            else if(k==4) printf("CGB %d\n", tot-sub);
            else if(k==5) printf("GBC %d\n", tot-sub);
            else if(k==6) printf("GCB %d\n", tot-sub);
        }

        else if(i==1) printf("BGC %d\n", tot-sub);
        else if(i==2) printf("BCG %d\n", tot-sub);
        else if(i==3) printf("GBC %d\n", tot-sub);
        else if(i==4) printf("GCB %d\n", tot-sub);
        else if(i==5) printf("CBG %d\n", tot-sub);
        else if(i==6) printf("CGB %d\n", tot-sub);

    }
    return 0;
}
