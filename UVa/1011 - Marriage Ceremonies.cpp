#include<bits/stdc++.h>

using namespace std;

int priorIndex[17][17];
//int takenColumn[17];
int n;

int dp[66000];

int setBit(int n, int pos) {
    return n | (1<<pos);
}
int resetBit(int n, int pos) {
    return n & ~(1<<pos);
}
int checkBit(int n, int pos) {
    return n & (1<<pos);
}

int power(int base, int p) {
    int temp = 1;
    while(p--) {
        temp *= base;
    }
    return temp;
}

int maxSum(int row, int mask) {

    //if(row >= n) return 0;
    if(mask == pow(2,n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];

    int temp = 0;
    for(int i=0; i<n; i++) {
        if(!checkBit(mask, i)) {
            //takenColumn[i] = 1;
            temp = max(temp, priorIndex[row][i] + maxSum(row+1, setBit(mask, i)) );
            //takenColumn[i] = 0;
        }
    }

    return dp[mask] = temp;
}

int main() {

    int t,T;
    cin >> T;
    for(t=1; t<=T; t++) {

        //int n;
        cin >> n;
        memset(priorIndex, 0, sizeof(priorIndex));
        memset(dp, -1, sizeof(dp));
        //memset(takenColumn, 0, sizeof(takenColumn));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> priorIndex[i][j];
            }
        }

        //cout << maxSum(0) << endl;
        printf("Case %d: %d\n",t, maxSum(0, 0));
    }

    return 0;
}
