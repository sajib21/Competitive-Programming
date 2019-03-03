#include<bits/stdc++.h>
#define vi vector<int>

#define vs vector<string>
#define pb(x) push_back(x)

using namespace std;

vi getPos(vs grid) {
    int pos[4] = {-1,-1,-1,-1};
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) if(isalpha(grid[i][j]) ) {
            if(pos[ grid[i][j]-'A' ] == -1) pos[ grid[i][j]-'A' ] = i*8+j;
        }
    }
    return vi (pos, pos+4);
}
void printInfo(vs u) {
//    cout << "GRID: " << endl;
//    for(int i=0; i<8; i++) {
//        for(int j=0; j<8; j++) printf("%c", u[i][j]);
//        printf("\n");
//    }
    vi p = getPos(u);
    cout << "POS: " << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << endl;
    printf("\n");
}

char str[10][10];

vs leftGravity(vs u) {
    vs v = u;
    vi pos = {-1,-1,-1,-1};

    while(true) {
        vi cur = getPos(v);
        if(cur == pos) break;
        pos = cur;

        for(int i=0; i<4; i++) {
            int r = pos[i]/8;
            int c = pos[i]%8;

            while(true) {
                if(!c) break;
                if(v[r][c-1] == '.' && v[r+1][c-1] == '.') {
                    v[r][c-1] = v[r+1][c-1] = i+'A';
                    v[r][c+1] = v[r+1][c+1] = '.';
                }
                else break;
            }
        }
    }
    return v;
}

vs rightGravity(vs u) {
    vs v = u;
    vi pos = {-1,-1,-1,-1};

    while(true) {
        vi cur = getPos(v);
        if(cur == pos) break;
        pos = cur;

        for(int i=0; i<4; i++) {
            int r = pos[i]/8;
            int c = pos[i]%8;

            while(true) {
                if(c >= 6) break;
                if(v[r][c+2] == '.' && v[r+1][c+2] == '.') {
                    v[r][c+2] = v[r+1][c+2] = i+'A';
                    v[r][c  ] = v[r+1][c  ] = '.';
                }
                else break;
            }
        }
    }
    return v;
}

vs upGravity(vs u) {
    vs v = u;
    vi pos = {-1,-1,-1,-1};

    while(true) {
        vi cur = getPos(v);
        if(cur == pos) break;
        pos = cur;

        for(int i=0; i<4; i++) {
            int r = pos[i]/8;
            int c = pos[i]%8;

            while(true) {
                if(!r) break;
                if(v[r-1][c] == '.' && v[r-1][c+1] == '.') {
                    v[r-1][c] = v[r-1][c+1] = i+'A';
                    v[r+1][c] = v[r+1][c+1] = '.';
                }
                else break;
            }
        }
    }
    return v;
}

vs downGravity(vs u) {
    vs v = u;
    vi pos = {-1,-1,-1,-1};

    while(true) {
        vi cur = getPos(v);
        if(cur == pos) break;
        pos = cur;

//        cout << "DOWN IN: " << endl;
//        printInfo(v);
//        getchar();

        for(int i=0; i<4; i++) {
            int r = pos[i]/8;
            int c = pos[i]%8;

            while(true) {
                if(r >= 6) break;
                if(v[r+2][c] == '.' && v[r+2][c+1] == '.') {
                    v[r+2][c] = v[r+2][c+1] = i+'A';
                    v[r][c  ] = v[r  ][c+1] = '.';
                }
                else break;
            }
        }
    }
    return v;
}



int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        for(int i=0; i<8; i++) scanf("%s", str[i]);

        vs root, u;
        for(int i=0; i<8; i++) {
            string seq = str[i];
            root.pb(seq);
        }
        vi pos = getPos(root), p;

        map<vi, bool>vis;
        queue<vs>q;

        int ans = 0;

        u = leftGravity(root); p = getPos(u);
        if(vis.find(p) == vis.end()) {
            ans++;
            vis[p] = true;
            q.push(u);
        }
        u = rightGravity(root); p = getPos(u);
        if(vis.find(p) == vis.end()) {
            ans++;
            vis[p] = true;
            q.push(u);
        }
        u = upGravity(root); p = getPos(u);
        if(vis.find(p) == vis.end()) {
            ans++;
            vis[p] = true;
            q.push(u);
        }
        u = downGravity(root); p = getPos(u);
        if(vis.find(p) == vis.end()) {
            ans++;
            vis[p] = true;
            q.push(u);
        }

        while(!q.empty()) {
            vs ugrid, vgrid;
            vi vpos;

            ugrid = q.front(); q.pop();

//            cout << "CUR: " << ans << endl;
//            printInfo(ugrid);
//            getchar();

            vgrid = leftGravity(ugrid);
            vpos = getPos(vgrid);
            if(vis.find(vpos) == vis.end()) {
                vis[vpos] = true;
                ans++;
                q.push(vgrid);
            }

            vgrid = rightGravity(ugrid);
            vpos = getPos(vgrid);
            if(vis.find(vpos) == vis.end()) {
                vis[vpos] = true;
                ans++;
                q.push(vgrid);
            }

            vgrid = upGravity(ugrid);
            vpos = getPos(vgrid);
            if(vis.find(vpos) == vis.end()) {
                vis[vpos] = true;
                ans++;
                q.push(vgrid);
            }

            vgrid = downGravity(ugrid);
            vpos = getPos(vgrid); //cout << "DONE" << endl;
            if(vis.find(vpos) == vis.end()) {
                vis[vpos] = true;
                ans++;
                q.push(vgrid);
            }
        }

        printf("Case %d: %d\n", t, ans);
    }
}
