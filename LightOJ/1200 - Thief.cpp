#include<bits/stdc++.h>

using namespace std;

int n, cap;
int price[110], quantity[110], weight[110];
int dp[110][10100];

int getMax(int indx, int left) {

    if(indx == n || left == 0) return 0;
    if(left < 0) return INT_MIN;
    if(dp[indx][left] != -1) return dp[indx][left];

//    if(!quantity[indx]) {
//        return dp[indx][left] = getMax(indx+1, left);
//    }
    else {
        return dp[indx][left] =
        max( price[indx] + getMax(indx, left-weight[indx]) ,
            getMax(indx+1, left));
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        scanf("%d %d", &n,&cap);
        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &price[i], &quantity[i], &weight[i]);
            cap -= weight[i]*quantity[i];
        }

        if(cap < 0) {
            printf("Case %d: Impossible\n", t);
            continue;
        }

        printf("Case %d: %d\n",t, getMax(0, cap));
    }

    return 0;
}
