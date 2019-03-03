///NEVER ADD EVEN 1 TO INT_MAX
///IT MAKES IT INT_MIN


#include<bits/stdc++.h>
#define IM INT_MAX-10

using namespace std;

int n, x[18], y[18];
int mask[18][18];
int dp[20][20][200000], taken[18][18];

int setBit(int n, int pos) { return n | (1<<pos); }
int resetBit(int n, int pos) { return n & ~(1<<pos); }
int checkBit(int n, int pos){ return n& (1<<pos); }

bool checkFall(int i, int j, int k) {

    //if(i==j) return true;
    double X = 1.0*(y[k]-y[i])/(y[i]-y[j]), Y = 1.0*(x[k]-x[i])/(x[i]-x[j]);
    //cout << X << " " << Y << endl;;
    return X == Y;
}

void preMasking() {

    memset(mask, 0, sizeof(mask));

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(checkFall(i,j,k)) {
                    mask[i][j] = setBit(mask[i][j], k);
                }
            }
        }
    }
}

int getMin(int a, int b, int takenMask, int debug) {

    if(takenMask == ((1<<n) - 1)) return 0;
    if(a == n-2 && b >= n) return IM;

    if(dp[a][b][takenMask] != -1) return dp[a][b][takenMask];

    int temp = IM;
    int j = b;
    for(int i=a; i<n; i++) {
        for( ; j<n; j++) if(!taken[i][j] && i!=j) {
            if(takenMask | mask[i][j] > takenMask) {
                taken[i][j]=1;
                //cout << debug << "\t points " << i << ' ' << j << endl;
                //cout << debug << "\t" << takenMask << " | " << mask[i][j] << " = " << (takenMask | mask[i][j]) << endl;
                temp = min(temp, 1+getMin(i, j+1, takenMask | mask[i][j], debug+1));
                taken[i][j] = 0;
                //cout << debug << "\ttemp is " << temp << endl;
            }
        }
        j = i+2;
    }

    //cout << "\t" << temp << endl;
    return dp[a][b][takenMask] = temp;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));
        memset(taken, 0, sizeof(taken));

        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);

        if(n==1) {
            printf("Case %d: %d\n", t, 1);
            continue;
        }

        preMasking();

        printf("Case %d: %d\n", t,getMin(0,0, 0, 1));
    }

    return 0;
}
