#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int ax,ay, bx,by, cx,cy, dx,dy, difx,dify;
        scanf("%d %d %d %d %d %d", &ax,&ay,&bx,&by,&cx,&cy);
        difx = ax - bx;
        dify = ay - by;
        dx = cx + difx;
        dy = cy + dify;
        printf("Case %d: %d %d %d\n",t, dx,dy, abs( (ax-bx)*(by-cy) - (bx-cx)*(ay-by) ) );
    }
    return 0;
}
