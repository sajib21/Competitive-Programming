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

using namespace std;


int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        double R1,R2,R3, A,B,C, alpha,beta,gamma, area1,area2,area3, S, areaTriangle, ans;
        scanf("%lf %lf %lf", &R1,&R2,&R3);
        A = R2+R3; B = R1+R3; C = R1+R2;
        alpha = acos( (B*B + C*C - A*A) / (2*B*C));
        beta  = acos( (C*C + A*A - B*B) / (2*C*A));
        gamma = acos( (A*A + B*B - C*C) / (2*A*B));

        area1 = 0.5 * alpha * R1*R1;
        area2 = 0.5 * beta  * R2*R2;
        area3 = 0.5 * gamma * R3*R3;

        S = (A+B+C)/2;
        areaTriangle = sqrt(S * (S-A) * (S-B) * (S-C));
        ans = areaTriangle - (area1+area2+area3);
        printf("Case %d: %.10lf\n", t, ans);
    }

    return 0;
}

