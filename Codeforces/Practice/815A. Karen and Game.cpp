#include<bits/stdc++.h>

using namespace std;

int n,m, a[505][505];
bool fl;

int main() {
    scanf("%d %d", &n, &m);

    if(n <= m) {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d", &a[i][j]);
    }
    else {
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
                scanf("%d", &a[i][j]);
        swap(n,m);
        fl = 1;
    }

    int ans = 0;
    vector<int>row,col;

    for(int i=0; i<n; i++) {
        int mn = INT_MAX;
        for(int j=0; j<m; j++) mn = min(mn, a[i][j]);
        ans += mn;
        for(int j=0; j<m; j++) a[i][j] -= mn;
        for(int x=0; x<mn; x++) row.push_back(i);
    }

    for(int j=0; j<m; j++) {
        int mn = INT_MAX;
        for(int i=0; i<n; i++) mn = min(mn, a[i][j]);
        ans += mn;
        for(int i=0; i<n; i++) a[i][j] -= mn;
        for(int x=0; x<mn; x++) col.push_back(j);
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j]) {
                printf("-1\n");
                return 0;
            }

    cout << row.size()+col.size() << endl;
    for(int r : row) cout << (fl? "col " : "row ") << r+1 << endl;
    for(int c : col) cout << (fl? "row " : "col ") << c+1 << endl;
}
