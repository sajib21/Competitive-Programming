#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;



int n,m, a[40];
vi u,v;

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &a[i]), a[i] %= m;

//    for(int i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

    for(int mask=0; mask < (1 << (n/2)); mask++) {
        int sum = 0;
        for(int i=0; i<n/2; i++) if(mask & (1 << i)) {
            sum += a[i];
            sum %= m;
        }
        u.pb(sum);
    }

    for(int mask=0; mask < (1 << ((n+1)/2)); mask++) {
        int sum = 0;
        for(int i=0; i<(n+1)/2; i++) if(mask & (1 << i)) {
            sum += a[n/2+i];
            sum %= m;
        }
        v.pb(sum);
    }

    sort(u.begin(), u.end()); u.erase(unique(u.begin(), u.end()), u.end());
    sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());

//    for(int i=0; i<u.size(); i++) cout << u[i] << ' '; cout << endl;
//    for(int i=0; i<v.size(); i++) cout << v[i] << ' '; cout << endl;

    int ans = 0;
    for(int i=0; i<u.size(); i++) {
        int x = u[i];
        int y = m-u[i];
        int j = lower_bound(v.begin(), v.end(), y) - v.begin() - 1;
        y = v[j];
        ans = max(ans, x+y);
    }

    cout << ans << endl;
}
