#include<bits/stdc++.h>

using namespace std;

int grid[10][10];

int bfs(int ri, int ci, int rd, int cd) {
    queue < pair<int,int> > q;
    q.push(pair <int,int> (ri, ci));

    while(!q.empty()) {

        pair <int,int> top = q.front(); q.pop();
        int row = top.first , column = top.second;

        if(row== rd && column==cd) {

            return grid[row][column];
        }

        if(row>2 && column<8 && grid[row-2][column+1] == -1) {
            grid[row-2][column+1] = grid[row][column]+1;
            q.push(pair<int,int> (row-2, column+1));
        }
        if(row>1 && column<7 && grid[row-1][column+2] == -1) {
            grid[row-1][column+2] = grid[row][column]+1;
            q.push(pair<int,int> (row-1, column+2));
        }
        if(row<8 && column<7 && grid[row+1][column+2] == -1) {
            grid[row+1][column+2] = grid[row][column]+1;
            q.push(pair<int,int> (row+1, column+2));
        }
        if(row<7 && column<8 && grid[row+2][column+1] == -1) {
            grid[row+2][column+1] = grid[row][column]+1;
            q.push(pair<int,int> (row+2, column+1));
        }
        if(row>2 && column>1 && grid[row-2][column-1] == -1) {
            grid[row-2][column-1] = grid[row][column]+1;
            q.push(pair<int,int> (row-2, column-1));
        }
        if(row>1 && column>2 && grid[row-1][column-2] == -1) {
            grid[row-1][column-2] = grid[row][column]+1;
            q.push(pair<int,int> (row-1, column-2));
        }
        if(row<8 && column>2 && grid[row+1][column-2] == -1) {
            grid[row+1][column-2] = grid[row][column]+1;
            q.push(pair<int,int> (row+1, column-2));
        }
        if(row<7 && column>1 && grid[row+2][column-1] == -1) {
            grid[row+2][column-1] = grid[row][column]+1;
            q.push(pair<int,int> (row+2, column-1));
        }
    }
}

int main() {
    char s1[5], s2[5];

    while(scanf("%s %s", s1,s2) != EOF) {
        int ci = s1[0]-'a' + 1 , cd = s2[0]-'a' + 1;
        int ri = s1[1]-'0' , rd = s2[1]-'0';

        //printf("%d %d %d %d\n", ri,ci, rd,cd);

        memset(grid, -1, sizeof(grid));
        grid[ri][ci] = 0;

        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, bfs(ri, ci, rd, cd));

    }

    return 0;
}

