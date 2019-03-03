#include<bits/stdc++.h>
#define sqr(x) ( (x) * (x) )

using namespace std;

struct info{
    double x,y,z;
    info() {x = y = z = 0;}
    info(double xx, double yy = 0, double zz = 0) {
        x = xx; y = yy; z = zz;
    }
};

double dist(info a, info b) { return sqrt( sqr(a.x-b.x) + sqr(a.y-b.y) ); }/// RETURNS DIST*DIST
double area(info a, info b, info c) { return abs(0.5*((a.x-b.x)*(b.y-c.y) - (b.x-c.x)*(a.y-b.y))) ; }

info a,b,c,d,e,f, g,h;

int main() {
//    freopen("1249i.txt", "r", stdin);
//    freopen("1249o.txt", "w", stdout);

    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &a.x,&a.y, &b.x,&b.y, &c.x,&c.y, &d.x,&d.y, &e.x,&e.y, &f.x,&f.y)) {
        if(!a.x && !a.y && !b.x && !b.y && !c.x && !c.y && !d.x && !d.y && !e.x && !e.y && !f.x && !f.y) return 0;

        double tri = area(d,e,f);

        double lo=0, hi=10000,md;
        for(int i=0; i<1000; i++) {
            double t = (lo+hi)/2;
            double dx,dy;
            h.x = a.x + t*(c.x-a.x);
            h.y = a.y + t*(c.y-a.y);
            dx = h.x-a.x, dy = h.y-a.y;
            g.x = b.x+dx, g.y = b.y+dy;

            double para = area(a,b,g) + area(a,g,h);

            if(para >= tri) hi = t;
            else lo = t;
        }
        printf("%.3f %.3f %.3f %.3f\n", g.x,g.y, h.x,h.y );

    }
}
