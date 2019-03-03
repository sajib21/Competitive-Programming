#include<bits/stdc++.h>
#define LIM 100
using namespace std;

double dp1[303][303][LIM+10], dp2[303][303][LIM+10];
bool dr1[303][303][LIM+10], dr2[303][303][LIM+10];

double f(int a, int b, int in) {
    if(!a || !b) return 0;
    if(!in) return 1;
//    if(!b) return 1;
    if(dr1[a][b][in]) return dp1[a][b][in];
    dr1[a][b][in] = 1;

    int mn = min(a,b);
    return dp1[a][b][in] = (1+f(a-mn, b+mn, in-1) + 1+f(a+mn, b-mn, in-1)) / 2.0;
}

double g(int a, int b, int in) {
//    cout << "G IN " << a << ' ' << b << ' ' << in << endl;
    //getchar();
    if(!a) return 0;
    if(!b) return 1;
    if(!in) return 1;
    if(dr2[a][b][in]) return dp2[a][b][in];
    dr2[a][b][in] = 1;

    int mn = min(a,b);
    return dp2[a][b][in] = (g(a-mn, b+mn, in-1) + g(a+mn, b-mn, in-1)) / 2.0;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int a,b;
        scanf("%d %d", &a,&b);
//        cout << f(a,b, LIM) << endl;
//        cout << g(a,b, LIM) << endl;
        printf("Case %d: %.6f %.6f\n", t, f(a,b, 100), g(a,b, 100) );
    }
}
