#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m, ans = 0;
    cin >> n >> m;

    while( n && m && (n >= 2 || m >= 2) ) {
        if(n > m) {
            n -= 2; m--;
            ans++;
        }
        else {
            n--; m -= 2;
            ans++;
        }
    }

    cout << ans << endl;
}
