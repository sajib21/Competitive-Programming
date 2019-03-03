#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

string num;
int n,m;
ll target, dp[1 << 18][101];

ll f(int mask, int rem) {
    if(mask == target) return rem == 0;
    if(dp[mask][rem] != -1) return dp[mask][rem];
    ll ans = 0;
    int last = -1;
    for(int i=0; i<n; i++) if(!chkBit(mask, i)) {
        if(!mask && num[i] == '0') continue;
        if(num[i]-'0' == last) continue;
        ans += f(setBit(mask, i), (rem*10 + num[i]-'0')%m );
        last = num[i] - '0';
    }
    return dp[mask][rem] = ans;
}

int main() {
    cin >> num >> m;
    sort(num.begin(), num.end());
    n = num.size();
    memset(dp, -1, sizeof dp);
    target = (1 << n) - 1;
    printf("%I64d\n", f(0, 0));
}
