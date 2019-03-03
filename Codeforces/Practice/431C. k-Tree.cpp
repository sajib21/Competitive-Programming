#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

int n,k,d;
ll dp[110][3];

ll getMax(int taken, int con) {

    if(taken == n) {
        if(con) return 1;
        else return 0;
    }
    if(taken > n) return 0;

    if(dp[taken][con] != -1) return dp[taken][con];

    int temp = 0, rem = n-taken;
    for(int i=1; i <= k && i <= rem; i++) {
        temp = (temp + getMax(taken+i, (i>=d) | con ) ) % MOD;
    }

    return dp[taken][con] = temp;
}

int main() {

    memset(dp, -1, sizeof(dp));

    scanf("%d %d %d", &n,&k,&d);

     //getMax(0,0, 0);
    cout << getMax(0,0) << endl;

}
