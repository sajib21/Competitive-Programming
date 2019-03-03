#include<bits/stdc++.h>

using namespace std;

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {
        int n;
        int my[53], op[53];
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &my[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &op[i]);
        }
        sort(my, my+n);
        sort(op, op+n);

        int score[53][53] = {0};
        for(int i=0; i<=n; i++) {
            score[i][0] = score[0][i] = 0;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int p=0;
                if(my[i-1] > op[j-1]) p = 2;
                else if(my[i-1] == op[j-1]) p = 1;
                score[i][j] = max(p+score[i-1][j-1], max(score[i-1][j], score[i][j-1]));
            }
        }
        printf("Case %d: %d\n",t, score[n][n]);
    }

    return 0;

}
