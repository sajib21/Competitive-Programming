#include<bits/stdc++.h>
#define LIM 200005
#define MOD 1000000007
#define ll long long int

using namespace std;

ll r,g;
ll dp[3][LIM]; ///[640]

int main() {
    cin >> r >> g;

    dp[0][0] = 1;

    bool f = false;
    int in;
    for(in=1; ; in++) {
        f = false;
        memset(dp[in%2], 0, sizeof dp[in%2]);
        ll total = in*(in+1)/2;

        for(ll red=min(r, total); red>=0; red--) {
            ll green = total - red;
            if(green <= g) {
                int pr = (in-1)%2;
                dp[in%2][red] += dp[pr][red];
                dp[in%2][red] %= MOD;
                f = true;
            }
            else break;
        }
        for(ll red=min(r, total); red>=in; red--) {
            ll green = total - red;
            if(green <= g) {
                int pr = (in-1)%2;
                dp[in%2][red] += dp[pr][red-in];
                dp[in%2][red] %= MOD;
                f = true;
            }
            else break;
        }
        if(!f) break;
    }

    in--;
    ll ans = 0;
    for(int red=0; red<=r; red++) {
//        cout << dp[in%2][red] << ' ';
        ans += dp[in%2][red];
        ans %= MOD;
    }
//    cout << endl;

    printf("%lld\n", ans);
}
