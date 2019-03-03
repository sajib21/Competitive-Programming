#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

int c,d,h,s,j;
double dp[17][4][17][4][17][4][17][4][4];

double expMoves(int ctaken, int cj, int dtaken, int dj, int htaken, int hj, int staken, int sj, int jtaken) {

//    cout << ctaken << ' ' << cj << ' ' << dtaken << ' ' << dj << ' ' << htaken << ' ' << hj << ' ' << staken << ' ' << sj << ' ' << jtaken << endl;
//    getchar();

    if(ctaken+cj>=c && dtaken+dj>=d && htaken+hj>=h && staken+sj>=s) return 0;

    if(dp[ctaken][cj][dtaken][dj][htaken][hj][staken][sj][jtaken] != -1) return dp[ctaken][cj][dtaken][dj][htaken][hj][staken][sj][jtaken];

    int alltaken = ctaken + dtaken + htaken + staken + jtaken;
    double ans = 0;
    int cnt = 0;


    if(ctaken < 13) ans += 1.0 * ( (13.0-ctaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken+1,cj, dtaken,dj, htaken,hj, staken,sj, jtaken) );
    if(dtaken < 13) ans += 1.0 * ( (13.0-dtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken+1,dj, htaken,hj, staken,sj, jtaken) );
    if(htaken < 13) ans += 1.0 * ( (13.0-htaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken,dj, htaken+1,hj, staken,sj, jtaken) );
    if(staken < 13) ans += 1.0 * ( (13.0-staken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken,dj, htaken,hj, staken+1,sj, jtaken) );
    if(jtaken <  2) {
        int k, koto=0;
        int o=c-ctaken, p=d-dtaken, q=h-htaken, r=s-staken;
        if(o >= p && o >= q && o >= r) ans += 1.0 * ( (2.0-jtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj+1, dtaken,dj, htaken,hj, staken,sj, jtaken+1) );
        else if(p >= o && p >= q && p >= r) ans += 1.0 * ( (2.0-jtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken,dj+1, htaken,hj, staken,sj, jtaken+1) );
        else if(q >= o && q >= p && q >= r) ans += 1.0 * ( (2.0-jtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken,dj, htaken,hj+1, staken,sj, jtaken+1) );
        else ans += 1.0 * ( (2.0-jtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken,dj, htaken,hj, staken,sj+1, jtaken+1) );

//        if(ctaken+cj < c) ans += 1.0 * ( (2.0-jtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj+1, dtaken,dj, htaken,hj, staken,sj, jtaken+1) );
//        if(dtaken+dj < d) ans += 1.0 * ( (2.0-jtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken,dj+1, htaken,hj, staken,sj, jtaken+1) );
//        if(htaken+hj < h) ans += 1.0 * ( (2.0-jtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken,dj, htaken,hj+1, staken,sj, jtaken+1) );
//        if(staken+sj < s) ans += 1.0 * ( (2.0-jtaken)/(54.0-alltaken) ) * ( 1.0 + expMoves(ctaken,cj, dtaken,dj, htaken,hj, staken,sj+1, jtaken+1) );
    }

//    cout << "STATE  : " << ctaken << ' ' << cj << ' ' << dtaken << ' ' << dj << ' ' << htaken << ' ' << hj << ' ' << staken << ' ' << sj << ' ' << jtaken << " ANS : " << ans << endl;
    return dp[ctaken][cj][dtaken][dj][htaken][hj][staken][sj][jtaken] = ans;
}

void allClear() {
    for(int A=0; A<=15; A++)
        for(int B=0; B<=2; B++)
            for(int C=0; C<=15; C++)
                for(int D=0; D<=2; D++)
                    for(int E=0; E<=15; E++)
                        for(int F=0; F<=2; F++)
                            for(int G=0; G<=15; G++)
                                for(int H=0; H<=2; H++)
                                    for(int I=0; I<=2; I++)
                                        dp[A][B][C][D][E][F][G][H][I] = -1;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d %d", &c,&d,&h,&s); j = 2;
        allClear();
        printf("Case %d: %.10lf\n", t, expMoves(0,0,0,0,0,0,0,0,0));
    }
    return 0;
}

