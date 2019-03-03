#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n;
vector<int> xCoY[1010], yCoX[1010], pointX, pointY;
int grid[1010][1010];

void BFS(int x, int y) {

    grid[x][y] = 1;
    queue<pii>q;

    q.push(pii(x,y));



    while(!q.empty()) {

        pii p = q.front();
        q.pop();
        int xx = p.first, yy = p.second;
        //cout << xx << ' ' << yy << endl;
        int sz = xCoY[xx].size();
        for(int i=0; i<sz; i++) {//cout << "buggy" << endl;
            int ty = xCoY[xx][i];
            if(!grid[xx][ty]) {
                grid[xx][ty] = 1;
                q.push(pii(xx,ty));
            }

        }

        sz = yCoX[yy].size();
        for(int i=0; i<sz; i++) {
            int tx = yCoX[yy][i];
            if(!grid[tx][yy]) {
                grid[tx][yy] = 1;
                q.push(pii(tx,yy));
            }//cout << "dekhi" << endl;
        }

    }
}

int main() {

    scanf("%d", &n);

    int x,y;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x,&y);
        pointX.push_back(x);
        pointY.push_back(y);

        xCoY[x].push_back(y);
        yCoX[y].push_back(x);
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        x = pointX[i]; y = pointY[i];
        if(!grid[x][y]) {
            BFS(x,y);
            ans++;
        }
    }

    printf("%d\n", ans-1);

    return 0;
}
