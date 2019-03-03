#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};


struct pnt{
    int x,y;
    pnt() {}
    pnt(int xx, int yy) {
        x = xx; y = yy;
    }
};

int m,n, q;
char grid[505][505];
int comp[505][505], cmp;
int cnt[250050];

int bfs(int r, int c) {
    cmp++;
    queue<pnt>q;
    comp[r][c] = cmp;
    if(grid[r][c] == 'C') cnt[ comp[r][c] ]++;
    grid[r][c] = '#';
    q.push(pnt(r,c));

    while(!q.empty()) {
        pnt nd = q.front();
        q.pop();
        int rr = nd.x , cc =nd.y;

        for(int i=0; i<4; i++) {
            int tr = rr + dirR[i] , tc = cc + dirC[i];
            if(tr < 0 || tr >= m || tc < 0 || tc >= n) continue;
            if(grid[tr][tc] != '#') {
                comp[tr][tc] = cmp;
                if(grid[tr][tc] == 'C') cnt[ comp[tr][tc] ]++;
                grid[tr][tc] = '#';
                q.push(pnt(tr,tc));
            }
        }
    }
}

int main() {
//    freopen("1337o.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        cmp=0;
        memset(comp, 0, sizeof(comp));
        memset(cnt, 0, sizeof cnt);
        scanf("%d %d %d", &m,&n, &q);
        for(int i=0; i<m; i++) scanf("%s", grid[i]);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != '#') {
//                    cout << i << ' ' << j << endl;
                    bfs(i,j);

//                    cout << cmp << endl;
                }
            }
        }

//        for(int i=0; i<m; i++) printf("%s\n", grid[i]);

//        for(int i=1; i<=cmp; i++) cout << i << ' ' << cnt[i] << endl;

        printf("Case %d:\n", t);
        while(q--) {
            int r,c;
            scanf("%d %d", &r,&c); r--; c--;
//            cout << "ANS " << comp[r][c] << ' ' << cnt[ comp[r][c] ] << endl;
            printf("%d\n", cnt[ comp[r][c] ]);
        }
    }
    return 0;
}
