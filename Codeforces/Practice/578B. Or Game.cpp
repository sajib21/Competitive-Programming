#include<bits/stdc++.h>
#define LIM 200005
#define ll long long int

using namespace std;

int n,k,x;
ll a[LIM], b[LIM], c[LIM];

int main() {
    scanf("%d %d %d", &n, &k,&x);

    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=n; i++) b[i] = b[i-1] | a[i];
    for(int i=n; i>=0; i--) c[i] = c[i+1] | a[i];

    ll ans = 0;
    ll mul = 1;
    for(int i=0; i<k; i++) mul *= x;
    for(int i=1; i<=n; i++) {
        ans = max(ans, b[i-1] | (a[i]*mul) | c[i+1] );
    }

    cout << ans << endl;
}
