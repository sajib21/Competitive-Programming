#include<bits/stdc++.h>

using namespace std;

int n,d, ara[30003];
int dp[30003][600];

int getMax(int cur, int lastJump) {

    if(!lastJump) return 0;
    if(cur > 30000) return 0;

    if(dp[cur][lastJump-d+1] != -1) return dp[cur][lastJump-d+1];

    return dp[cur][lastJump-d+1] = ara[cur] + max( getMax(cur+lastJump-1, lastJump-1),
            max(getMax(cur+lastJump, lastJump), getMax(cur+lastJump+1, lastJump+1)) );
}

int main() {

    int t;
    cin >> n >> d;
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        ara[t]++;
    }

    cout << getMax(d, d) << endl;

    return 0;

}
