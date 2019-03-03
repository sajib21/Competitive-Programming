#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

int n,k;
int dp[110][110][110];

int get(int st, int ed, int rem) {
    if(st > ed) return 0;
    if(rem == 1) return ed*(ed+1)/2 - st*(st-1)/2;
    if(dp[st][ed][rem] != -1) return dp[st][ed][rem];

    int ans = INT_MAX;
    for(int i=st; i<=ed; i++) {
        ans = min(ans, i + max( get(st, i-1, rem-1) , get(i+1, ed, rem) ) );
    }
    return dp[st][ed][rem] = ans;
}

int main() {

    memset(dp, -1, sizeof(dp));
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &k,&n);
        printf("Case %d: %d\n", t, get(1, n, k));
    }

    return 0;
}
