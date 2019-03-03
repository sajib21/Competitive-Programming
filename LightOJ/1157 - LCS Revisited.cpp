#include<bits/stdc++.h>
#define MOD 1000007

using namespace std;

string a,b;
int sz1, sz2, lcs;

int dp[1010][1010];
int dr[1010][1010];

int getLCS(int indxA, int indxB) {

    if(indxA == sz1 || indxB == sz2) return dp[indxA][indxB] = 0;

    if(dp[indxA][indxB] != -1) return dp[indxA][indxB];

    int ans;
    if(a[indxA] == b[indxB]) {
        ans = 1 + getLCS(indxA+1, indxB+1);
        dr[indxA][indxB] = 1;
    }
    else{
        int a = getLCS(indxA+1, indxB) , b = getLCS(indxA, indxB+1);
        if(a == b) {
            ans = a;
            dr[indxA][indxB] = 2;
        }
        else {
            if(a > b) {
                ans = a;
                dr[indxA][indxB] = 3;
            }
            else {
                ans = b;
                dr[indxA][indxB] = 4;
            }
        }
    }

//    dr[indxA][indxB] = 1;
    return dp[indxA][indxB] = ans;
}

int countLCS(int inA, int inB) {

//    if(inA == sz1 || inB == sz2) return 1;
    if(dp[inA][inB] == 0) return 1;
    if(dr[inA][inB] != -1) return dr[inA][inB];
    //int total = lcs;

    int ans = 0;
    int pre = dp[0][0] - dp[inA][inB];
//    for(int total = 0; total < lcs; total++) {
        for(char c = 'a'; c<='z'; c++) {

            int i,j;
            for(i = inA; i < sz1 && a[i] != c; i++) ;
            for(j = inB; j < sz2 && b[j] != c; j++) ;
            if(a[i] == c && b[j] == c && dp[i][j] + pre == lcs) {
//                cout << "CHECKING " << i << ' ' << j << dp[i][j] << endl;
//                total--;
//                printf("%c", c);
//                inA = i+1;
//                inB = j+1;
                ans += countLCS(i+1,j+1) ;
                ans %= MOD;
//                break;
            }
            //if(!total) break;
        }
//    }
    return dr[inA][inB] = ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        lcs = 0;
        memset(dp, -1, sizeof(dp));
        memset(dr,  -1, sizeof(dr));

        cin >> a; cin >> b;
        sz1 = a.size(); sz2 = b.size();

        lcs = getLCS(0,0);
        memset(dr, -1, sizeof(dp));

//        cout << lcs << endl;

        if(lcs) printf("Case %d: %d\n", t, countLCS(0,0) );
        else printf("Case %d: 1\n", t);



//        if(lcs) printLCS(0,0);
//        else printf(":(");

//        printf("\n");
    }

    return 0;
}
