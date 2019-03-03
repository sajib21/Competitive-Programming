#include<bits/stdc++.h>

using namespace std;

string a,b,c;
int sz1, sz2, sz3, lcs;

int dp[52][52][52];

int getLCS(int indxA, int indxB, int indxC) {

    if(indxA == sz1 || indxB == sz2 || indxC == sz3) return 0;

    if(dp[indxA][indxB][indxC] != -1) return dp[indxA][indxB][indxC];

    int ans;
    if(a[indxA] == b[indxB] && b[indxB] == c[indxC]) ans = 1 + getLCS(indxA+1, indxB+1, indxC+1);
    else ans = max( getLCS(indxA+1, indxB, indxC) , max( getLCS(indxA, indxB+1, indxC), getLCS(indxA, indxB, indxC+1) ) );

    return dp[indxA][indxB][indxC] = ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        lcs = 0;
        memset(dp, -1, sizeof(dp));

        cin >> a; cin >> b; cin >> c;
        sz1 = a.size(); sz2 = b.size(); sz3 = c.size();

        lcs = getLCS(0,0,0);

        //cout << lcs << endl;

        printf("Case %d: %d", t, lcs);


        printf("\n");
    }

    return 0;
}
