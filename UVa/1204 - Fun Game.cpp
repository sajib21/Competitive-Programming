#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; }
int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

int n, target, sum;
string seq[18];
vector<string> pure;
int dp[36][1 << 18];
int dr[36][1 << 18];

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

int getPrefix(string str) {
    cout << str << ' ' << str.size() << endl;
    int ans = 0;
    for(int i=1; i<str.size(); i++) {
        int j,k;
        for(j=0,k=i; k<str.size(); k++, j++) if(str[j] != str[k]) break;
//        cout << i << ' ' << k << endl;
        if(k == str.size()) {
            ans = max(ans, (int)(str.size()-i) );
        }
    }
    return str.size() - ans;
}

int f(int last, int mask) {
    if(mask == target) return 0;
    if(dp[last][mask] != -1) return dp[last][mask];
    int ans = -1, dir;
    for(int i=0; i<n; i++) if(!chkBit(mask, (i+1)/2 )) {
        int temp = getSuffix(last, i) + f(i, setBit(mask, (i+1)/2 ) );
        if(temp > ans) {
            ans = temp;
            dir = i;
        }
//        ans = max(ans, getSuffix(last, i) + f(i, setBit(mask, (i+1)/2 ) ) );
    }
    dr[last][mask] = dir;
    return dp[last][mask] = ans;
}

int g(int last, int mask, string temp) {
    if(mask == target) {
        cout << "DONE " << temp << endl;
        return temp.size() - getSuffix(last, dr[0][1]);
    }
    int ans = dp[last][mask];
    int dir = dr[last][mask];

//    cout << "IN " << last << ' ' << mask << ' ' << dir
//        << ' ' << pure[dir] << ' ' << getSuffix(last, dir) << endl; getchar();

    temp += pure[dir].substr( getSuffix(last,dir), pure[dir].size() );
    return g(dir, setBit(mask, (dir+1)/2), temp );
}


int main() {
    while(scanf("%d", &n) && n) {
        for(int i=0; i<n; i++) cin >> seq[i];
        pure.clear();
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

            reverse(seq[i].begin(), seq[i].end());
            for(j=0; j<n; j++) if(i != j) {
                if(seq[j].find(seq[i]) != string::npos) {
                    seq[i] = "";
                    f = false;
                    break;
                }
            }


            if(f) {
                pure.pb(seq[i]);
                reverse(seq[i].begin(), seq[i].end());
                pure.pb(seq[i]);
            }
        }
        n = pure.size();

        memset(dp, -1, sizeof dp);
        memset(dr, -1, sizeof dr);
        memset(ov, -1, sizeof ov);
        target = (1 << ((n+1)/2) ) -1;

        int an = f(0,1);

//        cout << dp[0][1] << ' ' << dr[0][1] << ' ' << n << ' ' << target << endl;

        printf("%d\n", g(0,1, "") );
    }
    return 0;
}
