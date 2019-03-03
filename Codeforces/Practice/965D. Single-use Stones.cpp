#include<bits/stdc++.h>

using namespace std;

int n,w, a[100005];

int main() {
    scanf("%d %d", &w, &n);
    for(int i=1; i<w; i++) scanf("%d", &a[i]);

    int sum = 0;
    for(int i=1; i<=n; i++) sum += a[i];
    int ans = sum;
    for(int i=n+1; i<w; i++) {
//        if(a[i] < a[i-n])
            sum = sum - a[i-n] + a[i];
//        else a[i] = a[i-n];
        ans = min(ans, sum);
    }

    cout << ans << endl;
}
