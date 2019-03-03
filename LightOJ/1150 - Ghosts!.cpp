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
int keys[27][27], bpm[55][55];

int graphMat[55][55], mat[55][55],b[55][55] ;
vii graphVec[55];

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

struct info{
    int u, k;
    info() {}
    info(int uu, int kk) {
        u = uu; k = kk;
    }
    bool operator < (const info &b) const {
        return k > b.k;
    }
};

int bfsFlow(int root, int estim) {
    int cap = -1;
    int keys[110], par[110], vis[110];
    memset(keys, -1, sizeof(keys));
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    keys[root] = 0;
    priority_queue<info>q;
    q.push(info(root, 0 ));

    while(!q.empty()) {
        info nd = q.top();
        int u = nd.u , k = nd.k;
        q.pop();
        vis[u] = 1;

        if(u == g+h+1) {
            cap = keys[u];
            break;
        }

        int sz = graphVec[u].size();
        for(int i=0; i<sz; i++) {
            int v = graphVec[u][i];
            if(graphMat[u][v] > 0 && v != par[u] ) {
                if(keys[v] == -1 /*&& keys[u] + graphMat[u][v] <= estim*/) {
                    keys[v] = keys[u] + graphMat[u][v];
                    par[v] = u;
                    q.push(info(v, keys[v]));
                }
            }
        }
    }

    if(cap == -1 || cap > estim) return -1;

    int v = g+h+1;
    int u = par[v];
    while(u != -1) {
//        graphMat[u][v] ;

//        cout << "PRE " << u << ' ' << v << " : " << graphMat[u][v] << ' ' << graphMat[v][u] << endl;


        graphMat[v][u] += graphMat[u][v];
        graphMat[u][v] = 0;

//        cout << "PRE " << u << ' ' << v << " : " << graphMat[u][v] << ' ' << graphMat[v][u] << endl;

        u = par[u];
        v = par[v];


        if(v == 0) break;
    }
//    cout << endl;
    return cap;
}

bool flow(int estim) {   ///impossible case baki

    if(estim == 15) cout << "CHECKING FOR " << estim << endl;

    for(int i=0; i<=g+h+1; i++) {
        for(int j=0; j<=g+h+1; j++) {
            graphMat[i][j] = mat[i][j];
            bpm[i][j] = b[i][j];
        }
    }

    int ans = 0;
    int cnt = 0;
    while(true) {
        int temp = bfsFlow(0, estim);
        if(estim == 15) cout << temp << endl;
        if(temp <= 0) break;
        if(ans+temp-2 > estim) continue;
        ans += temp-2;
        cnt++;
        if(estim == 15) cout << temp-2 << ' ' << ans << ' ' << cnt << endl;
    }
    if(cnt == h) return true;
    return false;
}

int flowBS() {
    int lo = 1 , hi = 10000;
    int md;
    int ans = 10000;
    while(lo < hi) {
        md = (lo+hi) / 2;
        bool temp = flow(md);
        cout << md << " : " << temp << endl;
        if(temp) hi = md;
        else lo = md;

        if(lo + 1 == hi) break;
    }
    return hi;
}


int main() {
    int T;
    scanf("%D", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        memset(graphMat, 0, sizeof(graphMat));
        memset(mat, 0, sizeof(mat));
        memset(bpm, 0, sizeof(bpm));
        memset(b, 0, sizeof(b));

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
                if(keys[r][c] > 0) graphMat[i][g+j] = keys[r][c] , bpm[i][g+j] = 1;
            }
        }
        for(int i=1; i<=g; i++) graphMat[0][i] = 1 , bpm[0][i] = 1;
        for(int i=1; i<=h; i++) graphMat[g+i][g+h+1] = 1 , bpm[g+i][g+h+1] = 1;

        for(int i=0; i<=g+h+1; i++) {
            for(int j=0; j<=g+h+1; j++) {
                if(graphMat[i][j]) graphVec[i].pb(j) , graphVec[j].pb(i);
            }
        }

        for(int i=0; i<=g+h+1; i++) {
            for(int j=0; j<=g+h+1; j++) {
                mat[i][j] = graphMat[i][j];
                b[i][j] = bpm[i][j];
            }
        }

//        cout << g << ' ' << h << endl;
//        for(int i=0; i<=g+h+1; i++) {
//            for(int j=0; j<=g+h+1; j++) {
//                printf("%3d", bpm[i][j]);
//            }
//            cout << endl;
//        }
//        cout << endl;
//        for(int i=0; i<=g+h+1; i++) {
//            cout << i << endl;
//            for(int j=0; j<graphVec[i].size(); j++) {
//                cout << graphVec[i][j] << ' ' ;
//            }
//            cout << endl;
//        }

        int ans = flowBS();
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
