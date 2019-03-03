#include<bits/stdc++.h>

using namespace std;

char str[103];
int dp[103][103];

int getMin(int st, int ed) {
    if(st >= ed) return 0;
    if(dp[st][ed] != -1) return dp[st][ed];

    if(str[st] == str[ed]) return dp[st][ed] = getMin(st+1, ed-1);
    else return dp[st][ed] = 1 + min(getMin(st+1, ed), getMin(st, ed-1));
}

int main() {
    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        scanf("%s", str);

        printf("Case %d: %d\n", t, getMin(0, strlen(str)-1));
    }
    return 0;
}
