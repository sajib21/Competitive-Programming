#include <stdio.h>

int main()
{
    int i,T;
   scanf("%d", &T);
for(i=1; i<=T; i++){
    int N,K,P;
    scanf ("%d %d %d",&N,&K,&P);
    int M=K+P;
    if (M>N) {
        while(M>N) M=M-N;
    printf ("Case %d: %d\n",i,M);
    }
    else printf ("Case %d: %d\n",i,M);
}
    return 0;
}
