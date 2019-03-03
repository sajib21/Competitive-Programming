#include <stdio.h>
#include <string.h>

char num[104][104];
int sum[104];
int l, len;

void rev(char num[104])
{
    int i=0, t;
    l=strlen(num)-1;
    while(i<l)
    {
        t=num[i];
        num[i]=num[l];
        num[l]=t;
        i++;
        l--;
    }
}
void rnd(char num[104])
{
    int i ;
    l=strlen(num);
    if (l>len) len=l;
    for(i=0; i<l; i++) num[i]-='0';
}

int main()
{
    int n, m, i=0, j,k, cry=0;

    do
    {
        i++;
        gets(num[i]);
        rev(num[i]);
        rnd(num[i]);
    }while(num[i][l-1]!=0);

    len+=2;
    for(j=0; j<len ; j++)
    {
        for(k=1; k<i; k++) sum[j]+=num[k][j];
        sum[j]+=cry;
        cry=sum[j]/10;
        sum[j]%=10;
    }
    for(k=103; k; k--) if (sum[k]) break;
    for(k; k>=0; k--) printf("%d", sum[k]);
    printf("\n");

    return 0;
}
