#include<bits/stdc++.h>
#define LIM 100005
#define MAX 100000

using namespace std;

int n, a[LIM], L[LIM];

int LIS() {
    memset(L, 127, sizeof L);

    int ans = 0;
    for(int i=1; i<=n; i++) {
        int x = lower_bound(L+1, L+MAX+1, a[i]) - L;
        ans = max(ans, x);
        L[x] = min(L[x], a[i]);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    cout << LIS() << endl;
}
