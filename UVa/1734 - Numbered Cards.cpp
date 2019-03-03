#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int

using namespace std;

int setBit(int mask, int pos) { return mask | (1<<pos); }
int chkBit(int mask, int pos) { return mask & (1<<pos); }

char num[14];
ll fact[15];
int n, sz, target;
ll dp[12][1100][3], dr[12][1100], cnt[520];

int f(int in, int mask, int con) {
    if(in == sz) return 1;
    if(dp[in][mask][con] != -1) return dp[in][mask][con];

    ll ans = 0;

    if(con == 0) {
        for(int i=0; i<num[in]-'0'; i++) {
            if(chkBit(mask, i)) ans += f(in+1, mask, 1);
        }
        if(chkBit(mask, num[in]-'0')) ans += f(in+1, mask, 0);
    }
    else {
        for(int i=0; i<10; i++) {
            if(chkBit(mask, i)) ans += f(in+1, mask, 1);
        }
    }

    return dp[in][mask][con] = ans;
}

ll g(int rem, int mask) {
    if(!rem) mask != 0;
    if(dr[rem][mask] != -1) return dr[rem][mask];

    ll ans = 0;
    for(int take=1; take<target; take+=2) {
        if( (mask & take) <= 1 ) {
            ans += ( f(0, take, 0) - 1 ) * g(rem-1, mask|take);
            ans %= MOD;
        }
    }
    return dr[rem][mask] = ans;
}

int main() {
    fact[0] = 1;
    for(int i=1; i<=10; i++) fact[i] = fact[i-1] * i;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof dp);
        memset(dr, -1, sizeof dr);

        scanf("%s", num);
        sz = strlen(num);
        target = (1 << 9);

        ll ans = 0;

        for(int take=1; take<10; take++) {
            cout << g(take, 1) << endl;
            ans += g(take, 1) / fact[take];
        }

        printf("Case %d: %lld\n", t, ans);
    }
}
