#include<bits/stdc++.h>
#define sqr(x) ( (x) * (x) )
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

struct point {
    double x,y;
    point() {}
    point(double xx, double yy) {
        x = xx; y = yy;
    }
    double dist(point b) {
        return sqr(x-b.x) + sqr(y-b.y);
    }
};

double dist(point a,point b) {
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}

int n,m, x[25], y[25], under[25];
double d[25];
point c[25];

void printInfo() {
    cout << "CENTROID:" << endl;
    for(int i=0; i<m; i++) cout << c[i].x << ' ' << c[i].y << endl;
    cout << "UNDER" << endl;
    for(int i=0; i<n; i++) cout << i << ' ' << under[i] << endl;
}

void cluster() {
//    printInfo();

    for(int i=0; i<n; i++) {
        under[i] = 0; d[i] = c[0].dist(point(x[i],y[i]));
        for(int j=0; j<m; j++) {
            double temp = c[j].dist(point(x[i],y[i]));
            if(temp < d[i]) {
                under[i] = j;
                d[i] = temp;
            }
        }
    }

    int sx[25] = {}, sy[25] = {}, cnt[25] = {};
    for(int i=0; i<n; i++) {
        sx[ under[i] ] += x[i];
        sy[ under[i] ] += y[i];
        cnt [ under[i] ]++;
    }
    for(int i=0; i<m; i++) {
        c[i].x = 1.0*sx[i]/cnt[i];
        c[i].y = 1.0*sy[i]/cnt[i];
    }
}

double gg(vi id) {
    double r = 0;
    double ax,ay, bx,by;
    for(int i=0; i<id.size(); i++) {
        ax = x[ id[i] ], ay = y[ id[i] ];
        for(int j=i+1; j<id.size(); i++) {
            bx = x[ id[j] ], by = y[ id[i] ];
            r = max(r, dist(point(ax,ay), point(bx,by)) );
        }
    }
    return r;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
        for(int i=0; i<m; i++) c[i].x = x[i], c[i].y = y[i];

        for(int i=0; i<20; i++) cluster();

        double r = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(under[i] != under[j]) continue;
                r = max(r, dist(point(x[i],y[i]), point(x[j],y[j]) ) );
            }
        }

        printInfo();

        printf("Case %d: %.2f\n", t, sqrt(r)/2);
    }
}
