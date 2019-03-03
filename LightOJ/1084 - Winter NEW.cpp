#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int n,k, dist[LIM+10], nextPtr[LIM+10];
int dp[LIM+10];

int getMin(int in) {
    if(in >= n) return 0;
    if(dp[in] != -1) return dp[in];

    int x = nextPtr[in];
    x--;

    int ans = MAX;
    for( ; x-2>=in; x--) {
        int temp = 1+getMin(x+1);
        if(temp < ans) ans = min(ans, temp);
//        else break;
    }
    return dp[in] = ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        memset(nextPtr, 0, sizeof(nextPtr));
        scanf("%d %d", &n,&k);
        for(int i=0; i<n; i++) scanf("%d", &dist[i]);
        sort(dist, dist+n);

        queue<int>q;
        q.push(dist[0]+2*k);

        int out = 0, in = 1;
        while(!q.empty() && in < n) {
            while(dist[in] > q.front() && !q.empty()) {
                nextPtr[out++] = in;
                q.pop();
            }
            q.push(dist[in]+2*k);
            in++;
        }
        while(!q.empty()) {
            nextPtr[out++] = n;
            q.pop();
        }

        int ans = getMin(0);
        if(ans == MAX) printf("Case %d: -1\n", t);
        else printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
