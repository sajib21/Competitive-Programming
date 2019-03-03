#include<bits/stdc++.h>

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        int ax,ay,bx,by,cx,cy,dx,dy;
        scanf("%d %d %d %d %d %d %d %d", &ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);

        double lo = 0, hi = 1, m1 = (lo+hi)/3, m2 =m1*2;
        double fx = bx-ax, fy = by-ay, sx = dx-cx, sy = dy-cy;
        for(int x=0; x<45; x++) {

            m1 = lo+(hi-lo)/3, m2 = hi - (hi-lo)/3;

            double newAx = ax + fx*m1 - cx - sx*m1, newAy = ay + fy*m1 - cy - sy*m1;
            double newBx = ax + fx*m2 - cx - sx*m2, newBy = ay + fy*m2 - cy - sy*m2;
            double m1dis = sqrt(newAx*newAx + newAy*newAy), m2dis = sqrt(newBx*newBx + newBy*newBy);
            if(m1dis < m2dis) {
                hi = m2;
            }
            //else if(m1dis==m2dis) break;
            else {
                lo = m1;
            }
            //printf("%.10lf %.10lf\n", m1dis, m2dis);

        }

            double newAx = ax + fx*m1 - cx - sx*m1, newAy = ay + fy*m1 - cy - sy*m1;
            double newBx = ax + fx*m2 - cx - sx*m2, newBy = ay + fy*m2 - cy - sy*m2;
            double m1dis = sqrt(newAx*newAx + newAy*newAy), m2dis = sqrt(newBx*newBx + newBy*newBy);

        printf("Case %d: %.10lf\n", t, m1dis);
    }

    return 0;
}
