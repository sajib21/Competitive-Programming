#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll n;
    while(scanf("%lld", &n) && n) {

        ll ans = 0;
        while(n) {
            ans += n%10;
            n/=10;
            if(ans > 9) {
                ans = ans%10 + ans/10;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
