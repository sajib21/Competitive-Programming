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

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

struct info{
    ll z,o,t;
    info() {}
    info(ll zz, ll oo, ll tt) {
        z = zz; o = oo; t = tt;
    }
    info operator + (const info &b) const {
        return info(z+b.z , o+b.o, t+b.t);
    }
};

int n,target, grid[16][16];
info dp[1 << 15];

info getCnt(int row, int mask) {
    if(row == n) return info(0,1,0);
    if(dp[mask].o != -1) return dp[mask];

    info ans = info(0,0,0), temp;
    for(int col=0; col<n; col++) if(!chkBit(mask, col)) {
        temp = getCnt(row+1, setBit(mask, col));
        if(grid[row][col] == 0) {
            ans.z += temp.z + temp.o;
            ans.t += temp.t ;
        }
        else if(grid[row][col] == 1) ans = ans + temp;
        else ans.t += temp.z + temp.o + temp.t;
//        cout << "IT " << row << ' ' << col << ' ' << mask << ' ' << temp.z << ' ' << temp.o << ' ' << temp.t << endl;
    }
//    cout << "RET " << row << ' ' << mask << ' ' << ans.z << ' ' << ans.o << ' ' << ans.t << endl;
    return dp[mask] = ans;
}

int main() {

//    freopen("1327i.txt", "r", stdin);
//    freopen("1327o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &grid[i][j]);
//        for(int i=0; i<n; i++) for(int j=0; j<n; j++) printf("%d", grid[i][j]);


        target = (1 << n) - 1;
        info ans = getCnt(0, 0);
        printf("Case %d: %lld\n", t, ans.o + ans.t);
    }

    return 0;
}
