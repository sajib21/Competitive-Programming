#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};


int n, ar,ac, br,bc, cr,cc;
char grid[11][11];
int visa[11][11], visb[11][11], visc[11][11];
int vis[11][11][11][11][11][11];
int ans;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%s", grid[i]);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 'A') ar = i , ac = j;
                else if(grid[i][j] == 'B') br = i , bc = j;
                else if(grid[i][j] == 'C') cr = i , cc = j;
            }
        }

        ans = -1;
        memset(vis, -1, sizeof(vis)); vis[ar][ac][br][bc][cr][cc] = 0;
        queue<pii> qa,qb,qc;
        qa.push(pii(ar,ac));
        qb.push(pii(br,bc));
        qc.push(pii(cr,cc));

//        cout << "INIT " << ar << ' ' << ac << ' ' << br << ' ' << bc << ' ' << cr << ' ' << cc << ' ' << vis[ar][ac][br][bc][cr][cc] << endl;

        while(!qa.empty()) {
            pii posa = qa.front(); qa.pop();
            pii posb = qb.front(); qb.pop();
            pii posc = qc.front(); qc.pop();

            int ar,ac, br,bc, cr,cc;
            ar = posa.first; ac = posa.second;
            br = posb.first; bc = posb.second;
            cr = posc.first; cc = posc.second;

            if(pii(ar,ac) == pii(br,bc) || pii(br,bc) == pii(cr,cc) || pii(cr,cc) == pii(ar,ac)) continue;

//            cout << "OUT " << ar << ' ' << ac << ' ' << br << ' ' << bc << ' ' << cr << ' ' << cc << ' ' << vis[ar][ac][br][bc][cr][cc] << endl;
//            getchar();

            if(grid[ar][ac] == 'X' && grid[br][bc] == 'X' && grid[cr][cc] == 'X') {
                ans = vis[ar][ac][br][bc][cr][cc];
//                cout << ans << ' ' << vis[ar][ac][br][bc][cr][cc] << endl;
                break;
            }

            for(int i=0; i<4; i++) {
                int aar,aac, bbr,bbc, ccr,ccc;
                aar = ar+dirR[i]; aac = ac+dirC[i];
                bbr = br+dirR[i]; bbc = bc+dirC[i];
                ccr = cr+dirR[i]; ccc = cc+dirC[i];

                if(grid[aar][aac] == '#' || aar < 0 || aar >= n || aac < 0 || aac >= n) aar = ar , aac = ac;
                if(grid[bbr][bbc] == '#' || bbr < 0 || bbr >= n || bbc < 0 || bbc >= n) bbr = br , bbc = bc;
                if(grid[ccr][ccc] == '#' || ccr < 0 || ccr >= n || ccc < 0 || ccc >= n) ccr = cr , ccc = cc;


                if(pii(aar,aac) == pii(bbr,bbc)) aar = ar , aac = ac , bbr = br , bbc = bc;
                if(pii(ccr,ccc) == pii(bbr,bbc)) ccr = cr , ccc = cc , bbr = br , bbc = bc;
                if(pii(aar,aac) == pii(ccr,ccc)) aar = ar , aac = ac , ccr = cr , ccc = cc;



                if(vis[aar][aac][bbr][bbc][ccr][ccc] == -1) {
                    vis[aar][aac][bbr][bbc][ccr][ccc] = vis[ar][ac][br][bc][cr][cc] + 1;
                    qa.push(pii(aar,aac));
                    qb.push(pii(bbr,bbc));
                    qc.push(pii(ccr,ccc));
//                    cout << "IN  " << aar << ' ' << aac << ' ' << bbr << ' ' << bbc << ' ' << ccr << ' ' << ccc << ' ' << vis[aar][aac][bbr][bbc][ccr][ccc] << endl;
//                    getchar();
                }
            }
        }
        if(ans == -1) printf("Case %d: trapped\n", t);
        else printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
