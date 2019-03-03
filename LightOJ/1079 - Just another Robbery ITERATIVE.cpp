#include<bits/stdc++.h>

using namespace std;

double p, prob[110];
int n, money[110], total;
double dp[110][20010];

int main() {

//    freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

//        memset(dp, -1, sizeof(dp));
        for(int i=0; i<=100; i++) {
            for(int j=0; j<=20000; j++) {
                dp[i][j] = 1;
            }
        }

        total = 0;
        scanf("%lf %d", &p, &n);
        for(int i=1; i<=n; i++) {
            scanf("%d %lf", &money[i], &prob[i]);
            total += money[i];
        }

        dp[0][0] = 0;
        for(int i=1; i<=n; i++) {
            dp[i][0] = 0;
            for(int j=0; j<money[i]; j++) dp[i][j] = dp[i-1][j];
            for(int j=money[i]; j<=total; j++) {
                double pre = dp[i-1][ j-money[i] ];
                dp[i][j] = min( pre + (1-pre)*prob[i] , dp[i-1][j] );
            }
        }

//        for(int i=0; i<=n; i++) {
//            for(int j=0; j<=total; j++) {
//                printf("%5.2lf ", dp[i][j]);
//            }
//            printf("\n\n");
//        }


        int ansMil=0, ansProb = 1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=total; j++) {
                if(dp[i][j] < p) {
                    ansMil = max(ansMil, j);
                }
            }
        }
        printf("Case %d: %d\n", t, ansMil);
    }

    return 0;

}
