#include<bits/stdc++.h>
#define ll long long int
#define MX 1000000000

using namespace std;

ll power(ll sum, ll po) {

    ll ans = 1;
    while(po--) ans *= sum;
    return ans;
}

int main() {

    ll a,b,c;
    cin >> a >> b >> c;
    vector<ll> sol;

    for(int sum = 1; sum <=81; sum++) {

        ll x = b * power(sum, a) + c;
        ll temp1 = x, temp2 = 0;
        while(temp1) {
            temp2 += temp1 % 10;
            temp1 /= 10;
        }
        if(temp2 == sum && x < 1000000000) sol.push_back(x);
    }

    sort(sol.begin(), sol.end());

    ll sz = sol.size();
    cout << sz << endl;
    if(sz) {
        cout << sol[0] ;
        for(int i=1; i<sz; i++) cout << ' ' << sol[i] ;
        cout << endl;
    }

    return 0;
}
