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

int getComb(int n) {

    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans = (ans + comb[n][i] * getComb(n-i)) % MOD;
    }

    return dp[n] = ans;
}

int main() {

    genComb();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        scanf("%d", &n);
        printf("Case %d: %d\n", t, getComb(n));
    }

    return 0;
}
