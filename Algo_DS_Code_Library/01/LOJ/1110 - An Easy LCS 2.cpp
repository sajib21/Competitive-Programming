#include<bits/stdc++.h>

using namespace std;

string a,b;
int sz1, sz2, lcs;

int dp[110][110];

int getLCS(int indxA, int indxB) {

    if(indxA == sz1 || indxB == sz2) return 0;

    if(dp[indxA][indxB] != -1) return dp[indxA][indxB];

    int ans;
    if(a[indxA] == b[indxB]) ans = 1 + getLCS(indxA+1, indxB+1);
    else ans = max( getLCS(indxA+1, indxB) , getLCS(indxA, indxB+1) );

    return dp[indxA][indxB] = ans;
}

int printLCS(int inA, int inB) {

    //if(indxA == sz1 || indxB == sz2) return ;

    //int total = lcs;

    int ans = 0;

    for(int total = 0; total < lcs; total++) {
        for(char c = 'a'; c<='z'; c++) {

            int i,j;
            for(i = inA; i < sz1 && a[i] != c; i++) ;
            for(j = inB; j < sz2 && b[j] != c; j++) ;
            if(a[i] == c && b[j] == c && dp[i][j] + total == lcs) {
//                total--;
//                printf("%c", c);
                inA = i+1;
                inB = j+1;
                ans++;
//                break;
            }
            //if(!total) break;
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        lcs = 0;
        memset(dp, -1, sizeof(dp));

        cin >> a; cin >> b;
        sz1 = a.size(); sz2 = b.size();

        lcs = getLCS(0,0);

        //cout << lcs << endl;

        printf("Case %d: ", t);
        if(lcs) printLCS(0,0);
        else printf(":(");

        printf("\n");
    }

    return 0;
}
