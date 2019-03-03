#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 200005
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

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

int n, m,c;
ll pos[LIM+10], cnt[20], prep[20][20], target;
ll dp[(1 << 16)+100];

ll getMin(int mask) {
//    if(!in) cout << "IN " << in << ' ' << mask << ' ' << endl;
    if(mask == target) return 0;
    if(dp[mask] != -1) return dp[mask];

    ll ans = 10000000000000000LL;
    for(int i=0; i<m; i++) if(!chkBit(mask, i)) {
        ll temp = 0;
        for(int j=0; j<m; j++) if(chkBit(mask, j)) temp += prep[i][j];
        if(temp > ans) continue;
        temp += getMin(setBit(mask, i));
        ans = min(ans, temp);
    }
    return dp[mask] = ans;
}

int main() {
//    freopen("1194i.txt", "r", stdin);
//    freopen("1194o.txt", "w",stdout);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(cnt, 0, sizeof cnt );
        memset(prep,0, sizeof prep);
        memset(dp, -1, sizeof dp  );
        scanf("%d %d", &n,&m);
        target = (1 << m) - 1;
        for(int i=1; i<=n; i++) {
            scanf("%d", &c); c--;
            pos[i] = c;
        }
        for(int i=1; i<=n; i++) {
            for(int j=0; j<m; j++) if(pos[i] != j) prep[j][ pos[i] ] += cnt[j];
            cnt[ pos[i] ]++;
        }
//        for(int i=0; i<m; i++) {
//            for(int j=0; j<m; j++) if(i != j) {
//                cout << i << ' ' << j << ' ' << prep[i][j] << endl;
//            }
//        }


        printf("Case %d: %lld\n", t, getMin(0));
    }

    return 0;
}

