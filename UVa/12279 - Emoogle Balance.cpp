#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
//    scanf("%d", &T);
    for(int t=1; ; t++) {
        int n,x, ans = 0;
        scanf("%d", &n);
        if(!n) return 0;
        while(n--) {
            scanf("%d", &x);
            if(x) ans++;
            else ans--;
        }
        printf("Case %d: %d\n", t, ans);
    }
}
