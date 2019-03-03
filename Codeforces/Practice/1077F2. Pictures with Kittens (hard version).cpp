#include<bits/stdc++.h>
#define LIM 5003
#define ll long long int
#define MIN -100000000000000000LL

using namespace std;

int n,sz,x, a[LIM];
ll dp[LIM][LIM];

int main() {
    scanf("%d %d %d", &n, &sz, &x);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    for(int i=0; i<=5000; i++) {
        for(int j=0; j<=5000; j++) dp[i][j] = MIN;
    }
    dp[0][0] = 0;


    for(int k=1; k<=x; k++) {
        deque<int>dq;
        for(int i=0; i<k; i++) {
            while(!dq.empty() && dp[k-1][dq.back()] < dp[k-1][i]) dq.pop_back();
            dq.push_back(i);
        }

        for(int i=k; i<=n; i++) {
            int last = i-sz;
            while(!dq.empty() && dq.front() < last) dq.pop_front();
            dp[k][i] = a[i] + dp[k-1][dq.front()];

            while(!dq.empty() && dp[k-1][dq.back()] < dp[k-1][i]) dq.pop_back();
            dq.push_back(i);
        }

    }

    ll ans = MIN;
    for(int i=n-sz+1; i<=n; i++) ans = max(ans, dp[x][i]);

    if(ans < 0) cout << -1 << endl;
    else cout << ans << endl;

}
