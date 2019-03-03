#include <stdio.h>
#include <string.h>
int main()
{
    long long int n,s,i,j,p,l,k,a[100];
    char m[1000000];
    scanf("%lld",&n);
    while(n--){
        scanf("%s",m);
        scanf("%lld",&s);
        for(i=0;i<s;i++){
            scanf("%lld",&a[i]);
        }
        k =0;
        l=strlen(m);
        for(i=0;i<s;i++){
            j=0;
            for(p =0;p<l; p++) {
                j =(j*10+m[p]-'0')% a[i];
            }
            if(j)
            {
                printf("%s - Simple.\n",m);
                break;
            }
        }
        if(!j) printf("%s - Wonderful.\n",m);
    }
    return 0;
}
