#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        double x1,y1,r1, x2,y2,r2;


        double chord, midChordx, midChordy;
        double alpha,beta;
        double s1,s2;
        double tri1,cir1, tri2,cir2;

        scanf("%lf %lf %lf %lf %lf %lf", &x1,&y1,&r1, &x2,&y2,&r2);
        midChordx = (x1+x2) / 2.0;
        midChordy = (y1+y2) / 2.0;
        double dis = sqrt( (midChordx-x2)*(midChordx-x2) + (midChordy-y2)*(midChordy-y2) );

        cout << "MID " << midChordx << ' ' << midChordy << ' ' << dis << endl;

        double lo=0 , hi = 2*min(r1,r2), md;
//        hi = 1000000;
        while(lo < hi) {
            chord = (lo+hi) / 2.0;


            double compr2 = sqrt(chord*chord/4.0 + dis*dis);

            cout << "IN " << lo << ' ' << chord << ' ' << hi << " DIS " << dis << " COMP R2 " << compr2 << endl;

            if(compr2 < r2) lo = chord;
            else hi = chord;
            if(fabs(lo-hi) <= EPS) break;
        }

        cout << "CHORD " << chord << endl;

        alpha = 2*asin(chord/(2.0*r1));
        beta  = 2*asin(chord/(2.0*r2));

        cir1 = 0.5 * alpha * r1*r1;
        cir2 = 0.5 * beta  * r2*r2;

        s1 = (r1+r1+chord) / 2.0;
        s2 = (r2+r2+chord) / 2.0;
        tri1 = sqrt( s1*(s1-r1)*(s1-r1)*(s1-chord) );
        tri2 = sqrt( s2*(s2-r2)*(s2-r2)*(s2-chord) );

        printf("Case %d: %.10lf\n", t, (cir1+cir2) - (tri1+tri2));
    }
    return 0;
}
