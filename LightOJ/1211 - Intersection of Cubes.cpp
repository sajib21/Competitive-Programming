#include<bits/stdc++.h>

using namespace std;

int n, x1[110], Y1[110], z1[110], x2[110], y2[110], z2[110];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d %d %d %d %d", &x1[i], &Y1[i], &z1[i], &x2[i], &y2[i], &z2[i]);
        int xx1 = x1[0] , yy1 = Y1[0] , zz1 = z1[0];
        int xx2 = x2[0] , yy2 = y2[0] , zz2 = z2[0];
        bool chk = true;
        for(int i=1; i<n && chk; i++) {
            int tx1,ty1,tz1, tx2,ty2,tz2;

            if(x2[i] >= xx1 && x2[i] <= xx2) tx2 = x2[i];
            else if(xx2 >= x1[i] && xx2 <= x2[i]) tx2 = xx2;
            else chk = false;

            if(y2[i] >= yy1 && y2[i] <= yy2) ty2 = y2[i];
            else if(yy2 >= Y1[i] && yy2 <= y2[i]) ty2 = yy2;
            else chk = false;

            if(z2[i] >= zz1 && z2[i] <= zz2) tz2 = z2[i];
            else if(zz2 >= z1[i] && zz2 <= z2[i]) tz2 = zz2;
            else chk = false;

            if(x1[i] <= xx2 && x1[i] >= xx1) tx1 = x1[i];
            else if(xx1 <= x2[i] && xx1 >= x1[i]) tx1 = xx1;
            else chk = false;

            if(Y1[i] <= yy2 && Y1[i] >= yy1) ty1 = Y1[i];
            else if(yy1 <= y2[i] && yy1 >= Y1[i]) ty1 = yy1;
            else chk = false;

            if(z1[i] <= zz2 && z1[i] >= zz1) tz1 = z1[i];
            else if(zz1 <= z2[i] && zz1 >= z1[i]) tz1 = zz1;
            else chk = false;

            xx1 = tx1; xx2 = tx2; yy1 = ty1; yy2 = ty2; zz1 = tz1; zz2 = tz2;
        }
        if(!chk) printf("Case %d: 0\n", t);
        else printf("Case %d: %d\n", t, (xx2-xx1)*(yy2-yy1)*(zz2-zz1) );
    }
    return 0;
}
