#include<bits/stdc++.h>
#define MX 2000006
#define ll long long int
using namespace std;

int n,q,l,r, ara[MX], freq[MX];

int main() {

    scanf("%d %d", &n,&q);
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
    sort(ara+1, ara+n+1);
    freq[0] = 0;
    for(int i=0; i<q; i++) {
        scanf("%d %d", &l,&r);
        freq[l]++; freq[r+1]--;
    }
    for(int i=1; i<=n; i++) freq[i] += freq[i-1];
    sort(freq+1, freq+n+1);

    ll res = 0;
    for(int i=1; i<=n; i++) res += (ll) freq[i]*ara[i];

    printf("%lld\n", res);

    return 0;
}
