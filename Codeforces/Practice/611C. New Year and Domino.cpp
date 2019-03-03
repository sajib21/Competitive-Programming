#include<bits/stdc++.h>
#define LIM 500

using namespace std;

int h,w,q, grid[LIM+10][LIM+10];
int rowWise[LIM+10][LIM+10], colWise[LIM+10][LIM+10];
int row[LIM+10][LIM+10],col[LIM+10][LIM+10];

int main() {

    char c;
    cin >> h >> w;
    getchar();

    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            scanf("%c", &c);
            if(c == '.') grid[i][j] = 1;
        }
        getchar();
    }

    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            if(grid[i][j-1] && grid[i][j]) rowWise[i][j] = 1, row[i][j]=1;
            rowWise[i][j] += rowWise[i][j-1] + rowWise[i-1][j] - rowWise[i-1][j-1];
            row[i][j] += row[i-1][j];
            if(grid[i-1][j] && grid[i][j]) colWise[i][j] = 1, col[i][j]=1;
            colWise[i][j] += colWise[i-1][j] + colWise[i][j-1] - colWise[i-1][j-1];
            col[i][j] += col[i][j-1];
        }
    }

    cin >> q;
    while(q--) {
        int r1,c1,r2,c2;
        scanf("%d %d %d %d", &r1,&c1,&r2,&c2);
        printf("%d\n", (rowWise[r2][c2]-rowWise[r2][c1-1]-rowWise[r1-1][c2]+rowWise[r1-1][c1-1]) + (colWise[r2][c2]-colWise[r2][c1-1]-colWise[r1-1][c2]+colWise[r1-1][c1-1]) - (row[r2][c1]-row[r1-1][c1]) - (col[r1][c2]-col[r1][c1-1]) );
    }

    return 0;
}
