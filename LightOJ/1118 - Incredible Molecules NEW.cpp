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
//typedef pair<double,double> pdd
#define EPS 1e-9

//double dist(pdd a, pdd b) { return sqrt( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) );}

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        double x1,y1,r1, x2,y2,r2;
        scanf("%lf %lf %lf %lf %lf %lf", &x1,&y1,&r1, &x2,&y2,&r2); ///CHECK IF DOESN'T COLLIDE
        double dis = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
//        cout << "DIS " << dis << endl;

        if(r1+r2 <= dis) {
            printf("Case %d: 0\n", t);
            continue;
        }
        if(r1+dis <= r2) {
//            cout << "HERE 1" << endl;
            printf("Case %d: .10lf\n", t, pi*r1*r1);
            continue;
        }
        if(r2+dis <= r1) {
//            cout << "HERE 2" << endl;
            printf("Case %d: .10lf\n", t, pi*r2*r2);
            continue;
        }

        double alpha,beta;
        double s;
        double tri, cir1,cir2;

        alpha = 2.0 * acos( (dis*dis + r1*r1 - r2*r2)/(2.0 *dis*r1) );
        beta  = 2.0 * acos( (dis*dis + r2*r2 - r1*r1)/(2.0 *dis*r2) );

        cir1 = 0.5 * r1*r1 * (alpha - sin(alpha) );
        cir2 = 0.5 * r2*r2 * (beta  - sin(beta  ));

//        s = (r1+r2+dis) / 2.0;
//        tri = 2*sqrt( s*(s-r1)*(s-r2)*(s-dis) );

        printf("Case %d: %.10lf\n", t, cir1+cir2);
    }
    return 0;
}

