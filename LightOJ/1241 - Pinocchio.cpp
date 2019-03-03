#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n, a,b, ans = 0;
        scanf("%d", &n);
        scanf("%d", &a);
        if(a <= 2) ans = 0;
        else ans = (a-2 + 4) / 5;
        for(int i=1; i<n; i++) {
            scanf("%d", &b);
            if(b > a) ans += (b-a + 4) / 5;
            a = b;
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;

}
