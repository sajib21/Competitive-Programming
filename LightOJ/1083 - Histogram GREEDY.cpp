#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 30000
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

int n, h[LIM+10];

int histogram(int n, int h[]) { ///ASSUMES N = SIZE, H = ARA (0 BASED)
    stack<int>stk;
    int i = 0, ans=0;
    while(i < n) {
        if(stk.empty() || h[stk.top()] <= h[i]) stk.push(i++);
        else {
            int tp = stk.top();
            stk.pop();
            ans = max(ans, h[tp] * (stk.empty()? i : i-stk.top()-1));
        }
    }
    while(!stk.empty()) {
        int tp = stk.top();
        stk.pop();
        ans = max(ans, h[tp] * (stk.empty()? i : i-stk.top()-1));
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &h[i]);
        printf("Case %d: %d\n", t, histogram(n, h));
    }
    return 0;
}
