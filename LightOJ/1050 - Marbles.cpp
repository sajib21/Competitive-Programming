#include<bits/stdc++.h>
#define LIM 500

using namespace std;

int r,b;
double dp[LIM+5][LIM+5];

double get(int rtake, int btake) {

    if(btake < 0) return 0;
    if(rtake > btake) return 0;
    if(!rtake) return 1;
    if(dp[rtake][btake] != -1) return dp[rtake][btake];

    return dp[rtake][btake] = 1.0 * rtake/(rtake+btake+1) * get(rtake-1, btake-1) + 1.0 * (btake+1)/(rtake+btake+1) * get(rtake, btake-2);
}

int main() {
    for(int i=0; i<=LIM; i++) for(int j=0; j<=LIM; j++) dp[i][j] = -1;
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
//        memset(dp, -1, sizeof(dp));


//        for(int i=0; i<5; i++) for(int j=0; j<5; j++) cout << dp[i][j] << endl;

        scanf("%d %d", &r,&b);

//        if(r > b) {
//            printf("Case %d: 0\n", t);
//            continue;
//        }
//        cout << r << ' ' << b << endl;
        printf("Case %d: %.10lf\n", t, get(r,b-1) );
    }
    return 0;
}
