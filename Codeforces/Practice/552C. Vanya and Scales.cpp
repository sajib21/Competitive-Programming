#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define pb(x) push_back(x)

using namespace std;

int main() {
    ll w,m, a[70] = {0};
    cin >> w >> m;

    int in=0;
    while(m) {
        a[in++] = m%w;
        m /= w;
    }

    for(int i=0; i<=in; i++) {
//        cout << i << ' ' << a[i] << endl;
        if(a[i] < 2) continue;
        if(a[i] == w-1 || a[i] == w) {
            a[i+1]++;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
