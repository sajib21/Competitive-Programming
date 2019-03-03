/// first remove strings that are fully contained
/// check how much size needs to be added to merge cur string (<=cur.size)

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

using namespace std;

int setBit(int mask, int pos) {
    return mask | (1 << pos) ;
}
int togBit(int mask, int pos) {
    return mask ^ (1 << pos) ;
}
int chkBit(int mask, int pos) {
    return mask & (1 << pos) ;
}

int n, tar, sd;
vector<string> seq, pure;
int dp[16][1 << 16];

int ov[16][16];
int getSuffix( int a, int b) {
    if (a == 0)
        return 0;

    if (ov[a][b] != -1)
        return ov[a][b];

    for (int i = 0; i < pure[a].size(); ++i) {
        bool suffix = true;
        for (int j = 0; j < pure[b].size() && i + j < pure[a].size() && suffix; ++j) {
            if (pure[a][i + j] != pure[b][j]) {
                suffix = false;
            }
        }
        if (suffix) {
            int overlap = pure[a].size() - i;
            return ov[a][b] = overlap;
        }
    }
    return ov[a][b] = 0;
}

int f(int in, int mask) {
    if(mask == tar) return dp[in][mask] = 0;
    if(dp[in][mask] != -1) return dp[in][mask];

    for(int i=1; i<pure.size(); i++) {
        if(!chkBit(mask, i)) {
            int temp = getSuffix(in, i) + f(i, setBit(mask, i));
            if(temp > dp[in][mask]) {
                dp[in][mask] = temp;
            }
        }
    }
    return dp[in][mask];
}

string ans;
void g(int in, int mask, string cs = "") {
    if(cs > ans) return;

    if(mask == tar) {
        ans = min(ans, cs);
        return ;
    }

    for(int i=1; i<pure.size(); i++) {
        int suf = getSuffix(in, i) , tm = setBit(mask, i);
        if(!chkBit(mask, i) && suf+dp[i][tm] == dp[in][mask]) {
//            string temp = cs;
//            for(int p=suf; p<pure[i].size(); p++) temp = temp + pure[i][p];
            g(i, tm, cs+pure[i].substr(suf, pure[i].size()-suf+1));
        }
    }
}

int main() {

//    freopen("1073i.txt", "r", stdin);
//    freopen("1073o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int ttt=1; ttt<=T; ttt++) {
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        memset(ov, -1, sizeof(ov));
        pure.clear();
        seq.clear();
        string s;
        for(int i=0; i<n; i++) {
            cin >> s;
            seq.pb(s);
        }

        pure.pb("");
        for(int i=0; i<n; i++) {
            bool f = true;
            int j;
            for(j=0; j<n; j++) if(i != j) {
                if(seq[j].find(seq[i]) != string::npos) {
                    seq[i] = "";
                    f = false;
                    break;
                }
            }
            if(f) pure.pb(seq[i]);
        }

        tar = (1 << (pure.size()) ) - 1;

        sd = f(0, 1) ;

        ans = "Z";
        g(0, 1);

        printf("Case %d: ", ttt);
        cout << ans << endl;

    }
    return 0;
}
