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
        int a,b;
        scanf("%d : %d", &a, &b);
        double g = 1.0*a/b;
        double theta = pi - 2*atan(g);
        double w = 200 / (g + theta/2*sqrt(1+g*g));
        printf("Case %d: %.10lf %.10lf\n",t, g*w, w);
    }
    return 0;

}

