#include<bits/stdc++.h>
#define ll long long int
#define MX 100005

using namespace std;
ll n, l,r, q1,q2, w[MX] = {0};
ll suml[MX] = {0}, sumr[MX] = {0};

void fast() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


int main() {

    fast();



    cin >> n >> l >> r >> q1 >> q2;
    for(int i=1; i<=n; i++) cin >> w[i];

    for(int i=1; i<=n; i++) suml[i] = suml[i-1] + w[i];
//    for(int i=1; i<=n; i++) cout << suml[i] << endl;
    for(int i=n; i>0; i--) sumr[i] = sumr[i+1] + w[i];
//    for(int i=n; i>0; i--) cout << sumr[i] << endl;

    ll ans = LONG_LONG_MAX, temp = 0;
    for(int i=0; i<=n; i++) {
        temp = suml[i]*l + sumr[i+1]*r;
//        cout << temp << ' ';

        if(i < n-i) temp += (n-2*i-1)*q2;
        else if(i > n-i) temp += (2*i-n-1)*q1;
        ans = min(ans, temp);
//        cout << temp << endl;
    }

    cout << ans << endl;

    return 0;

}
