#include <stdio.h>

#define MAX 5000002

long long unsigned int  sum[MAX];

void sievePHI(){
    int i,j;
    for( i=2;i<MAX;i++){
        if( sum[i]==0){
            sum[i] = i-1;
            for( j = i*2; j<MAX; j+=i){
                if( sum[j] == 0 ) sum[j] = j;
                sum[j] /= i ;
                sum[j] *= (i-1) ;
            }
        }
        sum[i]=sum[i]*sum[i] + sum[i-1];
    }
}

int main()
{
    int t,T, a,b;
    sievePHI();

    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", t, (long long unsigned int) sum[b]-sum[a-1]);
    }
    return 0;
}
