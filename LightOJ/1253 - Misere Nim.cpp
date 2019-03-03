#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int n, a, sum = 0, xorSum = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a);
            sum += a;
            xorSum ^= a;
        }

        if(sum == n) {
            if(n%2) printf("Case %d: Bob\n", t);
            else printf("Case %d: Alice\n", t);
        }
        else {
            if(xorSum) printf("Case %d: Alice\n", t);
            else printf("Case %d: Bob\n", t);
        }
    }

    return 0;

}
