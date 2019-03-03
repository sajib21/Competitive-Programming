#include<bits/stdc++.h>
#define LIM 1010

using namespace std;

int n,m, bame[LIM][LIM], dane[LIM][LIM], upre[LIM][LIM], nice[LIM][LIM];
int lagao[LIM][LIM], ver[LIM][LIM], hor[LIM][LIM];
char grid[LIM][LIM];

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%s", grid[i]);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            bame[i][j] = grid[i][j] == '*';
            if(j && bame[i][j]) bame[i][j] += bame[i][j-1];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=m-1; j>=0; j--) {
            dane[i][j] = grid[i][j] == '*';
            if(j<m-1 && dane[i][j]) dane[i][j] += dane[i][j+1];
        }
    }

    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            upre[i][j] = grid[i][j] == '*';
            if(i && upre[i][j]) upre[i][j] += upre[i-1][j];
        }
    }
    for(int j=0; j<m; j++) {
        for(int i=n-1; i>=0; i--) {
            nice[i][j] = grid[i][j] == '*';
            if(i<n-1 && nice[i][j]) nice[i][j] += nice[i+1][j];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int x = min(min(bame[i][j], dane[i][j]), min(upre[i][j], nice[i][j]));
            x--;
            if(x > 0) {
                lagao[i][j] = x;
                ans++;
                ver[i-x][j]++;
                ver[i+x+1][j]--;

                hor[i][j-x]++;
                hor[i][j+x+1]--;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i) ver[i][j] += ver[i-1][j];
            if(j) hor[i][j] += hor[i][j-1];
            int temp = ver[i][j]+hor[i][j];
            if(grid[i][j] == '*' && !temp) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(lagao[i][j]) printf("%d %d %d\n", i+1,j+1, lagao[i][j]);
        }
    }

}
