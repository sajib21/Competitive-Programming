#include<bits/stdc++.h>
#define LIM 20004
#define ll long long int

using namespace std;

ll n, x, y, z;
ll xx[LIM], yy[LIM], zz[LIM];

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        ll xa,xb, ya,yb, za,zb, r=0;

        scanf("%lld %lld %lld", &x,&y,&z);
        xx[0] = xa = xb = x; yy[0] = ya = yb = y; zz[0] = za = zb = z;

        for(int i=1; i<n; i++) {
            scanf("%lld %lld %lld", &x, &y, &z); xx[i] = x; yy[i] = y; zz[i] = z;
            xa = min(xa, x); xb = max(xb, x);
            ya = min(ya, y); yb = max(yb, y);
            za = min(za, z); zb = max(zb, z);
        }
        r = max(r, xb-xa); r = max(r, yb-ya); r = max(r, zb-za);

        ll xxa = xa, xxb = xb, yya = ya, yyb = yb, zza = za, zzb = zb;

        ///000
        {
            bool f = true;
            xa = xxa, xb = xxb, ya = yya, yb = yyb, za = zza, zb = zzb;
            if(xb - xa < r) xb = xa + r;
            if(yb - ya < r) yb = ya + r;
            if(zb - za < r) zb = za + r;

//            cout << r << ' ' << xa << ' ' << xb << ' ' << ya << ' ' << yb << ' ' << za << ' ' << zb << endl;


            for(int i=0; f && i<n; i++) {
                x = xx[i]; y = yy[i]; z = zz[i];
                if(x > xa && x < xb && y > ya && y < yb && z > za && z < zb) {
                    f = false;
                    break;
                }
//                cout << i << ' ' << f << endl;
            }

            if(f) {
                printf("Case %d: %lld\n", t, r);
                continue;
            }
        }

        /// 001
        {
            bool f = true;
            xa = xxa, xb = xxb, ya = yya, yb = yyb, za = zza, zb = zzb;
            if(xb - xa < r) xa = xb - r;
            if(yb - ya < r) yb = ya + r;
            if(zb - za < r) zb = za + r;

//            cout << r << ' ' << xa << ' ' << xb << ' ' << ya << ' ' << yb << ' ' << za << ' ' << zb << endl;


            for(int i=0; f && i<n; i++) {
                x = xx[i]; y = yy[i]; z = zz[i];
                if(x > xa && x < xb && y > ya && y < yb && z > za && z < zb) {
                    f = false;
                    break;
                }
//                cout << i << ' ' << f << endl;
            }

            if(f) {
                printf("Case %d: %lld\n", t, r);
                continue;
            }
        }

        ///010
        {
            bool f = true;
            xa = xxa, xb = xxb, ya = yya, yb = yyb, za = zza, zb = zzb;
            if(xb - xa < r) xb = xa + r;
            if(yb - ya < r) ya = yb - r;
            if(zb - za < r) zb = za + r;

//            cout << r << ' ' << xa << ' ' << xb << ' ' << ya << ' ' << yb << ' ' << za << ' ' << zb << endl;


            for(int i=0; f && i<n; i++) {
                x = xx[i]; y = yy[i]; z = zz[i];
                if(x > xa && x < xb && y > ya && y < yb && z > za && z < zb) {
                    f = false;
                    break;
                }
//                cout << i << ' ' << f << endl;
            }

            if(f) {
                printf("Case %d: %lld\n", t, r);
                continue;
            }
        }

        ///011
        {
            bool f = true;
            xa = xxa, xb = xxb, ya = yya, yb = yyb, za = zza, zb = zzb;
            if(xb - xa < r) xa = xb - r;
            if(yb - ya < r) ya = yb - r;
            if(zb - za < r) zb = za + r;

//            cout << r << ' ' << xa << ' ' << xb << ' ' << ya << ' ' << yb << ' ' << za << ' ' << zb << endl;


            for(int i=0; f && i<n; i++) {
                x = xx[i]; y = yy[i]; z = zz[i];
                if(x > xa && x < xb && y > ya && y < yb && z > za && z < zb) {
                    f = false;
                    break;
                }
//                cout << i << ' ' << f << endl;
            }

            if(f) {
                printf("Case %d: %lld\n", t, r);
                continue;
            }
        }

        ///100
        {
            bool f = true;
            xa = xxa, xb = xxb, ya = yya, yb = yyb, za = zza, zb = zzb;
            if(xb - xa < r) xb = xa + r;
            if(yb - ya < r) yb = ya + r;
            if(zb - za < r) za = zb - r;

//            cout << r << ' ' << xa << ' ' << xb << ' ' << ya << ' ' << yb << ' ' << za << ' ' << zb << endl;


            for(int i=0; f && i<n; i++) {
                x = xx[i]; y = yy[i]; z = zz[i];
                if(x > xa && x < xb && y > ya && y < yb && z > za && z < zb) {
                    f = false;
                    break;
                }
//                cout << i << ' ' << f << endl;
            }

            if(f) {
                printf("Case %d: %lld\n", t, r);
                continue;
            }
        }

        ///101
        {
            bool f = true;
            xa = xxa, xb = xxb, ya = yya, yb = yyb, za = zza, zb = zzb;
            if(xb - xa < r) xa = xb - r;
            if(yb - ya < r) yb = ya + r;
            if(zb - za < r) za = zb - r;

//            cout << r << ' ' << xa << ' ' << xb << ' ' << ya << ' ' << yb << ' ' << za << ' ' << zb << endl;


            for(int i=0; f && i<n; i++) {
                x = xx[i]; y = yy[i]; z = zz[i];
                if(x > xa && x < xb && y > ya && y < yb && z > za && z < zb) {
                    f = false;
                    break;
                }
//                cout << i << ' ' << f << endl;
            }

            if(f) {
                printf("Case %d: %lld\n", t, r);
                continue;
            }
        }

        ///110
        {
            bool f = true;
            xa = xxa, xb = xxb, ya = yya, yb = yyb, za = zza, zb = zzb;
            if(xb - xa < r) xb = xa + r;
            if(yb - ya < r) ya = yb - r;
            if(zb - za < r) za = zb - r;

//            cout << r << ' ' << xa << ' ' << xb << ' ' << ya << ' ' << yb << ' ' << za << ' ' << zb << endl;


            for(int i=0; f && i<n; i++) {
                x = xx[i]; y = yy[i]; z = zz[i];
                if(x > xa && x < xb && y > ya && y < yb && z > za && z < zb) {
                    f = false;
                    break;
                }
//                cout << i << ' ' << f << endl;
            }

            if(f) {
                printf("Case %d: %lld\n", t, r);
                continue;
            }
        }

        ///111
        {
            bool f = true;
            xa = xxa, xb = xxb, ya = yya, yb = yyb, za = zza, zb = zzb;
            if(xb - xa < r) xa = xb - r;
            if(yb - ya < r) ya = yb - r;
            if(zb - za < r) za = zb - r;

//            cout << r << ' ' << xa << ' ' << xb << ' ' << ya << ' ' << yb << ' ' << za << ' ' << zb << endl;


            for(int i=0; f && i<n; i++) {
                x = xx[i]; y = yy[i]; z = zz[i];
                if(x > xa && x < xb && y > ya && y < yb && z > za && z < zb) {
                    f = false;
                    break;
                }
//                cout << i << ' ' << f << endl;
            }

            if(f) {
                printf("Case %d: %lld\n", t, r);
                continue;
            }
        }

        printf("Case %d: -1\n", t);
    }
}
