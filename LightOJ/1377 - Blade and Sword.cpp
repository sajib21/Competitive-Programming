#include    <bits/stdc++.h>
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     10000000
#define     MOD     1000000007
#define     MAX     10000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};

struct info{
    int x,y,z; bool f;
    info() {}
    info(int xx, int yy, int zz = 0, bool ff = 0) {
        x = xx; y = yy; z = zz; f = ff;
    }
};

int n,m, dis[202][202], pr,pc,dr,dc;
char grid[202][202];
vector<info> tel;


int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        memset(dis, -1, sizeof(dis));
        tel.clear();
        for(int i=0; i<n; i++) scanf("%s", &grid[i]);
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
            if(grid[i][j] == 'P') pr = i , pc = j;
            if(grid[i][j] == 'D') dr = i , dc = j;
            if(grid[i][j] == '*') tel.pb(info(i,j));

        }

        queue<info>q;
        q.push(info(pr,pc));
        dis[pr][pc] = 0;

        while(!q.empty()) {
            info nd = q.front(); q.pop();
            int r = nd.x , c = nd.y, w = nd.z;
//            cout << "OUT " << r << ' ' << c << endl;

//            if(grid[r][c] == 'D') break;

            if(grid[r][c] == '*' && nd.f) {
                int sz = tel.size();
                if(sz == 1) {
                    dis[r][c] = 0;
                    continue;
                }
//                cout << "BUG STAR" << endl;
                for(int i=0; i<sz; i++) {
                    int RR = tel[i].x , CC = tel[i].y;
//                    cout << "STAR " << RR << ' ' << CC << endl;
                    if(RR != r || CC != c) {

                        if(dis[RR][CC] == -1) {
                            dis[RR][CC] = 1;
                            q.push(info(RR,CC, w+1));
                        }
                        else if(dis[RR][CC] == 1) {
                            dis[RR][CC] = 0;
                            q.push(info(RR,CC, w+1));
                        }
                    }
                }
            }
            else {
                for(int i=0; i<4; i++) {
                    int R = r + dirR[i] , C = c + dirC[i];
                    if(R < 0 || R == n || C < 0 || C == m || grid[R][C] == '#') continue;
                    if(grid[R][C] == '*' && tel.size() == 1) continue;

                    if(grid[R][C] == '*' && dis[R][C] == -1) {
                        dis[R][C] = 1;
                        q.push(info(R,C, w+3));
                        q.push(info(R,C, w+1, 1));
                    }
                    else if(grid[R][C] == '*' && dis[R][C] == 1) {
                        dis[R][C] = 0;
                        q.push(info(R,C, w+3));
                        q.push(info(R,C, w+1, 1));
                    }

                    else if(dis[R][C] == -1 || w+1 < dis[R][C]) {
                        dis[R][C] = w + 1;
//                        if(grid[R][C] == '*') q.push(info(R,C, dis[R][C]-2, 1));
                        q.push(info(R,C, dis[R][C]));
                    }
                }
            }
        }
        if(dis[dr][dc] == -1) printf("Case %d: impossible\n", t);
        else printf("Case %d: %d\n", t, dis[dr][dc]);

//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) printf("%4d", dis[i][j]);
//            cout << endl;
//        }
    }

    return 0;
}
