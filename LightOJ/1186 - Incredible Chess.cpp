#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int n, wht[110], b , xorSum = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &wht[i]);
        for(int i=0; i<n; i++) {
            scanf("%d", &b);
            xorSum = xorSum ^ (b-wht[i]-1);
        }

        if(xorSum) printf("Case %d: white wins\n", t);
        else       printf("Case %d: black wins\n", t);
    }

    return 0;

}
