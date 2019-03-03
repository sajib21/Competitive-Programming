#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int setBit(int mask, int p) { return mask | (1 << p); }
int chkBit(int mask, int p) { return mask & (1 << p); }

int n, grid[18][18], dp[18][1<<16];
vi valid[18];
vi nxt[18][1<<16];
int sum[18][1<<16];

bool ok(int a, int b, int n) {
    for(int i=0; i<n; i++) {
        if(chkBit(a, i)) {
            if(i && chkBit(b, i-1)) return false;
            if(chkBit(b, i)) return false;
            if(i<n-1 && chkBit(b, i+1)) return false;
        }
    }
    return true;
}

bool isValid(int lastMask, int n) {
    for(int i=1; i<n; i++) {
        if(chkBit(lastMask, i-1) && chkBit(lastMask, i)) return false;
    }
    return true;
}

int f(int r, int mask) {
//    cout << "IN " << r << ' ' << mask << endl; getchar();
    if(r == n) return 0;
    if(dp[r][mask] != -1) return dp[r][mask];

    int ans = 0;

    for(int i=0; i<nxt[n][mask].size(); i++) {
        int nxtMask = nxt[n][mask][i];
//        if(r == 2 && mask == 0) {
//            cout << "TEST " << sum[r][mask] << endl; getchar();
//        }
        ans = max(ans, sum[r][nxtMask]+f(r+1,nxtMask));
    }
//    cout << "OUT " << r << ' ' << mask << ' ' << ans << endl; getchar();
    return dp[r][mask] = ans;
}


int main() {
    for(int i=1; i<=16; i++) {
        for(int mask=0; mask<(1<<i); mask++) {
            if(isValid(mask, i)) valid[i].pb(mask);
        }
    }

    for(int sz=1; sz<=16; sz++) {
        for(int i=0; i<valid[sz].size(); i++) {
            int p = valid[sz][i];
//            assert(p < 2500);
            for(int j=i; j<valid[sz].size(); j++) {
                int q = valid[sz][j];
//                assert(q < 2500);
                if(ok(p, q, sz)) {
                    nxt[sz][p].pb(q); nxt[sz][q].pb(p);
                }
            }
        }
    }

//    for(int i=0; i<(1<<3); i++) {
//        cout << i << " : ";
//        for(int j=0; j<nxt[3][i].size(); j++) cout << nxt[3][i][j] << ' ';
//        cout << endl;
//    }

    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) scanf("%d", &grid[i][j]);
        }

        memset(sum, 0, sizeof sum);
        for(int i=0; i<n; i++) {
            for(int p=0; p<valid[n].size(); p++) {
                int mask = valid[n][p];
                for(int j=0; j<n; j++)
                    if(chkBit(mask, j)) sum[i][mask] += grid[i][j];
//                cout << i << ' ' << mask << ' ' << sum[i][mask] << endl;
            }
        }

        memset(dp, -1, sizeof dp);
        printf("%d\n", f(0,0));
    }
}
