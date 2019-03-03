#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        ll n,k;
        scanf("%lld %lld", &n,&k);

        ll res = 1;
        for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1;

        printf("Case %d: %lld\n", t, res);
    }
    return 0;
}
