#include<bits/stdc++.h>

using namespace std;

int main() {
    int lo = 1, hi = 1000000, md;
    char ans[4];

    while(lo < hi) {
        md = (lo+hi + 1) / 2;
        printf("%d\n", md);
//        printf("%d %d %d\n", lo, md, hi);
        fflush(stdout);

        scanf("%s", ans);
        if(ans[0] == '<') hi = md-1;
        else lo = md;
    }

    printf("! %d\n", lo);
    fflush(stdout);

    return 0;
}
