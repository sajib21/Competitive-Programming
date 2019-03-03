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

int n, g,h;
char grid[27][27];
pnt gp[55], hp[55];
int keys[27][27];

int graphMat[110][110]; //mat[55][55],b[55][55] ;
vii graphVec[110];

int bfs(pnt p) {
    int r = p.x , c = p.y;
    memset(keys, -1, sizeof(keys));
//    memset(bpm, 0, sizeof(bpm));
    keys[r][c] = 0;
//    bpm[r][c] = 0;
    queue<pnt>q;
    q.push(p);

    while(!q.empty()) {
        pnt nd = q.front();
        q.pop();
        int r = nd.x , c = nd.y;
        for(int i=0; i<4; i++) {
            int rr = r + dirR[i] , cc = c + dirC[i];
            if(rr < 0 || rr == n || cc < 0 || cc == n || grid[rr][cc] == '#' || keys[rr][cc] != -1) continue;
            keys[rr][cc] = keys[r][c] + 1;
//            bpm[rr][cc] = 1;
            q.push(pnt(rr,cc));
        }
    }
}

int match[110], vis[110];
bool findMatch(int u, int cost) {

    int sz = graphVec[u].size();
    for(int i=0; i<sz; i++) {
        int v = graphVec[u][i];
        if(graphMat[u][v] > cost) continue;
        if(!vis[v]) {
            vis[v] = 1;
            if((match[v] == 0 || findMatch(match[v], cost)) ) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

bool bpm(int estim) {
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for(int i=1; i<=g; i++) {
        memset(vis, 0, sizeof(vis));
        if(findMatch(i, estim)) cnt++;
//        cout << "GOT " << i << ' ' << cnt << endl;
    }
//    cout << "FOUND " << cnt << endl;
    return cnt == h ;
}

int BS() {
    if(!bpm(10000)) return -1;
//    getchar(); getchar();

    int lo = 1 , hi = 1000, md;
//    cout << "IN BS" << endl;
    bool br = false;
    while(lo < hi) {
        md = (lo+hi) / 2;
        bool t = bpm(md);
//        cout << "BS " << lo << ' ' << md << ' ' << hi << ' ' << t << endl;
        if(t) hi = md;
        else lo = md;

        if(lo+1 == hi) {
            if(br) break;
            br = true;
        }
    }
    return hi;
}

int main() {

//    freopen("1150i.txt", "r", stdin);
//    freopen("1150o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        memset(graphMat, 0, sizeof(graphMat));

        for(int i=0; i<110; i++) graphVec[i].clear();

        g = 0 ; h = 0;
        for(int i=0; i<n; i++) scanf("%s", grid[i]);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 'G') gp[++g] = pnt(i,j);
                else if(grid[i][j] == 'H') hp[++h] = pnt(i,j);
            }
        }
        for(int i=1; i<=g; i++) {
            bfs(gp[i]);
            for(int j=1; j<=h; j++) {
                int r = hp[j].x , c = hp[j].y;
                if(keys[r][c] > 0) graphMat[i][g+j] = keys[r][c];
            }
        }
        for(int i=1; i<=g; i++) {
            for(int j=g+1; j<=g+h; j++) {
                if(graphMat[i][j]) graphVec[i].pb(j);
            }
        }

//        cout << g << ' ' << h << endl;
//        cout << "MAT" << endl;
//        for(int i=1; i<=g; i++) {
//            for(int j=g+1; j<=g+h; j++) {
//                printf("%3d", graphMat[i][j]);
//            }
//            cout << endl;
//        }
//        cout << endl;
//        cout << "GRAPH" << endl;
//        for(int i=0; i<=g+h+1; i++) {
//            cout << i << endl;
//            for(int j=0; j<graphVec[i].size(); j++) {
//                cout << graphVec[i][j] << ' ' ;
//            }
//            cout << endl;
//        }

//        for(int x=0; x<10; x++) bpm(500) ;

        int ans = BS();
        if(ans == -1) printf("Case %d: Vuter Dol Kupokat\n", t);
        else printf("Case %d: %d\n", t, 2*ans+2);
    }
    return 0;
}

