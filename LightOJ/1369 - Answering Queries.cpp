#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ll n,q;
        ll num, sum = 0, ara[100010];
        scanf("%lld %lld", &n,&q);
        for(ll i=0, mul=n-1; i<n; i++, mul-=2) {
            scanf("%lld", &num);
            sum += mul*num;
            ara[i] = num;
        }

        printf("Case %d:\n", t);

        for(int i=0; i<q; i++) {
            ll c, u,val;
            scanf("%lld", &c);
            if(!c) {
                scanf("%lld %lld", &u,&val);
                sum -= (n - (2*u+1))*( ara[u] - val );
                ara[u] = val;
            }
            else printf("%lld\n", sum);
        }
    }

    return 0;


}
