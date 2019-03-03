#include <bits/stdc++.h>

using namespace std;

int cubes[] = {0,1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,
                3375,4096,4913,5832,6859,8000,9261,10648};

long long int dp[25][10010];

long long int getMax(int i, int n) {

    if(i > 21) {
        if(!n) return 1;
        else return 0;
    }

    if(dp[i][n] == -1) {
        if(cubes[i] <= n)
            dp[i][n] = getMax(i, n-cubes[i]);
        else dp[i][n] = 0;

        dp[i][n] += getMax(i+1, n);
    }

    return dp[i][n];
}

int main() {
    int n;

    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &n) != EOF) {

        printf("%lld\n", getMax(1, n));

    }

    return 0;
}
