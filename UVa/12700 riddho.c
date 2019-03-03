#include <stdio.h>

int main()
{
    int n=0,cases=1;
    scanf("%d",&n);
    while(n--){
        int matches=0,i=0;
        scanf("%d",&matches);
            char str[11];
            scanf("%s",str);
            int A=0,B=0,T=0,W=0;
            for(i=0;i<matches;i++){
                if(str[i]=='A')
                    A++;
                else if(str[i]=='B')
                    B++;
                else if(str[i]=='T')
                    T++;
                else if(str[i]=='W')
                    W++;
            }
            if((B+A==matches)&& B!=0)
                printf("Case %d: BANGLAWASH\n",cases);
            else if((W+A==matches) && W!=0)
                printf("Case %d: WHITEWASH\n",cases);
            else if(A==matches)
                printf("Case %d: ABANDONED\n",cases);
            else if(B>W)
                printf("Case %d: BANGLADESH %d - %d\n",cases,B,W);
            else if(B<W)
                 printf("Case %d: WWW %d - %d\n",cases,W,B);
            else if(B==W)
                printf("Case %d: DRAW %d %d\n",cases,B,T);
            cases++;
    }
    return 0;
}
