#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int setBit(int n, int pos) { return n | (1 << pos) ;}
int checkBit(int n, int pos) { return n & (1 << pos) ; }

int n;
char grid[10][10];

int chk(int lr, int lc) {
    if(grid[lr][0] != '.' && grid[lr][0] == grid[lr][1] && grid[lr][1] == grid[lr][2] && grid[lr][2] == grid[lr][3]) return 1;
    if(grid[0][lc] != '.' && grid[0][lc] == grid[1][lc] && grid[1][lc] == grid[2][lc] && grid[2][lc] == grid[3][lc]) return 1;
    if(grid[0][0] != '.' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] == grid[3][3]) return 1;
    if(grid[0][3] != '.' && grid[0][3] == grid[1][2] && grid[1][2] == grid[2][1] && grid[2][1] == grid[3][0]) return 1;
    return 0;
}

pii f(int p) {

    char player;
    if(p == 0) player = 'x';
    else player = 'o';
//    int r=-1,c=-1;
    bool ans = false;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(grid[i][j] == '.') {
                grid[i][j] = player;
                if(chk(i,j) == 1) {
                    grid[i][j] = '.';
                    return pii(i,j);
                }
                pii temp = f(!p);
                if(temp.first == -1) {
                    grid[i][j] = '.';
                    return pii(i,j);
                }
                grid[i][j] = '.';
            }
        }
    }
    return pii(-1,-1);
}

int main() {

    char c;
    while( scanf("%c", &c) && c != '$' ) {
        for(int i=0; i<4; i++) scanf("%s", grid[i]);
        pii ans = f(0);
        if(ans.first == -1) printf("#####\n");
        else printf("(%d,%d)\n", ans.first, ans.second);
        getchar();
    }
    return 0;

}
