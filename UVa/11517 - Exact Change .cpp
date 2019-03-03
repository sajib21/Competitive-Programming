#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>

using namespace std;

int n,make, bill[103];
int dp[22004];
//int lv=0, lb=0;

void solve() {

    memset(dp, 0, sizeof(dp));
    //for(int i=0; i<=20004; i++) dp[i] = 200000;
    //cout << lv << " and " << lb << endl;
    //dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=20000-bill[i]+1; j >= 0 ; j--) { ///zeta banaite chai
            if(dp[j]) {
                if(dp[j+bill[i]] == 0 || dp[j+bill[i]] > 1+dp[j]) {
                    dp[bill[i]+j] = 1 + dp[j];
                }
            }
        }
        dp[bill[i]] = 1;
    }



    //cout << dp[500] << ' ' << dp[1000] << ' ' << dp[1400] << ' ' << dp[1500] << ' ' << dp[2000] << endl;

    int lv = 0; int lb = 0;

    for(int i=make; i<=20000 ; i++) {
        if(dp[i]) {
            //cout << "change hoy i = " << i << endl;
            lv = i;
            lb = dp[i];
            break;
        }
        //cout << i << " e dp value " << dp[i] << endl;
    }
    printf("%d %d\n", lv, lb);
    //cout << lv << ' ' << lb << endl;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        //lv = lb = 0;


        scanf("%d %d", &make, &n);
        for(int i=0; i<n; i++) scanf("%d", &bill[i]);
        sort(bill, bill+n);

        solve();


    }

    return 0;
}

