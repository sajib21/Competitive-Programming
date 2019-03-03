#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int n, a,b, xorSum = 0;
//        int moves[200];
        scanf("%d", &n);
//        scanf("%d", &a);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &a, &b);
//            cout << b-a << endl;
            xorSum = xorSum ^ (b-a-1);
//            a = b;
        }

        if(xorSum) printf("Case %d: Alice\n", t);
        else printf("Case %d: Bob\n", t);
    }

    return 0;
}
