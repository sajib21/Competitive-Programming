///NEVER ADD EVEN 1 TO INT_MAX
///IT MAKES IT INT_MIN
///WHENEVER YOU USE BOOLEAN AND BITWISE OPERATOR MUST USE BRACKET


#include<bits/stdc++.h>
#define IM INT_MAX-10

using namespace std;

int n, x[18], y[18], sz;
int mask[18][18], lim;
int dp[70000];
vector<int>mvs;

int setBit(int n, int pos) { return n | (1<<pos); }
int resetBit(int n, int pos) { return n & ~(1<<pos); }
int checkBit(int n, int pos){ return n& (1<<pos); }

void printBin(int n) {

    if(!n) return;
    printBin(n>>1);
    cout << n%2;
}

bool checkFall(int i, int j, int k) {

    if(i==k || j==k) return true;
    int area = (x[i]-x[j])*(y[j]-y[k]) - (x[j]-x[k])*(y[i]-y[j]);
    return area == 0;
}

void preMasking() {

    memset(mask, 0, sizeof(mask));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
//            mask = 0;
            for(int k=0; k<n; k++) {
                if(i!=j && checkFall(i,j,k)) {
                    mask[i][j] |= 1 << k;
//                    mask |= 1 << k;
                }
            }
//            mvs.push_back(mask);
        }
    }

}

int getMin(int takenMask) {

    if(takenMask == lim ) return 0;
    if (__builtin_popcount(takenMask) == (n - 1)) return dp[takenMask] = 1;

//    if(a >= n) return IM;

    if(dp[takenMask] != -1) return dp[takenMask];

    int temp = IM;


    int i;


    int tm = takenMask;
    for(i=0; tm%2; i++) tm = tm >> 1;
    tm = takenMask;
    for(int j=0; j<n; j++) {
        if( i!=j && tm%2==0 ) {
            temp = min(temp , 1 + getMin(takenMask | mask[i][j]) );
        }
        tm = tm >> 1;
    }

    return dp[takenMask] = temp;

}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));
        mvs.clear();

        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);

        if(n==1 || n==2) {
            printf("Case %d: %d\n", t, 1);
            continue;
        }

        lim = (1 << n) - 1;

        preMasking();
        printf("Case %d: %d\n", t,getMin(0));
    }

    return 0;
}
