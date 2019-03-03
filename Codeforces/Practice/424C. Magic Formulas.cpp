#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,ara[1000006];
ll cumXor[1000006];

int main() {

    scanf("%lld", &n);
    for(ll i=1; i<=n; i++) scanf("%lld", &ara[i]);

    for(ll i=1; i<=n; i++) cumXor[i] = cumXor[i-1] ^ i;

    ll res = 0;
    for(ll i=1; i<=n; i++) {

        if((n/i) % 2) res ^= cumXor[i-1];

        res ^= cumXor[n%i] ^ ara[i];
    }

    printf("%lld\n", res);

    return 0;
}
