#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};

struct rc {
    int r, c, tim;
    rc() {}
    rc(int rr, int cc, int t) {
        r = rr;
        c = cc;
        tim = t;
    }
};

int n;
char mxx='A';
char grid[14][14];
rc pos[27];
bool vis[14][14];
queue<rc>q;

int bfs(char st, char ed) {

    memset(vis, 0, sizeof(vis));


    int rtr = pos[st-'A'].r , rtc = pos[st-'A'].c;
    vis[rtr][rtc] = 1;


    q.push(rc(rtr, rtc, 0));

    while(!q.empty()) {

        rc u = q.front();
        q.pop();
        int ur = u.r , uc = u.c, ut = u.tim;

        if(grid[ur][uc] == ed) {
            while(!q.empty()) q.pop();
            return ut;
        }

        for(int d=0; d<4; d++) {
            char nw = grid[ ur+dirR[d] ][ uc+dirC[d] ];
            if( ( (nw >= 'A' && nw <= ed) || nw == '.') && !vis[ ur+dirR[d] ][ uc+dirC[d] ] ) {
                vis[ ur+dirR[d] ][ uc+dirC[d] ] =  1;
                q.push(rc(ur+dirR[d] , uc+dirC[d], ut+1));
            }
        }
    }
    return -1;
}

int main() {

//    cout << (int) '.' << " " << (int) '#' << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(pos, 0, sizeof(pos));

        mxx = 0;
        scanf("%d", &n); getchar();
        for(int i=0; i<=n+1; i++) grid[0][i] = grid[n+1][i] = grid[i][0] = grid[i][n+1] = '#' ;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) scanf("%c", &grid[i][j]);
            getchar();
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                    mxx = max(mxx, grid[i][j]);
                    pos[ grid[i][j] - 'A' ] = rc(i,j, 0);
                }
            }
        }

//        cout << "MAX " << mxx << endl;

        int ans = 0;
        char pre = 'A';
        for(char c='B'; c<=mxx; c++) {
            int temp = bfs(pre, c);
            if(temp == -1) {
                ans = -1;
                break;
            }
            ans += temp;
            pre = c;
        }
        if(ans == -1) printf("Case %d: Impossible\n", t);
        else printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
