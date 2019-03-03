#include<bits/stdc++.h>

using namespace std;

int main() {

    freopen("12716ac.txt", "w", stdout);

    int n;
    while( (cin >> n) && n ) {
        cout << "DEBUG " << n << endl;
        int cnt  = 0;
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                if(__gcd(i,j) == (i^j)) {
                    cout << (i^j) << ' ' << i << ' ' << j << endl;
                    cnt++;
                }
            }
        }
        cout << "OUTPUT : " << cnt << endl;
    }
}
