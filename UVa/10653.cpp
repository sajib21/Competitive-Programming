#include <bits/stdc++.h>

using namespace std;

int r,c, grid[1010][1010];

int bfs(int xi, int yi, int xd, int yd, int prev_level) {

    queue< pair<int,int> > q;
    grid[xi][yi] = 1;
    q.push(pair<int,int>(xi,yi));

    while(!q.empty()) {
        pair<int,int> top = q.front(); q.pop();
        int x=top.first ,y=top.second;

        if(x==xd && y==yd) {
            return grid[x][y];
        }

        if(y>0 && !grid[x][y-1]) {
            grid[x][y-1] = grid[x][y] + 1;
            q.push(pair<int,int> (x, y-1));
        }
        if(x>0 && !grid[x-1][y]) {
            grid[x-1][y] = grid[x][y] + 1;
            q.push(pair<int,int> (x-1, y));
        }
        if(y<c-1 && !grid[x][y+1]) {
            grid[x][y+1] = grid[x][y] + 1;
            q.push(pair<int,int> (x, y+1));
        }
        if(x<r-1 && !grid[x+1][y]) {
            grid[x+1][y] = grid[x][y] + 1;
            q.push(pair<int,int> (x+1, y));
        }


    }

}

int main() {

    while (scanf("%d %d", &r, &c) && r && c) {
        memset(grid, 0, sizeof(grid));
        int bombRow;
        scanf("%d", &bombRow);
        for(int i=0; i<bombRow; i++) {
            int row, column, bomb;
            scanf("%d %d", &row, &bomb);
            while(bomb--) {
                scanf("%d", &column);
                grid[row][column] = -1;
            }
        }
        int xi,yi, xd,yd;
        scanf("%d %d %d %d", &xi, &yi, &xd, &yd);


        printf("%d\n", bfs(xi,yi, xd,yd, 0) - 1);

    }

    return 0;
}

