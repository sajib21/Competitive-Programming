#include<bits/stdc++.h>
#define LIM 32
#define MAX 1000
#define sqr(x) ( (x) * (x) )
#define pb(x) push_back(x)

using namespace std;

int a,b,c;
int A,B,C;
bool pith[2000006];
vector<int> x[2000006], y[2000006];

int main() {
//    cout << sqrt(1000) << endl;
//    cout << sqrt(sqr(120) + sqr(288)) << endl;
//    cout << sqrt(sqr(120) + sqr( 50)) << endl;
//    cout << sqrt(sqr(104) + sqr( 78)) << endl;

    for(int m=1; m<=LIM; m++) {
        for(int n=1; n<=LIM; n++) {
            a = abs(m*m - n*n);
            b = 2*m*n;
            c = m*m + n*n;
            if(!a) continue;

            if(a > b) swap(a,b);
            for(int i=1; ; i++) {
                A = i*a; B = i*b; C = i*c;
                if(A > MAX || B > MAX || C > MAX) break;
//                if(pith[C]) continue;
                x[C].pb(A); y[C].pb(B);
                pith[C] = 1;
//                cout << A << ' ' << B << ' ' << C << endl;
            }
        }
    }
//    cout << x[312] << ' ' << y[312] << endl;
//    cout << pith[999] << ' ' << x[999] << ' ' << y[999] << endl;

    int sq = sqr(a)+sqr(b);
    while(scanf("%d %d", &a,&b) != EOF) {
//        cout << x[a] << ' ' << y[a] << ' ' << a << endl;
//        cout << x[b] << ' ' << y[b] << ' ' << b << endl;
//        cout << sq << endl;
//        cout << "ONE " << sqr(x[a]+x[b])+sqr(y[a]-y[b]) << endl;
        if(pith[a] && pith[b]) {
            bool ff = true;
            for(int i=0; ff && i<x[a].size(); i++) {
                for(int j=0; ff && j<x[b].size(); j++) {
//                    int xa = x[a][i]
//                    cout << x[a][i] << ' ' << y[a][i] << endl;
//                    cout << x[b][j] << ' ' << y[b][j] << endl;
                    if(y[a][i] != y[b][j] && sq == sqr(x[a][i]+x[b][j])+sqr(y[a][i]-y[b][j])) {
                        cout << "YES" << endl; ff = false;
                        cout << 0 << ' ' << 0 << endl;
                        cout << x[a][i] << ' ' << y[a][i];
                        cout << -x[b][j] << ' ' << y[b][j] << endl;
                    }
                    else if(x[a][i] != x[b][j] && sq == sqr(y[a][i]+y[b][j])+sqr(x[a][i]-x[b][j])) {
                        cout << "YES" << endl; ff = false;
                        cout << 0 << ' ' << 0 << endl;
                        cout << ' ' << y[a][i] << ' ' << x[a][i] << endl;
                        cout << -y[b][j] << ' ' << x[b][j] << endl;
                    }

                    else if(x[a][i] != y[b][j] && sqr(a)+sqr(b) == sqr(y[a][i]+x[b][j])+sqr(x[a][i]-y[b][j])) {
                        cout << "YES" << endl; ff = false;
                        cout << 0 << ' ' << 0 << endl;
                        cout << y[a][i] << ' ' << x[a][i] << endl;
                        cout << -x[b][j] << ' ' << y[b][j] << endl;
                    }
                    else if(y[a][i] != x[b][j] && sqr(a)+sqr(b) == sqr(x[a][i]+y[b][j])+sqr(y[a][i]-x[b][j]) ) {
                        cout << "YES" << endl; ff = false;
                        cout << 0 << ' ' << 0 << endl;
                        cout << x[a][i] << ' ' << y[a][i] << endl;
                        cout << -y[b][j] << ' ' << x[b][j] << endl;
                    }

                }
            }
            if(ff) cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
}
