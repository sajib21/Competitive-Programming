#include<bits/stdc++.h>
#define LIM 200
#define pb push_back
#define pii pair<int,int>

using namespace std;

struct info {
    int r, c, moves;
    char type;
    info() {}
    info(int rr, int cc, char tt, int mm) {
        r = rr; c = cc; type = tt; moves = mm;
    }
};

int dirr[] = {-1, 0, 1, 0};
int dirc[] = {0, 1, 0, -1};

int r,c;
char grid[LIM+10][LIM+10];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int pr,pc;
        queue<info>q;

        scanf("%d %d", &r,&c);
        getchar();
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                scanf("%c", &grid[i][j]);
                if(grid[i][j] == 'J') pr = i, pc = j;
                else if(grid[i][j] == 'F') q.push(info(i,j, 'F', 0));
            }
            getchar();
        }
        q.push(info(pr,pc, 'J', 0));

        int ans = -1;

        while(!q.empty()) {
            info cell = q.front();
            q.pop();
            int ur = cell.r , uc = cell.c, mvs = cell.moves;
            char tp = cell.type;

            if(ur < 0 || ur == r || uc < 0 || uc == c) continue;

            if(tp == 'J') {
                if(ur == 0 || ur == r-1 || uc == 0 || uc == c-1) {
                    ans = mvs;
                    break;
                }
                for(int i=0; i<4; i++) if(grid[ur + dirr[i] ][ uc + dirc[i] ] == '.') {
                    q.push(info(ur+dirr[i], uc+dirc[i], 'J', mvs+1));
                    grid[ur + dirr[i] ][ uc + dirc[i] ] = 'J';
                }
            }
            else {
                for(int i=0; i<4; i++) if(grid[ur + dirr[i] ][ uc + dirc[i] ] == '.' || grid[ur + dirr[i] ][ uc + dirc[i] ] == 'J') {
                    q.push(info(ur+dirr[i], uc+dirc[i], 'F', 0));
                    grid[ur + dirr[i] ][ uc + dirc[i] ] = 'F';
                }
            }
        }
        if(ans == -1) printf("Case %d: IMPOSSIBLE\n", t);
        else printf("Case %d: %d\n", t, ans+1);
    }
    return 0;
}
