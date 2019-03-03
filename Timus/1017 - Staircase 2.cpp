#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
ll dp[305][505];

ll getMax( ll brick, ll now) {

    if(!brick) return 1;
    if(brick < 0) return 0;

    if(dp[brick][now] == -1) {
        ll temp = 0;
        for(ll i = now; i <= brick; i++) {
            printf("brick: %lld, i %lld\n", brick, i);
            temp += getMax(brick-i, i+1);
            printf("temp %lld\n", temp );
        }
        dp[brick][now] = temp;
    }

    return dp[brick][now];

}

int main() {
    cin >> n;

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", getMax(n, 1)-1);
}
