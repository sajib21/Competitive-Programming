#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, x, mx = INT_MIN;
    long long int tot = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        tot += x;
        mx = max(mx, x);
    }


    long long int ans = (tot+n-2)/(n-1);

    //cout << ans << ' ' << mx << endl;

    if(ans > mx) printf("%I64d\n", ans);
    else printf("%d\n", mx);

    return 0;

}
