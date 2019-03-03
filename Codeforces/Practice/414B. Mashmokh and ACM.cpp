#include<bits/stdc++.h>
#define ll long long int
#define LIM 2000
#define MOD 1000000007

using namespace std;

int n,k;
ll dp[LIM+10][LIM+10];

ll getComb(int indx, int last) {

    if(indx == k) return 1;
    if(dp[indx][last] != -1) return dp[indx][last];

    ll ans = 0;
    for(int i=last; i<=n; i+=last) {
        ans = (ans + getComb(indx+1, i) ) % MOD;
    }

    return dp[indx][last] = ans;
}

int main() {

    memset(dp, -1, sizeof(dp));

    cin >> n >> k ;
    cout << getComb(0, 1) << endl;

    return 0;

}
