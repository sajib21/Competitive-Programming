#include<bits/stdc++.h>
#define sqr(x) ( (x) * (x) )
#define ld long double
#define EPS 1e-12

using namespace std;

double W,H,x,xe,ye, U;
ld p; /// p = sin^2(r)

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%lf %lf %lf %lf %lf %lf", &W, &H, &x, &xe, &ye, &U);

        p = sqr(xe-W) / ( sqr(xe-W) + sqr(ye-H) );
        U = 1/U;
        U = sqr(U);

        ld lo = 0, hi = H+1;
        ld h,k;
        for(int i=0; i<100; i++) {
            h = (lo+hi)/2;

            k = sqrt( sqr(h) * p * U / ( 1 - p*U ) );

            ld lombo = xe - x - k;
            ld bhumi = ye - h;
            ld sine = sqr(lombo) / (sqr(lombo)+sqr(bhumi));

            if( sine < p-EPS ) lo = h;
            else hi = h;

        }
        if(k > (W-x) || hi > H) printf("Impossible\n");
        else printf("%.4f\n", (double) hi);
    }
}
