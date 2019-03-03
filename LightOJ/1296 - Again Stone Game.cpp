#include<bits/stdc++.h>

using namespace std;

int n;
//int grundy[1010];

long long int getGrundy(int n) {

    if(n == 0) return 0;

    if(n%2) return getGrundy(n/2);
    else return n/2;
}

int main() {

//    memset(grundy, -1, sizeof(grundy));

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int n, g;
        long long int xorSum = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &g);
            xorSum ^= getGrundy(g);
        }
        if(xorSum) printf("Case %d: Alice\n", t);
        else printf("Case %d: Bob\n", t);
    }

    return 0;

}
