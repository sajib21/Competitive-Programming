#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        double a,b,c, p,q;
        scanf("%lf %lf %lf", &a,&b,&c);



        p = a*c/b;
        q = (a+p)*(c+p)/(b-p);

        if(p < 0 || b-p <= 0) printf("Case %d: -1\n", t);
        else printf("Case %d: %.8f\n", t, p+q);

    }
}
