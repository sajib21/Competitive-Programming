#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

int n, a[LIM], dp[LIM];

int f(int in) {
//    cout << "IN " << in << endl; getchar();
    if(dp[in] != -1) return dp[in];

    int ans = 0;
    for(int i=in+a[in]; i<n; i+=a[in]) {
        if(a[i] > a[in]) ans |= !f(i);
    }
    for(int i=in-a[in]; i>=0; i-=a[in]) {
        if(a[i] > a[in]) ans |= !f(i);
    }
//    cout << "OUT " << in << ' ' << ans << endl;
    return dp[in] = ans;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);

//    cout << f(0) << endl;

    for(int i=0; i<n; i++) {
        if(f(i)) printf("A");
        else printf("B");
    }
}
