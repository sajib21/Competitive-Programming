#include<bits/stdc++.h>

using namespace std;

int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};

int m,n;
char grid[55][55], res[55][55];

void dfs(int r, int c, char p) {

    if(r < 0 || r > m+1 || c < 0 || c > n+1) return;
//    cout << "ONE " << r << ' ' << c << ' ' << p << endl;
    res[r][c] = '.';

    for(int i=0; i<4; i++) {
        int nr = r + dirR[i] , nc = c + dirC[i];
        if(grid[nr][nc] != p && !res[nr][nc]) dfs(nr, nc, p);
    }

}

void dfs2(int r, int c, char p) {

    res[r][c] = p;
    grid[r][c] = p;

    for(int i=0; i<4; i++) {
        int nr = r + dirR[i] , nc = c + dirC[i];
        if(!res[nr][nc]) dfs2(nr, nc, p);
    }
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(res, 0, sizeof(res));
        scanf("%d %d", &m,&n);

        for(int i=0; i<=n+1; i++) grid[0][i] = grid[m+1][i] = '.';
        for(int i=0; i<=m+1; i++) grid[i][0] = grid[i][n+1] = '.';

//        getchar();
        for(int i=1; i<=m; i++) {
            getchar();
            for(int j=1; j<=n; j++) {
                scanf("%c", &grid[i][j]);
            }
//            getchar();
        }

        dfs(0,0, '.');
        for(int i=0; i<=m+1; i++) {
            for(int j=0; j<=n+1; j++) {
                if(grid[i][j] != '.') {
                    memset(res, 0, sizeof(res));
                    dfs(0,0, grid[i][j]);
                    dfs2(i, j, grid[i][j] );
                }
            }
        }

        printf("Case %d:\n", t);
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
