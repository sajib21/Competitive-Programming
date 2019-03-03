#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        double AB,BC,CA, rat;
        cin >> AB >> BC >> CA >> rat;

        printf("Case %d: %.10lf\n", t, AB * sqrt(rat/(rat+1)) );
    }

    return 0;

}
