#include<bits/stdc++.h>

using namespace std;


int main() {

    int n, x, xorSum = 0;
    while(scanf("%d", &n) && n) {
        xorSum = 0;
        while(n--) {
            scanf("%d", &x);
            xorSum ^= x;
        }
        if(xorSum) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


