#include <stdio.h>

int main()
{
    int n[3][3];
    char ara[3];
    int i,j,r,c,r1,c1,r2,c2, t;
    while((scanf("%d %d %d %d %d %d %d %d %d", &n[0][0],&n[0][1],&n[0][2],&n[1][0],&n[1][1],&n[1][2],&n[2][0],&n[2][1],&n[2][2]))==9)
    {
        int sum=0;
        int max=0;
        for(i=0; i<3; i++) for(j=0; j<3; j++)
        {
            sum=sum+n[i][j];
            if(n[i][j]>=max)
            {
                max=n[i][j];
                r=i;
                c=j;
            }
            ara[r]=c;
        }
        t=sum;
        sum=sum-max;

        max=0;
        for(i=0; i<3; i++) for(j=0; j<3; j++)
        {
            if(i!=r && j!=c)
            {
                if(n[i][j]>=max)
                {
                    max=n[i][j];
                    r1=i;
                    c1=j;
                }
                ara[r1]=c1;
            }
        }
        sum=sum-max;

        max=0;
        for(i=0; i<3; i++) for(j=0; j<3; j++)
        {
            if(i!=r && i!=r1 && j!=c && j!=c1)
            {
                if(n[i][j]>=max)
                {
                    max=n[i][j];
                    r2=i;
                    c2=j;
                }
                ara[r2]=c2;
            }
        }
        sum=sum-max;

        for(i=0; i<3; i++)
        {
            if(ara[i]==0) ara[i]='B';
            if(ara[i]==1) ara[i]='G';
            if(ara[i]==2) ara[i]='C';
        }

        if(sum==t*2/3) printf("BCG %d\n", sum);
        else printf("%s %d\n", ara, sum);
    }
    return 0;
}
