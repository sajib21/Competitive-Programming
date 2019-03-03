#include<bits/stdc++.h>
#define pii pair<int,int>
#define _it [ r+dirR[mv] ][ c+dirC[mv] ]
using namespace std;

int m,n, grid[12][12], k;
vector<pii>nits;
int lev[105][12][12], mov[105][12][12];

int dirR[] = {+1,+1,+2,+2,-1,-1,-2,-2};
int dirC[] = {-2,+2,-1,+1,-2,+2,-1,+1};

void allBFS() {

    memset(lev, -1, sizeof(lev));

    k = nits.size();
    for(int kn=0; kn<k; kn++) {

        //memset(lev, -1, sizeof(lev));

        pii p = nits[kn];

        queue<pii>q;
        q.push(p);
        lev[kn] [ p.first ][ p.second ] = 0;
        mov[kn] [ p.first ][ p.second ] = 0;

        while(!q.empty()) {
            pii u = q.front(); int r = u.first, c = u.second;
            q.pop();
            for(int mv=0; mv<8; mv++) {
                if(r+dirR[mv] < 0 || r+dirR[mv] >= m || c+dirC[mv] < 0 || c+dirC[mv] >= n ) continue;
                if(lev[kn]_it == -1) {
                    lev[kn]_it = lev[kn] [r][c] + 1;
                    mov[kn]_it = (lev[kn]_it + (grid[p.first][p.second] - '0') - 1) / (grid[p.first][p.second] - '0');
                    q.push(make_pair(r+dirR[mv], c+dirC[mv]));
                }
            }
        }
    }

}

int main(){

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        nits.clear();

        scanf("%d %d", &m, &n); getchar();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                scanf("%c", &grid[i][j]);
                if(grid[i][j] >= '1' && grid[i][j] <= '9') {
                    nits.push_back(make_pair(i,j));
                }
            }
            getchar();
        }
        allBFS();

//        for(int kn = 0; kn<k; kn++) {
//            for(int r=0; r<m; r++) {
//                for(int c=0; c<n; c++) {
//                    cout << lev[kn][r][c];
//                }
//                cout << endl;
//            }
//            cout << endl;
//        }

        int ans = INT_MAX;
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                int temp = 0;
                for(int kn=0; kn<k; kn++) {
                    temp += mov[kn][r][c];
                    if(lev[kn][r][c] == -1) {
                        temp = INT_MAX;
                        break;
                    }
                }
                if(temp < ans) ans = temp;
            }
        }
        if(ans == INT_MAX) printf("Case %d: %d\n", t, -1);
        else printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
