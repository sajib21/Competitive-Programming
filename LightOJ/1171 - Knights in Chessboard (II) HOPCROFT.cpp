#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 500000
#define MOD 1000000007
#define MAX 40000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int dirR[] = {+1, +2, +2, +1, -1, -2, -2, -1} ;
int dirC[] = {+2, +1, -1, -2, -2, -1, +1, +2} ;

struct info{
    int x,y;
    info() {}
    info(int xx, int yy) {
        x = xx; y = yy;
    }
};

int m,n,k,x, blk[205][205];

info match[205][205] ;
int visl[205][205] , visr[205][205] ;

bool bfs() {
    int dis = INT_MAX;
    memset(visl, -1, sizeof(visl));
    memset(visr, -1, sizeof(visr));
    queue<info>q;


    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(!blk[i][j] && !match[i][j].x) {
                visl[i][j] = 0;
                q.push(info(i,j));
            }
        }

    }

    while(!q.empty()) {
        info u = q.front();
        int ur = u.x , uc = u.y;
        q.pop();

        if(visl[ur][uc] > dis) break;

//        cout << u << ' ' << visl[u] << endl;

        for(int i=0; i<8; i++) {
            int vr = ur+dirR[i] , vc = uc+dirC[i];
            if(vr<1 || vr>m || vc<1 || vc>n || blk[vr][vc] ) continue;

            if(visr[vr][vc] == -1) {
                visr[vr][vc] = visl[ur][uc] + 1;
                if(!match[vr][vc].x) dis = visr[vr][vc];
                else {
                    int wr = match[vr][vc].x , wc = match[vr][vc].y;
                    visl[wr][wc] = visr[vr][vc] + 1;
                    q.push(info(wr,wc));
                }
            }
        }
    }
//    cout << "RETURN BFS " << (dis != INT_MAX) << endl;;
    return dis != INT_MAX;
}

bool findMatch(info u) {
    int ur = u.x , uc = u.y;

    for(int i=0; i<8; i++) {
        int vr = ur+dirR[i] , vc = uc+dirC[i];
        if(vr<1 || vr>m || vc<1 || vc>n || blk[vr][vc] ) continue;
        if(visr[vr][vc] == visl[ur][uc]+1) {
            visr[vr][vc] = 0;
            if(!match[vr][vc].x || findMatch(match[vr][vc])) {
                match[vr][vc] = u;
                match[ur][uc] = info(vr,vc);
//                cout << "MATCH OF " << u << " IS " << v << endl;
////                cout << "MATCH OF " << num[u] << " IS " << num[v] << endl;
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    memset(match, 0, sizeof(match));
//    memset(vis, -1, sizeof(vis));
    int ans = 0;
    while(bfs()) {
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(!blk[i][j] && !match[i][j].x && findMatch(info(i,j))) {
        //            cout << "TRY " << i << endl;
                    ans++;
                }
            }
        }
    }

//    cout << " BPM " << ans << endl;
    return ans;
}


int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d", &m,&n,&k);
        memset(blk, 0, sizeof(blk));
        for(int i=0; i<k; i++) {
            int r,c;
            scanf("%d %d", &r,&c);
            blk[r][c] = 1;
        }
        printf("Case %d: %d\n", t, m*n - k - bpm());
//        for(int i=1; i<=m; i++) for(int j=1; j<=n; j++) cout << i << ' ' << j << " : " << match[i][j].x << ' ' << match[i][j].y << endl;
    }
    return 0;
}
