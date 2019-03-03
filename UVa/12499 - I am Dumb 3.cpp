#include<bits/stdc++.h>

using namespace std;

int n,l, x, ara[55];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d %d",&n, &l);

        int xorSum = 0;

        for(int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
        }

        int i;
        for(i=1; i<n; i+=2) {
            xorSum ^= ara[i] - ara[i-1];
        }

        if(i == n) xorSum ^= (l-ara[i-1]);

        if(xorSum) printf("Case %d: First Player\n", t);
        else printf("Case %d: Second Player\n", t);

    }

    return 0;

}
