#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int R,r, H, p ;
        double Hy, Rx;
        scanf("%d %d %d %d", &R, &r, &H, &p);
        Hy = 1.0*H*r/(R-r);
        Rx = 1.0*r*(1.0 + 1.0*p/Hy) ;

        printf("Case %d: %.10lf\n", t, pi* (Rx*Rx*(Hy+p) - r*r*Hy) /3.0 );
    }
    return 0;

}
