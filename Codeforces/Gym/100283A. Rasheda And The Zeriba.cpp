#include<bits/stdc++.h>
#define pi acos(-1)

using namespace std;

int n, a[1010];

double f(double r) {
    double cover = 0;
    for(int i=0; i<n; i++) {
        double tmp = acos( (2*r*r - a[i]*a[i])/(2*r*r) ) * r;
        cover += tmp;
    }
    return cover;
}

int main() {
    freopen("zeriba.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int sum = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        bool ok = true;
        for(int i=0; i<n; i++) {
            if(sum-a[i] <= a[i]) ok = false;
        }
        if(!ok) {
            printf("Case %d: can't form a convex polygon\n", t);
            continue;
        }

        double lo = 0, hi = 100000000, md;

        for(int i=0; i<50; i++) {
            md = (lo+hi)/2.0;

            if( f(md) <= 2*pi*md) hi = md;
            else lo = md;

        }

        printf("Case %d: %.4f\n", t, hi);

    }
}
