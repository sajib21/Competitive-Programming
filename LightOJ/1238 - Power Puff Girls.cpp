#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};

int m,n;
char grid[22][22];

int bfs(char grid[22][22], pii st) {
    int dis[22][22];
    memset(dis, -1, sizeof(dis));
    dis[st.first][st.second ] = 0;
    queue<pii>q;
    q.push(st);

    while(!q.empty()) {
        pii nd = q.front();
        q.pop();

        int r = nd.first , c = nd.second;
//        cout << "NOW " << r << ' ' << c << endl;
//        if(r < 0 || )
        if(grid[r][c] == 'h') {
//            cout << "ANS " << r << ' ' << c << ' ' << dis[r][c] << endl;
            return dis[r][c];
        }

//        cout << "BUG" << endl;

        if(grid[r][c] == '#' || grid[r][c] == 'm') {
//            cout << grid[r][c] << endl;
            continue;
        }

//        cout << "BUG " << endl;
        for(int i=0; i<4; i++) {
            int nr = r + dirR[i] , nc = c + dirC[i];
            if( r < 0 || r >= m || c < 0 || c >= n) continue;
//            cout << "NEW " << nr << ' ' << nc << endl;
            if( (grid[nr][nc] == '.' || grid[nr][nc] == 'h') && dis[nr][nc] == -1) {
                dis[nr][nc] = dis[r][c] + 1;
                q.push(pii(nr, nc));
            }
        }
    }
    return 0;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &m,&n);
        for(int i=0; i<m; i++) scanf("%s", grid[i]);
        pii st;
        char temp[22][22];
        int a,b,c;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 'a') {
                    st = pii(i,j);
                    break;
                }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                temp[i][j] = grid[i][j];
                if(grid[i][j] == 'b' || grid[i][j] == 'c') temp[i][j] = '.';
            }
        }
//        cout << "CALLING " << st.first << ' ' << st.second << endl;
        a = bfs(temp, st);

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 'b') {
                    st = pii(i,j);
                    break;
                }

//        char temp[22][22];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                temp[i][j] = grid[i][j];
                if(grid[i][j] == 'a' || grid[i][j] == 'c') temp[i][j] = '.';
            }
        }
        b = bfs(temp, st);

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 'c') {
                    st = pii(i,j);
                    break;
                }

//        char temp[22][22];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                temp[i][j] = grid[i][j];
                if(grid[i][j] == 'b' || grid[i][j] == 'a') temp[i][j] = '.';
            }
        }
        c = bfs(temp, st);

//        cout << a << ' ' << b << ' ' << c <<endl;
        printf("Case %d: %d\n",t, max(a, max(b,c)));
    }
    return 0;
}
