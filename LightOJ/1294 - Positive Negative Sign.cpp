#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ll n,m;
        scanf("%lld %lld", &n,&m);
        printf("Case %d: %lld\n",t, ( n/(2*m) ) * m*m );

    }

    return 0;

}
