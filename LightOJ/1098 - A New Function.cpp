#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ll ans = 0, pre;
        scanf("%lld", &n);

        ans = 0;
        pre = n;

        ll sq = sqrt(n);
        for(ll i=2; i<=sq; i++) {
            ll div = n / i;

            ans += (i-2)*( pre*(pre+1)/2 - div*(div+1)/2 );
            ans += (div-1)*i;

            pre = div;
        }

        if(pre != sq) {
            ans += (sq-1)*( pre*(pre+1)/2 - sq*(sq+1)/2 );
        }

        printf("Case %d: %lld\n", t, ans);
    }

    return 0;

}
