#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int bas, dv;
string num;
char num[18];
int sz;
int modv[17][17];
ll dp[70000][22];
bool isMaskUsed[70000];

int setBit(int mask, int pos) { return mask | (1<<pos); }
int resetBit(int mask, int pos) { return mask & ~(1<<pos); }
int checkBit(int mask, int pos) { return mask & (1<<pos); }

void generatemodvs() {

    for(int i=0; num[i]; i++) {
        int dig;
        if(num[i] >= '0' && num[i] <= '9') {
            dig = num[i] - '0';
        }
        else {
            dig = num[i] - 'A' + 10;
        }
        modv[i][0] = dig % dv;
        for(int j=1; j<sz; j++) {
            modv[i][j] = (modv[i][j-1]*bas) % dv;
        }
    }
}

void permuteCount(int indx, int mask) {

    if(mask == (1<<sz)-1) {
        dp[mask][0] = 1;
        return ;
    }
    if(isMaskUsed[mask] == 1) {
        return ;
    }

    int temp = 0;
    for(int i=0; i<sz; i++) {
        if(!checkBit(mask, i)) {
            int tempMaskI = setBit(mask, i);
            permuteCount(indx+1, tempMaskI);
            for(int tempMaskJ = 0; tempMaskJ < dv; tempMaskJ++) {
                if(dp[tempMaskI][tempMaskJ]) {
                    temp = (modv[indx][i] + tempMaskJ) % dv;
                    dp[mask][temp] += dp[tempMaskI][tempMaskJ];
                    isMaskUsed[mask] = true;
                }
            }
        }
    }
    return ;
}

int main() {

    //ios_base::sync_with_stdio(false);

    int t,T;
    scanf("%d",&T);
    for(t=1; t<=T; t++) {

        memset(dp, 0, sizeof(dp));
        memset(isMaskUsed, 0, sizeof(isMaskUsed));

        scanf("%d %d", &bas, &dv);
        cin >> num;
        //scanf("%s", num);

        sz = strlen(num);
        generatemodvs();
        permuteCount(0, 0);

        printf("Case %d: %lld\n", t, dp[0][0]);
    }

    return 0;
}
