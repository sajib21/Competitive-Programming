#include<bits/stdc++.h>
#define lim 2147483650

using namespace std;
int adjBitCount[21474836];

void getAdjBit(int indx, int lastWeight, int lastBit, int lastCount) {

    if(indx == 11) return;

    getAdjBit(indx+1, lastWeight, 0, lastCount);

    if(lastBit == 1) {
        adjBitCount[lastWeight + (1<<indx)] += lastCount+1;
        getAdjBit(indx+1, lastWeight+(1<<indx), 1,  lastCount+1);
    }
    else {
        adjBitCount[lastWeight + (1<<indx)] += lastCount;
        getAdjBit(indx+1, lastWeight+(1<<indx), 1,  lastCount);
    }
}

int main() {

    getAdjBit(0, 0, 0, 0); ///kototomo digit, pichoner weight, pichoner bit, pichoner adjCount

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        int n;
        scanf("%d", &n);
        printf("%d\n", adjBitCount[n]);
    }

    return 0;

}
