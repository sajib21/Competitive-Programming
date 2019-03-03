#include<bits/stdc++.h>

using namespace std;

char seq1[105], seq2[105];
int sz1, sz2;
char ans[105];

int dp[104][104];

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(ans, 0, sizeof(ans));
        //cin >> seq1 >> seq2;
        scanf("%s %s", seq1, seq2);
        sz1 = strlen(seq1), sz2 = strlen(seq2);
        printf("%s %s\n", seq1, seq2);

        for(int i=0; i<=100; i++) dp[i][0] = dp[0][i] = 0;

        for(int i=0; i<sz2; i++) {
            for(int j=0; j<sz1; j++) {
//                cout << i << " sq2 te " << seq2[i] << " " << j << " sq1 te " << seq1[j] << endl;
                if(seq2[i] == seq1[j]) {
//                    cout << seq1[j] << endl;
                    //printf("%c\n", seq1[i]);
                    dp[i+1][j+1] = 1 + dp[i][j];
                    if(ans[ dp[i+1][j+1] ] == 0 || seq1[j] < ans[ dp[i+1][j+1] ]) {
                        ans[ dp[i+1][j+1] ] = seq1[j];
//                        cout << ans[ dp[i+1][j+1] ] << endl;
                    }
                }
                else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        ans[ dp[sz2][sz1] + 1 ] = 0;
        //cout << dp[sz2][sz1] << endl;
        printf("Case %d: ", t);
        for(int i=1; i<=dp[sz2][sz1]; i++) printf("%c", ans[i]);
        printf("\n");
    }

    return 0;
}
