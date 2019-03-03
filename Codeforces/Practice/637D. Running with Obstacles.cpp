#include<bits/stdc++.h>
#define LIM 200005
#define pii pair<int,int>
#define pb push_back

using namespace std;

int n,m,s,d, a[LIM];
int dp[LIM], vis[LIM];

int main() {
    scanf("%d %d %d %d", &n, &m, &s,&d);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]) , a[i]++; /// reduced to at least step on a[i]
    sort(a+1, a+n+1);

    int cur = 0;
    while(cur >= 0 && !vis[cur] && cur < n) {
//        cout << cur << endl; getchar();
        vis[cur] = 1;
        int runway = a[cur+1]-2 - a[cur];
//        cout << cur << ' ' << a[cur] << ' ' << a[cur+1] << ' ' << runway << endl; getchar();
        if(runway < s) {
            cur--;
            if(cur < 0 || vis[cur]) break;
            dp[cur] = dp[cur+1];
        }
        else {
            int in = upper_bound(a, a+n+1, a[cur]+runway+d) - a;
            in--;
            dp[in] = cur;
            cur = in;
        }
    }

    if(cur != n) printf("IMPOSSIBLE\n");
    else {
        vector<pii>sol;
        sol.pb(pii(0, m-a[cur]));
        while(cur) {
            int pre = dp[cur];
            int airway = a[cur]-a[pre+1]+2;
            sol.pb(pii(1,airway));
            int runway = a[pre+1]-2-a[pre];
            sol.pb(pii(0,runway));
            cur = pre;
        }
        reverse(sol.begin(), sol.end());
        for(int i=0; i<sol.size(); i++) {
            if(sol[i].second) {
                if(sol[i].first) printf("JUMP ");
                else printf("RUN ");
                printf("%d\n", sol[i].second);
            }
        }
    }
    return 0;
}
