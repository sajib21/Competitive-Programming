#include <bits/stdc++.h>

using namespace std;

int cent[] = {50, 25, 10, 5, 1};
int dp[10][10000];

int getMax(int i, int n) {

    if(i == 5) {
        if(!n) return 1;
        else return 0;
    }

    if(dp[i][n] != -1) return dp[i][n];
    else {
        int c1, c2;
        if(n-cent[i] >= 0)
            c1 = getMax(i, n-cent[i]);
        else c1 = 0;
        c2 = getMax(i+1, n);

        return dp[i][n] = c1 + c2;


    }


}

int main() {

    int n;

    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &n) != EOF) {

        printf("%d\n", getMax(0, n));

    }

}
