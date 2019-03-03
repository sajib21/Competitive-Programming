// BACKTRACING
// TLE!!!
// NEED BITMASKING!!

#include<bits/stdc++.h>

using namespace std;

int priorIndex[17][17];
int takenColumn[17];
int n;

int maxSum(int row) {

    if(row >= n) return 0;

    int temp = 0;
    for(int i=0; i<n; i++) {
        if(!takenColumn[i]) {
            takenColumn[i] = 1;
            temp = max(temp, priorIndex[row][i] + maxSum(row+1) );
            takenColumn[i] = 0;
        }
    }

    return temp;
}

int main() {

    int t,T;
    cin >> T;
    for(t=1; t<=T; t++) {

        //int n;
        cin >> n;
        memset(priorIndex, 0, sizeof(priorIndex));
        memset(takenColumn, 0, sizeof(takenColumn));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> priorIndex[i][j];
            }
        }

        //cout << maxSum(0) << endl;
        printf("Case %d: %d\n",t, maxSum(0));
    }

    return 0;
}
