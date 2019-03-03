#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 5005

using namespace std;

int m,n;
char grid[110][110];
int row[110][110], col[110][110], r,c;
vi g[LIM];
int vis[2*LIM], match[2*LIM];

bool findMatch(int u) {
//    cout << "IN " << u << endl; getchar();
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        vis[v] = 1;
        if(match[v] == -1 || findMatch(match[v])) {
            match[v] = u; match[u] = v;
//            cout << "MATCH " << u << ' ' << v-r << endl; getchar();
            return true;
        }
    }
    return false;
}

int bpm() {
    memset(match, -1, sizeof match);
    int ans = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == '.') {
                int p = row[i][j], q = col[i][j];
                if(match[p] != -1) continue;
                memset(vis, 0, sizeof vis);
//                cout << "MATCHING " << p << endl;
                if(findMatch(p)) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main() {
//    freopen("1304i.txt", "r", stdin);
//    freopen("1304o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &m,&n);
        memset(g, NULL, sizeof g);
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);

        for(int i=0; i<m; i++) scanf("%s", grid[i]);

        r=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != 'W') {
                    if(!j || grid[i][j-1] == 'W') row[i][j] = ++r;
                    else row[i][j] = r;
                }
            }
        }
        c=0;
        for(int j=0; j<n; j++) {
            for(int i=0; i<m; i++) {
                if(!i || grid[i-1][j] == 'W') col[i][j] = ++c;
                else col[i][j] = c;
            }
        }
//        cout << "ROW " << endl;
//        for(int i=0; i<m; i++) {
//            for(int j=0; j<n; j++) cout << row[i][j] << ' ';
//            cout << endl;
//        }
//        cout << "COL " << endl;
//        for(int i=0; i<m; i++) {
//            for(int j=0; j<n; j++) cout << col[i][j] << ' ';
//            cout << endl;
//        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) if(grid[i][j] == '.') {
                g[ row[i][j] ].pb( r+col[i][j] );
//                cout << "EDGE " << row[i][j] << ' ' << col[i][j] << endl;
            }
        }
        printf("Case %d: %d\n", t, bpm());
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '.' && match[ r+col[i][j] ] == row[i][j])
                    printf("T");
                else printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }
}
