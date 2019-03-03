#include<bits/stdc++.h>
#define IM 10000000

using namespace std;

int charge[16][16];
int dp[17000];
int n;

int setBit(int n, int pos) { return n | (1<<pos); }
int resetBit(int n, int pos) { return n & ~(1<<pos); }
int checkBit(int n, int pos) { return n & (1<<pos); }

int minCost(int mask) {

    if(mask == (1<<n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];

    int temp = IM;
    for(int i=0; i<n; i++) {
        if(!checkBit(mask, i)) {

            int total = charge[i][i];
            for(int j=0; j<n; j++) {
                if(i != j) {
                    if(checkBit(mask, j)) total += charge[i][j];
                }
            }
            temp = min(temp, total + minCost(setBit(mask, i)));
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

        memset(charge, 0, sizeof(charge));
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> charge[i][j];
            }
        }

        printf("Case %d: %d\n", t, minCost(0));
    }

    return 0;
}
