#include <bits/stdc++.h>
#define MOD 100000000

using namespace std;

//int person[3] = {0,1};
//int n[3];
//int k[3];
int k1,k2;

long long int dp[101][101][3];

long long int getMax(int n1, int n2, int flag) {


    if(!flag) {
        if(!n1) {
            if(!n2) return 1;
            else return 0;
        }

        if(dp[n1][n2][flag] != -1) return dp[n1][n2][flag];

        long long int temp = 0;

        for(int i = 1; i <= k1 && i <= n1;  i++) {
            temp = (temp + getMax(n1-i, n2, 1)) % MOD ;
        }

        return dp[n1][n2][flag] = temp;

    }

    else {
        if(!n2) {
            if(!n1) return 1;
            else return 0;
        }

        if(dp[n1][n2][flag] != -1) return dp[n1][n2][flag];

        long long int temp = 0;

        for(int i = 1; i <= k2 && i <= n2;  i++) {
            temp = (temp + getMax(n1, n2-i, 0)) % MOD ;
        }

        return dp[n1][n2][flag] = temp;

    }


}

int main() {

    int n1,n2;
    //int flag = 0;
    // k1,k2;
    memset(dp, -1, sizeof(dp));

    //scanf("%d %d %d %d", &n[0],&n[1], &k[0],&k[1]);
    cin >> n1 >> n2 >> k1 >> k2;

    printf("%64d\n", (getMax(n1, n2, 0) + getMax(n1,n2, 1))%MOD );

    return 0;
}
