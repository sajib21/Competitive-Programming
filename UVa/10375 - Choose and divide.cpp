#include<bits/stdc++.h>

using namespace std;

int main() {
    int p,q,r,s;

    while(scanf("%d %d %d %d", &p,&q,&r,&s) != EOF) {
        double ans = 1, lo = 1, hi = 1000000000;

        int a = p, b = q, c = r, d = s;



        while( a > p-q || b > 1 || c > r-s || d > 1 ) {
//            cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << ans << endl; getchar();
            bool f = true;
            if(ans < lo) {
//                cout << "FF" << endl;
                if(a > p-q) ans *= a-- , f = false;
                else if(d > 1) ans *= d--, f = false;
            }
            else if(ans > hi) {
//                cout << "SS" << endl;
                if(b > 1) ans /= b-- , f = false;
                else if(c > r-s) ans /= c-- , f = false;
            }
            if(f) {
//                cout << "EE" << endl;
                if(a > p-q) ans *= a--;
                else if(d > 1) ans *= d--;
                if(b > 1) ans /= b--;
                else if(c > r-s) ans /= c--;
            }
        }

        printf("%.5lf\n", ans);
    }

    return 0;
}
