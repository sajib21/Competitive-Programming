#include<bits/stdc++.h>
#define ll long long int
#define LIM 200

///NEVER MEMSET 1 FOR LONG LONG INT, NO PROBLEM FOR -1

using namespace std;

int n, m, d;
ll ara[LIM+10];
int Q;
ll dp[LIM+10][12][24];

ll query(int indx, int remTake, ll remMod) {

    if(!remTake) {
        if(!remMod) {
//            cout << "BASE CASE " << debug << endl;
            return 1;
        }
        else return 0;
    }
    if(indx == n) return 0;
    if(dp[indx][remTake][remMod] != -1) return dp[indx][remTake][remMod];

    ll a=0,b=0;
//    if(!remMod) c++ , cout << "NORM " << debug << endl;
    a = query(indx+1, remTake-1, ( remMod+ara[indx]+ 10000000000LL*d )%d ); ///LONG LONG INT SIZE ER CONSTANT NITE LL USE KORBO
    b = query(indx+1, remTake, remMod);

    return dp[indx][remTake][remMod] = a+b;
}

int main() {

//    memset(dp, 1, sizeof(dp));
//    cout << dp[10][5][4] << endl;

    int T, lines = 0;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d %d", &n,&Q);
        for(int i=0; i<n; i++) scanf("%lld", &ara[i]);
//        printf("LINES %d : Case %d:\n",++lines, t);
        printf("Case %d:\n", t);
        for(int q=1; q<=Q; q++) {
            memset(dp, -1, sizeof(dp));
            scanf("%d %d", &d, &m);
//            printf("LINES %d : %lld\n",++lines, query(0, m, 0) );
            printf("%lld\n", query(0, m, 0) );
        }
//        cout << "DONE" << endl;
    }
    return 0;
}
