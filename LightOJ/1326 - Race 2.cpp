#include<bits/stdc++.h>
#define MOD 10056

using namespace std;

int n, comb[1010][1010];
int dp[1010];

void genComb() {

    comb[1][0] = comb[1][1] = 1;
    for(int i=2; i<=1000; i++) {
        comb[i][0] = 1;
        for(int j=1; j<=i; j++) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }
}

void genAns() {

    dp[0] = dp[1] = 1;
    for(int i=2; i<=1000; i++) {
        for(int j=1; j<=i; j++) {
            dp[i] = (dp[i] + comb[i][j] * dp[i-j]) % MOD;
        }
    }
}

int main() {

    genComb();
    genAns();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        //memset(dp, , sizeof(dp));

        scanf("%d", &n);
        printf("Case %d: %d\n", t, dp[n]);
    }

    return 0;
}
