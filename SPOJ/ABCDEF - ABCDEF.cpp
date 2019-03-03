#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define ll long long int

using namespace std;

int n, a[110];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    vi u,v;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                u.pb(a[i]*a[j]+a[k]);
            }
        }
    }
    for(int i=0; i<n; i++) if(a[i]) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                v.pb(a[i]*(a[j]+a[k]) );
            }
        }
    }

    sort(u.begin(), u.end());
    sort(v.begin(), v.end());

    ll ans = 0;

    for(int i=0; i<u.size(); i++) {
        ans += upper_bound(v.begin(), v.end(), u[i]) - lower_bound(v.begin(), v.end(), u[i]);
    }
    printf("%lld\n", ans);

}
