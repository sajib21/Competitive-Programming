#include <bits/stdc++.h>
#define MOD 100000007

using namespace std;

long long int coins[55], counts[55];

long long int n,k;
long long int dp[55][1000];

long long int getMax(long long int i, long long int k) {

    if(i == n) {
        if(!k) return 1;
        else return 0;
    }

    if(!k) return 1;
    else if (k < 0) return 0;


    if(dp[i][k] != -1)
        return dp[i][k];

    else {
        long long int temp = 0;
        for(int c=0; c<=counts[i]; c++) {
            if(k-coins[i]*c >= 0) {
                temp = ( temp + getMax(i+1, k - coins[i]*c) ) % MOD;
            }
            else break;
        }

        return dp[i][k] = temp;
    }
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        //cin >> n >> k;
        scanf("%lld %lld", &n, &k);

        for(int i=0; i<n; i++) {
            //cin >> coins[i];
            scanf("%lld", &coins[i]);
        }
        for(int i=0; i<n; i++) {
            //cin >> counts[i];
            scanf("%lld", &counts[i]);
        }

        printf("Case %d: %lld\n", t, getMax(0, k));
    }

    return 0;

}
