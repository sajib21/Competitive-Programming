#include<bits/stdc++.h>
#define LIM 1003

using namespace std;

int dR[] = {-1,  0,  0, +1};
int dC[] = { 0, -1, +1,  0};

bool chk(char a, char b) {
return (a == 'D' && b == 'I') || (a == 'I' && b == 'M') ||
       (a == 'M' && b == 'A') || (a == 'A' && b == 'D');
}

int n,m;
char grid[LIM][LIM];
int vis[LIM][LIM], keys[LIM][LIM];

int dfs(int ur, int uc) {
//    cout << ur << ' ' << uc << endl; getchar();
    vis[ur][uc] = 1;
    keys[ur][uc] = 1;
    for(int i=0; i<4; i++) {
        int vr = ur+dR[i];
        int vc = uc+dC[i];
        if(vr < 0 || vr >= n || vc < 0 || vc >= m || !chk(grid[ur][uc], grid[vr][vc])) continue;
        if(vis[vr][vc] == 1) {
            cout << "Poor Inna!" << endl;
            exit(0);
        }
        if(vis[vr][vc] == 2) keys[ur][uc] = max(keys[ur][uc], 1+keys[vr][vc]);
        else                 keys[ur][uc] = max(keys[ur][uc], 1+dfs(vr,vc));
    }
    vis[ur][uc] = 2;
    return keys[ur][uc];
}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++) scanf("%s", grid[i]);

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 'D' && !vis[i][j]) {
                ans = max(ans, dfs(i,j));
            }
        }
    }
    ans = ans/4;
    if(!ans) cout << "Poor Dima!" << endl;
    else cout << ans << endl;
}
