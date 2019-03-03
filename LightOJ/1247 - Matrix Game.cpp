#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int n,m;
        scanf("%d %d", &m, &n);

        int cell, rows, xorSum = 0;
//        memset(rows, 0, sizeof(rows));

        for(int i=0; i<m; i++) {
            rows = 0;
            for(int j=0; j<n; j++) {
                scanf("%d", &cell);
                rows += cell;
            }
            xorSum = xorSum ^ rows;
        }

        if(xorSum) printf("Case %d: Alice\n", t);
        else printf("Case %d: Bob\n", t);
    }

    return 0;

}
