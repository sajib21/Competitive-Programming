#include <bits/stdc++.h>
#define bugy cout << "debug" << endl;
using namespace std;

string A,B;
int sz1,sz2, K;

int dp[11][5][85][85];
//int dp[11][5][10004];

int getCount(int indx, int where, int numMod, int digMod) {

    if(indx == sz1) {
        if(!numMod && !digMod) return 1;
        else return 0;
    }

    //if(dp[indx][where][numMod] != -1) return dp[indx][where][numMod];
//    if(dp[indx][where][digMod] != -1) return dp[indx][where][digMod];
    if(dp[indx][where][numMod][digMod] != -1) return dp[indx][where][numMod][digMod];

    //bugy

    int temp = 0;
    if(where == 0) {
        if(A[indx] == B[indx]) {
            temp += getCount(indx+1, 0, (numMod*10 + A[indx]) % K, (digMod + A[indx]) % K );
        }
        else {
            temp += getCount(indx+1, 1, (numMod*10 + A[indx]) % K, (digMod + A[indx]) % K );
            for(int i=A[indx]+1; i<B[indx]; i++) {
                temp += getCount(indx+1, 2, (numMod*10 + i) % K, (digMod + i) % K );
            }
            temp += getCount(indx+1, 3, (numMod*10 + B[indx]) % K, (digMod + B[indx]) % K );
        }
    }

    else if(where == 1) {
        temp += getCount(indx+1, 1, (numMod*10 + A[indx]) % K, (digMod + A[indx]) % K );
        for(int i=A[indx]+1; i<=9; i++) {
            temp += getCount(indx+1, 2, (numMod*10 + i) % K, (digMod + i) % K );
        }
    }

    else if(where == 2) {
        for(int i=0; i<=9; i++) {
            temp += getCount(indx+1, 2, (numMod*10 + i) % K, (digMod + i) % K );
        }
    }
    else if(where == 3) {
        for(int i=0; i<B[indx]; i++) {
            temp += getCount(indx+1, 2, (numMod*10 + i) % K, (digMod + i) % K );
        }
        temp += getCount(indx+1, 3, (numMod*10 + B[indx]) % K, (digMod + B[indx]) % K );
    }
    //cout << temp << endl;
    //getchar();
//    return dp[indx][where][numMod] = temp;
//    return dp[indx][where][digMod] = temp;
    return dp[indx][where][numMod][digMod] = temp;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        cin >> A >> B;
        scanf("%d", &K);
        if(K > 82) {
            printf("Case %d: %d\n", t, 0);
            continue;
        }

        sz1 = A.size(); sz2 = B.size();
        if(sz1 != sz2) {
            int temp = sz2-sz1;
            string tmp;
            while(temp--) tmp = tmp + '0';
            A = tmp + A;
        }
        sz1 = sz2;
        //cout << A << endl;

        for(int i=0; i<sz1; i++) A[i] -= '0' , B[i] -= '0';

        printf("Case %d: %d\n", t, getCount(0, 0, 0,0));

    }
}
