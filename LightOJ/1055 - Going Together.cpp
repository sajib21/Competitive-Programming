#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};


int n, ar,ac, br,bc, cr,cc;
char grid[15][15];
int visa[15][15], visb[15][15], visc[15][15];

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
                if(grid[i][j] == 'C') cr = i , cc = j;
            }
        }
        memset(visa, 0, sizeof(visa)); visa[ar][ac] = 1;
        memset(visb, 0, sizeof(visb)); visa[br][bc] = 1;
        memset(visc, 0, sizeof(visc)); visa[cr][cc] = 1;
        queue<pii> qa,qb,qc;
        queue<int> qcnt;
        qa.push(pii(ar,ac));
        qa.push(pii(br,bc));
        qa.push(pii(cr,cc));
        qcnt.push(0);

        while(!qa.empty()) {
            pii posa = qa.front(); qa.pop();
            pii posb = qb.front(); qb.pop();
            pii posc = qc.front(); qc.pop();
            int cnt = qcnt.front(); qcnt.pop();

            int ar,ac, br,bc, cr,cc;
            ar = posa.first; ac = posa.second;
            br = posb.first; bc = posb.second;
            cr = posc.first; cc = posc.second;

            if(grid[ar][ac] )

            for(int i=0; i<4; i++) {
                int aar,aac, bbr,bbc, ccr,ccc;
                aar = ar+dirR[i]; aac = ac+dirC[i];
                bbr = br+dirR[i]; bbc = bc+dirC[i];
                ccr = cr+dirR[i]; ccc = cc+dirC[i];

                if(grid[aar][aac] != '.') aar = ar , aac = ac;
                if(grid[bbr][bbc] != '.') bbr = br , bbc = bc;
                if(grid[ccr][ccc] != '.') ccr = cr , ccc = cc;

                if(!visa[aar][aac] || !visb[bbr][bbc] || !visc[ccr][ccc]) {
//                    if(grid[aar][aac] == '.') visa[aar][aac] = 1;
//                    if(grid[bbr][bbc] == '.') visa[bbr][bbc] = 1;
//                    if(grid[ccr][ccc] == '.') visa[ccr][ccc] = 1;
                    visa[aar][aac] = visb[bbr][bbc] = visc[ccr][ccc] = 1;
                    qa.push(pii(aar,aac));
                    qb.push(pii(bbr,bbc));
                    qc.push(pii(ccr,ccc));
                    qcnt.push(cnt+1);
                }
            }
        }
    }

}
