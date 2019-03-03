#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld", &n);
        printf("Case %d: %lld\n", t, n - (ll) sqrt(1.0*n) - (ll) sqrt(n/2.0));
    }
    return 0;

}
