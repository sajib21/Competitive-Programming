#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
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

int m,n,c, grid[2002][2002];

int histogram() { ///ASSUMES N = SIZE, H = ARA (0 BASED)
    stack<int>stk;
    int i = 0, answer=0, ans=0;

    for(int c=0; c<n; c++) {
        i = 0;
        while(i < m) {
            if(stk.empty() || grid[stk.top()][c] <= grid[i][c]) stk.push(i++);
            else {
                int tp = stk.top();
                stk.pop();
                ans = max(ans, grid[tp][c] * (stk.empty()? i : i-stk.top()-1));
            }
        }
        while(!stk.empty()) {
            int tp = stk.top();
            stk.pop();
            ans = max(ans, grid[tp][c] * (stk.empty()? i : i-stk.top()-1));
        }
    }
    return ans;
}

int main() {

//    freopen("1424.txt", "r", stdin);
//    freopen("1424o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &m,&n);
        memset(grid, 0, sizeof grid);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                scanf("%1d", &c);
                grid[i][j] = !c;
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(grid[i][j]) grid[i][j] += grid[i][j-1];
            }
        }
        printf("Case %d: %d\n", t, histogram());
    }
    return 0;
}
