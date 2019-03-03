#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 30000
#define MOD 1000000007
#define MAX 100000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define M 200005
using namespace std;

int n, topFloor;
vii graph[M], costs[M];

int dp[3*100005];

int getMax(int in) {
//    cout << "IN " << in << endl;
    if(in >= topFloor) return 0;
    if(dp[in] != -1) return dp[in];

    int sz = graph[in].size() , ans = 0;
    for(int i=0; i<sz; i++) {
        ans = max(ans, costs[in][i] + getMax(in+graph[in][i]));
    }

    graph[in].clear(); costs[in].clear();

    ans = max(ans, getMax(in+1));
//    cout << "OUT " << in << ' ' << ans << endl;
    return dp[in] = ans;
}


int main() {

//    freopen("1360 out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
//        cout << dp[0] << endl;
//        for(int i=0; i<=MAX; i++) {
//            graph[i].clear() ; costs[i].clear();
//        }
        topFloor = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            int b,e,c;
            scanf("%d %d %d", &b,&e,&c);
            graph[b].pb(e);
            costs[b].pb(c);
            topFloor = max(topFloor, b+e-1);
        }
        printf("Case %d: %d\n", t, getMax(0));
    }

}
