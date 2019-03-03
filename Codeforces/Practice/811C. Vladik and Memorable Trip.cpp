#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int n, ara[5005], st[5005], ed[5005], crs[5005];

int dp[5005];

int getMax(int in) {
    if(in >= n) return 0;
    if(dp[in] != -1) return dp[in];
    int u = ara[in];
    if(crs[ u ] || st[ u ] != in) return dp[in] = getMax(in+1);

    int flag[5005] = {0};
    int ans = 0, temp = 0;
    for(int i=in; i<=ed[u]; i++) if(!flag[ ara[i] ]) {
        temp ^= ara[i];
        flag[ ara[i] ] = 1;
    }
    ans = temp + getMax(ed[u]+1);

    ans = max(ans, getMax(in+1));

    return dp[in] = ans;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d", &n);
    memset(st, -1, sizeof(st));
    memset(ed, -1, sizeof(ed));
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) {
        scanf("%d", &ara[i]);
        if(st[ ara[i] ] == -1) st[ ara[i] ] = i;
        ed[ ara[i] ] = i;
    }

    stack<int>stk;
    for(int i=0; i<n; i++) {
        if(st[ ara[i] ] == ed[ ara[i] ]) {
            continue;
        }
        if(stk.empty()) {
            stk.push(ara[i]);
            continue;
        }

        while(!stk.empty()) {
            int u = stk.top();
            int v = ara[i];
            if(ed[u] == i) {
                stk.pop(); break;
            }
            if(u == v ) {
                if(i == ed[v]) stk.pop();
                break;
            }
            else if(st[v] == i) {
                if(ed[u] < ed[v] ) {
                    if(!crs[u]) {
                        ed[u] = ed[v];
                    }

                    crs[v] = 1;

                    break;
                }
                else {
                    stk.push(v);
                    break;
                }
            }
            else {
                if(st[u] > st[v]) {
                    crs[u] = 1;
                    stk.pop();
                }
                else {
                    if(st[v] != ed[v] && !crs[v]) stk.push(v); ///
                    break;
                }
            }
        }
    }

    int ans = 0;
    printf("%d\n", getMax(0));

    return 0;
}

