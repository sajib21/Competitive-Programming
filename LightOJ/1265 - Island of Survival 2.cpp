#include<bits/stdc++.h>

using namespace std;

int t,d;

int main() {


    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++) {
        scanf("%d %d", &t, &d);
        if(t%2) printf("Case %d: %.10lf\n", tt, 0.0);
        else printf("Case %d: %.10lf\n", tt, 1.0 / (t+1) );
    }
    return 0;
}
