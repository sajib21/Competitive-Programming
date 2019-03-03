#include<bits/stdc++.h>

using namespace std;

int t,d;
double dp[1010][1010];

double f(int tl, int dl) {
//    cout << tl << ' ' << dl << endl;
//    getchar();
    if(!tl) return 1;

    if(tl < 0) return 0;
    if(dl < 0) return 0;

    if(dp[tl][dl] != -1) return dp[tl][dl];
    int all = tl+dl+1;
    double a=0,b=0, f1=0, f2=0;
    if(dl>0) f1 = f(tl, dl-1) ;
    if(tl>1) f2 = f(tl-2, dl) ;
    a = 1.0*( tl*dl*f1 + tl*(tl-1)*f2 ) / ( tl*tl + 2*tl*dl + tl + dl );
//    b = 1.0*( (tl*dl+dl)*f2 + tl*(tl-1)*f2 ) / ( all*(all-1) - dl*(dl-1) );

//    cout << tl << ' ' << dl << ' ' << a << ' ' << b << endl;

    return dp[tl][dl] = max(a,b);
}


int main() {

    for(int i=0; i<=1000; i++)
        for(int j=0; j<=1000; j++)
            dp[i][j] = -1;

    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++) {
        scanf("%d %d", &t, &d);
        printf("Case %d: %.10lf\n", tt, f(t,d));
    }
    return 0;
}
