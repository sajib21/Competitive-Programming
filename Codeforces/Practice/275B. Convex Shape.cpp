#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

int n,m;
char grid[60][60];
int whtr[60][60], whtc[60][60];
//vector<pii>blacks;

int main() {

    cin >> n >> m;
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=m; j++) {
            cin >> grid[i][j];
//            if(grid[i][j] == 'B') blacks.pb(mp(i,j));
        }
    }



    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(grid[i][j] == 'W') {
                whtc[i][j] = 1 + whtc[i-1][j];
                whtr[i][j] = 1 + whtr[i][j-1];
//                blkc[i][j] = blkc[i-1][j];
//                blkr[i][j] = blkr[i][j-1];
            }
            else {
                whtc[i][j] = whtc[i-1][j];
                whtr[i][j] = whtr[i][j-1];
//                blkc[i][j] = 1 + blkc[i-1][j];
//                blkr[i][j] = 1 + blkr[i][j-1];
            }
        }
    }

//    int sz = blacks.size();
//    for(int i=0; i<sz; i++) {
//        for(int j=i+1; j<sz; j++) {
//            pii p = blacks[i], q = blacks[j];
//            if(whtc[p.first][p.second] == whtc[q.first][p.second] && whtr[q.first][p.second] == whtr[q.first][q.second]) continue;
//            if(whtr[p.first][p.second] == whtr[p.first][q.second] && whtc[p.first][q.second] == whtc[q.first][q.second]) continue;
////            cout << p.first << ' ' << p.second << ' ' << q.first << ' ' << q.second << endl;
//            cout << "NO" << endl;
//            return 0;
//        }
//    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(grid[i][j] == 'B') {
                for(int k=1; k<=n; k++) {
                    for(int l=1; l<=m; l++) {
                        if(grid[k][l] == 'B') {
                            if(whtc[i][j] == whtc[k][j] && whtr[k][j] == whtr[k][l]) continue;
                            if(whtr[i][j] == whtr[i][l] && whtc[i][l] == whtc[k][l]) continue;

                            cout << "NO" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }


    cout << "YES" << endl;
    return 0;

}
