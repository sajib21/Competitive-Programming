#include<bits/stdc++.h>

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

string num;
int d, sz;
int dp[1050][1010];

int f(int mask, int rem) {



    if(mask == ( (1 << sz)-1) ) {
        if(!rem) return 1;
        else return 0;
    }
    if(dp[mask][rem] != -1) return dp[mask][rem];
    int ans = 0;
    for(int i=0; i<sz; i++) {
        if(!chkBit(mask, i)) {
//            cout << mask << ' ' << rem << endl;
            ans += f(setBit(mask, i), (10*rem+num[i]-'0') % d );
        }
    }
    return dp[mask][rem] = ans;
}

int main() {

    int fact[12] = {1};
    for(int i=1; i<=10; i++) fact[i] = fact[i-1]*i;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        cin >> num;
        sz = num.size();
        scanf("%d", &d);
//        sort(num.begin() , num.end());
        int flag[12] = {0};
        for(int i=0; i<sz; i++) flag[ num[i] - '0' ]++;

        int ans = f(0, 0);
//        cout << ans << endl;
        for(int i=0; i<10; i++) if(flag[i] > 1) ans /= fact[ flag[i] ];

        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
