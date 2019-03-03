#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000
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

int n,m;
char grid[22][22];
int matchR[22][22],matchC[22][22], vis[22][22];

bool findMatch(int ur, int uc) {

    for(int i=0; i<4; i++) {
        int vr = ur + dirR[i] , vc = uc + dirC[i];
        if(vr < 0 || vr == m || vc < 0 || vc == n || grid[vr][vc] != '*') continue;
        if(!vis[vr][vc]) {
            vis[vr][vc] = 1;
            if(matchR[vr][vc] == -1 || matchC[vr][vc] == -1 || findMatch(matchR[vr][vc], matchC[vr][vc])) {
                matchR[vr][vc] = ur; matchC[vr][vc] = uc;
                matchR[ur][uc] = vr; matchC[ur][uc] = vc;

                return true;
            }
        }
    }
    return false;
}

int bpm() {
    memset(matchR, -1, sizeof(matchR));
    memset(matchC, -1, sizeof(matchC));
    int ans = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == '*' && matchR[i][j] == -1 && matchC[i][j] == -1) {
                memset(vis, 0, sizeof(vis));
                findMatch(i,j);
                ans++;
            }
        }

    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &m,&n);
        for(int i=0; i<m; i++) scanf("%s", &grid[i]);
        printf("Case %d: %d\n", t, bpm());
    }
    return 0;
}

