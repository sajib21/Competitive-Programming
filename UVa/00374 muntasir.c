#include <stdio.h>
#include <string.h>

long long int bigmod ( long long a, int b, int c);
int main(){
    long long int b;
    int p,m;

    while(scanf("%lld %d %d",&b,&p,&m)==3)
    printf("%d\n",bigmod(b,p,m));
   return 0;
}
long long int  bigmod ( long long a, int b, int c){
    if ( b == 0 )return 1;
    if ( b % 2 ) return ((a%c)*(bigmod(a,b-1,c)))%c;

    else {
        long long d = bigmod(a,b/2,c);
        return ((d%c)*(d%c))%c;
    }
}
