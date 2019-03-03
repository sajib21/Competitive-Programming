#include <bits/stdc++.h>

using namespace std;

int nCr(int n, int r) {

    if(r==1) return n;
    if(r==n || r==0) return 1;

    return nCr(n-1, r-1) + nCr(n-1, r);
}

int main() {

    string a, b;
    cin >> a;
    cin >> b;

    int ap, am, bp, bm, bq;
    ap = am = bp = bm = bq = 0;

    int sz = a.size();
    for(int i=0; i<sz; i++) {
        if(a[i] == '+') ap++;
        else am++;
        if(b[i] == '+') bp++;
        else if(b[i] == '-') bm++;
        else bq++;
    }

    if(ap <= bp+bq) {
        if(ap == bp && am == bm) {
            printf("%.12lf\n", 1.0);
            //cout << 0 << endl;
        }
        else {
            if(ap < bp) {
                printf("%0.12lf\n", 0.0);
                //cout << 1 << endl;
            }
            else if(am < bm) {
                printf("%0.12lf\n", 0.0);
                //cout << 2 << endl;
            }
            else {
                int r = ap - bp;
                printf("%0.12lf\n", (double) nCr(bq, r)/pow(2, bq));
                //cout << 3 << ' ' << r << endl;
            }

        }
    }
    else {
        printf("%0.12lf\n", 0.0);
        //cout << 4 << endl;
    }

    return 0;


}
