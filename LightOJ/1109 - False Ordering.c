#include <stdio.h>

int sv[33];

svgen()
{
    int i, j;
    for(i=2; i<8; i++) if(!sv[i]) for(j=i*i; j<34; j+=i) sv[j]=1;
}

int main()
{
    int n, i,j, c, div, term, ara[1005];
    svgen();
    for(n=2; n<1001; n++)
    {
        div=1;
        term=n;
        for(i=2; i<33 && term>1; i++) if(!sv[i] && n%i==0)
            {
                c=0;
                while(term%i==0)
                {
                    c++;
                    term/i;
                }
                div*=(c+1);
            }
    }

}
