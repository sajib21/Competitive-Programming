#include <bits/stdc++.h>
#define IM 10000

using namespace std;

int n;
int balcony[22];
int dp[1100000];

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

int getMax(int mask) {

    //showBinary(mask);

    if(mask == (1<<n) - 1) return 0;
    if(dp[mask] != -1) return dp[mask];


    int temp = IM;
    for(int i=0; i<n; i++) {
        if(!checkBit(mask, i)) {

            int damage = 0;
            for(int j=0; j<n; j++) {
                if(j != i && j != (i+1)%n && j != (i+2)%n && !checkBit(mask, j)) {
                    damage += balcony[j];
                }
            }
            //cout << damage << endl;
            int tempMask = mask;
            tempMask = setBit(tempMask, i);
            tempMask = setBit(tempMask, (i+1)%n );
            tempMask = setBit(tempMask, (i+2)%n );
            temp = min(temp, damage + getMax(tempMask));
        }
    }

    return dp[mask] = temp;
}

int main() {

    //int n;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0; i<n; i++) cin >> balcony[i];

    cout << getMax(0) << endl;

    return 0;
}
