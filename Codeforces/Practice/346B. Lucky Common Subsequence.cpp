///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

struct info{
    int x,y,z, p,q,r;
    info() {x = y = z = p = q = r =  0;}
    info(int xx, int yy = 0, int zz = 0, int pp = 0, int qq = 0, int rr = 0) {
        x = xx; y = yy; z = zz; p = pp; q = qq; r = rr;
    }
};

string text, pattern;
int sizeText, sizePattern;
int prefix[110];
vector<int>results;

void generatePrefix() {
    prefix[0] = 0;
    for(int i = 0, j = 2; j<sizePattern; j++) {
        while(i > 0 && pattern[i+1] != pattern[j]) i = prefix[i];
        if(pattern[i+1] == pattern[j]) i = i+1;
        prefix[j] = i;
    }
}

string a,b;
int  dp[110][110][110];
info dr[110][110][110];

int f(int r, int c, int in) {
//    cout << r << ' ' << c << ' ' << in << endl; getchar();
    if(in == sizePattern) return dp[r][c][in] = INT_MIN;
    if(r == a.size() || c == b.size()) return dp[r][c][in] = 0;
    if(dp[r][c][in] != -1) return dp[r][c][in];

    int ans = 0, temp;
    info drr;
    int nn = in;
    if(a[r] == b[c]) {
        while(prefix[nn-1] && pattern[nn] != a[r]) nn = prefix[nn-1] + 1;
        if(pattern[nn] != a[r]) nn = 1;
        if(pattern[nn] != a[r]) nn = 0;
        temp = 1 + f(r+1,c+1, nn+1);
        if(temp > ans && nn+1 != sizePattern) {
            ans = temp;
            drr = info(r+1,c+1,nn+1, 1);
        }
    }
    temp = f(r+1,c,in);
    if(temp > ans) {
        ans = temp;
        drr = info(r+1,c,in, 0);
    }
    temp = f(r,c+1,in);
    if(temp > ans) {
        ans = temp;
        drr = info(r,c+1,in, 0);
    }
    dr[r][c][in] = drr;
    return dp[r][c][in] = ans;
}

void print(int r, int c, int in) {
    info dir = dr[r][c][in];
//    if(1 || r < 0 || c < 0 || in < 0 || 1) {cout << "NOW " << r << ' ' << c << ' ' << in << ' ' << dir.z << endl; getchar(); }
    if(r == a.size() || c == b.size() || dp[r][c][in] == 0 || dp[r][c][in] == INT_MIN) {
        printf("\n");
        exit(0);
    }

    if(a[r] == b[c] && dir.p) printf("%c", a[r]);
//    cout << "NXT " << dir.x << ' ' << dir.y << ' ' << dir.z << ' ' << endl;
//    getchar();
    print(dir.x , dir.y, dir.z);
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    cin >> a >> b >> pattern;
    pattern = "0" + pattern;
    sizePattern = pattern.size();
    generatePrefix();

    memset(dp, -1, sizeof dp);
    memset(dr, -1, sizeof dr);

    f(0,0, 1);
    if(!dp[0][0][1]) cout << dp[0][0][1] << endl;
    else print(0,0,1);

    return 0;
}
