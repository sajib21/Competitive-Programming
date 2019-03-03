#include<bits/stdc++.h>

using namespace std;

int n, health[16];
int guns[16][16];
int dp[66000];

int setBit(int mask, int pos) { return mask | (1<<pos); }
int resetBit(int mask, int pos) { return mask & ~(1<<pos); }
int checkBit(int mask, int pos) { return mask & (1<<pos); }

void showBinary(int mask) {

    for(int i=0; i<n; i++) {
        cout << mask%2 << ' ';
        mask /= 2;
    }
    cout << endl;
}

int getMin(int mask) {

    //showBinary(mask);

    if(mask == (1<<n) - 1) return 0;
    if(dp[mask] != -1) return dp[mask];

    int temp = INT_MAX;

    for(int i=0; i<n; i++) {
        if(!checkBit(mask, i)) {
            int dam = 1;
            for(int j=0; j<n; j++) {
                if(j!=i && checkBit(mask, j)) {
                    dam = max(dam, guns[j][i]);
                }
            }
            temp = min(temp, (health[i]+dam-1)/dam + getMin(setBit(mask, i)) ) ;
        }
    }

    return dp[mask] = temp;
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        cin >> n;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++) cin >> health[i];
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            scanf("%1d", &guns[i][j]);
        }
//        for(int i=0; i<n; i++) {
//            for(int j=0; j<n; j++) {
//                cout << guns[i][j] << ' ';
//            }
//            cout << endl;
//        }

        printf("Case %d: %d\n", t, getMin(0));

    }
}
