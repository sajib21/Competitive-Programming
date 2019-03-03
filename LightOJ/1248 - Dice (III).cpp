#include<bits/stdc++.h>

using namespace std;

double ex[100005];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int all;
        scanf("%d", &all);
        ex[0] = 0;

        for(int rem = 1; rem<=all; rem++) {
            ex[rem] = ex[rem-1] +  1.0*all/rem;
        }

        printf("Case %d: %.10lf\n", t, ex[all]);
    }

    return 0;

}
