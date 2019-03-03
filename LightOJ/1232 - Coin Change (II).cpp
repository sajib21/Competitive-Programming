

#include <bits/stdc++.h> ///C te submit dile sobchey kom memory lage!!
#define ll long long int
#define MOD 100000007
using namespace std;

//#include<stdio.h>
//#define ll long long int
//#define MOD 100000007

int main() {

    long long int t,T, n,k, coin, i,j, dp[10002];
    //int coins[102];
    //ll dp[10002];

    scanf("%lld", &T);
    for(t=1; t<=T; t++) {

        memset(dp, 0, sizeof(dp)); ///!
        dp[0] = 1;


        scanf("%lld %lld", &n,&k);
        //int i;
        for(i=0; i<n; i++) {
            scanf("%lld", &coin);

            //int j;
            for(j=coin; j<=k; j++) {
                if(coin <= j) {
                    dp[j] = (dp[j] + dp[ j-coin ]) % 100000007;
//                    dp[j] += ( dp[ j-coin ]);
//                    if(dp[j] >= MOD)
//                        dp[j] %= MOD;
                }
            }

        }


        printf("Case %lld: %lld\n", t, dp[k]);
    }

    return 0;
}
