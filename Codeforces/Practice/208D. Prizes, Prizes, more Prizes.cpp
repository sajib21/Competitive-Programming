#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll n, point[53], prize[7];
    scanf("%I64d", &n);
    for(int i=0; i<n; i++) scanf("%I64d", &point[i]);
    for(int i=0; i<5; i++) scanf("%I64d", &prize[i]);

    //cout << "bug" << endl;

    ll ans[7] = {0}, left = 0;

    for(int i=0; i<n; i++) {

        left += point[i];

        for(int j=4; j>=0; j--) {
            if(left >= prize[j]) {
                ans[j] += left/prize[j];
                left %= prize[j];
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << endl;
    cout << left << endl;

    return 0;
}
