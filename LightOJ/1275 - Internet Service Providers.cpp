#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ll n,c, x, xx;
        scanf("%lld %lld", &n,&c);

        if(!n) x = 0;
        else x = c / (2*n);
        xx = x+1;

        if(!n) printf("Case %d: 0\n", t);
        else if( x*(c-x*n) >= xx*(c-xx*n) ) printf("Case %d: %lld\n", t, x);
        else printf("Case %d: %lld\n",t, xx);
    }

    return 0;

}
