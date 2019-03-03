#include <bits/stdc++.h>
#define MAX INT_MAX

using namespace std;

int h, rcost[22],gcost[22],bcost[22];
int dp[20][10];


int getMin(int i, int now) {
    if(i == h) return 0;

    if(dp[i][now] == -1) {

        int temp = MAX;

        if(now != 1) {
            temp = min(temp, rcost[i] + getMin(i+1, 1));
        }
        if(now != 2) {
            temp = min(temp, gcost[i] + getMin(i+1, 2));
        }
        if(now != 3) {
            temp = min(temp, bcost[i] + getMin(i+1, 3));
        }

        dp[i][now] = temp;
    }

    return dp[i][now];

}

int main() {
    int i,T,t;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        scanf("%d", &h);

        for(int i=0; i<h; i++) {
            scanf("%d %d %d", &rcost[i], &gcost[i], &bcost[i]);
        }

        printf("Case %d: %d\n", t, getMin(0, 0));
    }
}
