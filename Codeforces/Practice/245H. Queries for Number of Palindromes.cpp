#include <bits/stdc++.h>

using namespace std;

int n, sz;
string seq;
int   dp[5050][5050];
int   dr[5050][5050];
bool pal[5050][5050];

int main() {
    cin >> seq;
    sz = seq.size();

    for(int i=0; i<sz; i++) pal[i][i] = 1;


    for(int p=1; p<sz; p++) {
        for(int i=0; i<sz; i++) {
            int j = i+p;
            if(j >= sz) break;
            if(pal[i+1][j-1] && seq[i] == seq[j]) pal[i][j] = 1;
            else if(i+1 == j && seq[i] == seq[j]) pal[i][j] = 1;
        }
    }

//    for(int i=0; i<sz; i++) {
//        for(int j=i+1; j<sz; j++) {
//            if(pal[i+1][j-1] && seq[i] == seq[j]) pal[i][j] = 1;
//            else if(i+1 == j && seq[i] == seq[j]) pal[i][j] = 1;
//        }
//    }

//    cout << "PAL" << endl;
////    cout << "DR" << endl;
//    for(int i=0; i<sz; i++) {
//        for(int j=0; j<sz; j++) {
//            cout << pal[i][j] << ' ' ;
//        }
//        cout << endl;
//    }

    memset(dp, 0, sizeof dp);
    for(int i=0; i<sz; i++) {
        dp[i][i] = pal[i][i];
        for(int j=i+1; j<sz; j++) dp[i][j] = dp[i][j-1] + pal[i][j];
    }

//    cout << "DP" << endl;
////    cout << "DR" << endl;
//    for(int i=0; i<sz; i++) {
//        for(int j=0; j<sz; j++) {
//            cout << dp[i][j] << ' ' ;
//        }
//        cout << endl;
//    }

    for(int j=sz-1; j>=0; j--) {
        dr[j][j] = dp[j][j];
        for(int i=j-1; i>=0; i--) {
            dr[i][j] = dr[i+1][j] + dp[i][j];
        }
    }

//    cout << "DR" << endl;
//    for(int i=0; i<sz; i++) {
//        for(int j=0; j<sz; j++) {
//            cout << dr[i][j] << ' ' ;
//        }
//        cout << endl;
//    }

    scanf("%d", &n);
    while(n--) {
        int l,r;
        scanf("%d %d", &l,&r); l--; r--;
        printf("%d\n", dr[l][r]);
    }
    return 0;
}
