#include<bits/stdc++.h>

using namespace std;

int dp[35], ex[35];

int main() {
    ex[0] = 1; for(int i=1; i<=30; i++) ex[i] = ex[i-1]*2;
    dp[1] = 2; dp[2] = 4; dp[3] = 7;
    for(int i=4; i<=30; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    int n;
    while(scanf("%d", &n)) {
        if(!n) return 0;
        printf("%d\n", ex[n] - dp[n]);
    }
    return 0;
}
