#include<bits/stdc++.h>

using namespace std;

int n,m,k, dots = 0, ir = -1, ic = -1, lft;
char grid[504][504];

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

void dfs(int r, int c) {

    if(!lft) return;
    grid[r][c] = 's';
    lft--;
    //if(!left) return;

    for(int i=0; i<4; i++) {
        int nr = r+dr[i], nc = c+dc[i];
        if(grid[nr][nc] == '.') {
            dfs(nr,nc);
        }
        if(lft <= 0) return;
    }
}

int main() {

    scanf("%d %d %d", &n,&m,&k);
    getchar();

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%c", &grid[i][j]);
            if(grid[i][j] == '.') {
                if(ir == -1) ir = i, ic = j;
                dots++;
            }
        }
        getchar();
    }

//    cout << dots << ' ' << k << endl;
//    cout << ir << ' ' << ic << endl;
    lft = dots-k;
    dfs(ir,ic);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(grid[i][j] == 's') printf(".");
            else if(grid[i][j] == '#') printf("#");
            else printf("X");
        }
        printf("\n");
    }
}
