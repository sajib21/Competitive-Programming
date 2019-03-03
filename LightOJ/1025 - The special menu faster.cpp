#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int sz;
string seq;
ll dp[62][62];

ll getWays(int left, int right) {

    if(left > right) return 0;
    if(left == right) return 1;

    if(dp[left][right] != -1) return dp[left][right];

    ll ans = 0;

    if(seq[left] == seq[right]) ans = 1 + getWays(left, right-1) + getWays(left+1, right);
    else ans = getWays(left, right-1) + getWays(left+1, right) - getWays(left+1, right-1);

    return dp[left][right] = ans;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        cin >> seq;
        sz = seq.size();

        printf("Case %d: %lld\n", t, getWays(0, sz-1));
        //cout << getWays(0, sz-1) << endl;
    }
}

