#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int r, l,w;
        scanf("%d", &r);
        l = 5*r;
        w = l/5*3;

        printf("Case %d:\n", t);
        printf("%d %d\n", -l*45/100, w/2);
        printf("%d %d\n", +l*55/100, w/2);
        printf("%d %d\n", +l*55/100, -w/2);
        printf("%d %d\n", -l*45/100, -w/2);
    }
}
