#include<bits/stdc++.h>
#define ll long long int
#define sqr(x) ( (x) * (x) )

using namespace std;

ll sum(ll x) {
    return x*(x+1)/2;
}
double bigMod(double n, int r) {
    if(!n) return 0;
    if(!r) return 1.0;
    if(r%2) return (bigMod(n, r-1)*n);
    double ans = bigMod(n, r/2);
    return (ans*ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        ll X,Y,Z;
        int k;
        scanf("%lld %lld %lld %d", &X,&Y,&Z, &k);

        ll all = sum(X) * sum(Y) * sum(Z);

        double ans = 0;
        for(ll x=0; x<X; x++) {
            for(ll y=0; y<Y; y++) {
                for(ll z=0; z<Z; z++) {
//                    double p = 1.0 * (x+1)*(X-x) * (y+1)*(Y-y) * (z+1)*(Z-z) / all;
                    double pr = 1.0, p;
                    p = 1.0;
                    if(x != 0) p -= sqr(1.0*x/X);
                    if(X-x-1 != 0) p -= sqr(1.0 * (X-x-1)/X);
                    pr *= p;

//                    cout << p << endl;

                    p = 1;
                    if(y != 0) p -= sqr(1.0*y/Y);
                    if(Y-y-1 != 0) p -= sqr(1.0 * (Y-y-1)/Y);
                    pr *= p;
//                    cout << p << endl;

                    p = 1;
                    if(z != 0) p -= sqr(1.0*z/Z);
                    if(Z-z-1 != 0) p -= sqr(1.0 * (Z-z-1)/Z);
                    pr *= p;
//                    cout << p << endl;

//                    cout << x << ' ' << y << ' ' << z << ' ' << pr << endl;

                    ans += 0.5*(1-bigMod(1-2*pr, k));
                }
            }
        }
        printf("Case %d: %.10lf\n", t, ans);
    }
    return 0;
}
