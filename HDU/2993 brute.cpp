#include<bits/stdc++.h>

using namespace std;

int n,k, a[10010], s[10010];

int main() {
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) s[i] = s[i-1] + a[i];

    double ans = 0;
    int p,q;
    for(int i=0; i<=n; i++) {
        for(int j=i+k; j<=n; j++) {
            double temp = 1.0 * (s[j]-s[i]) / (j-i);
            if(temp > ans) {
                ans = temp;
                p = i; q = j;
            }
        }
    }
    cout << p << ' ' << q << ' ' << ans << endl;
}
