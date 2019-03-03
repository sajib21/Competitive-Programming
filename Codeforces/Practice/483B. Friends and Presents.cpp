#include<bits/stdc++.h>
#define ll long long int

using namespace std;


int main() {

    ll cnt1,cnt2, x,y;
    cin >> cnt1 >> cnt2 >> x >> y;

    ll lo = 0, hi = 1e18, mid;

    while(lo < hi ) {
        mid = (lo+hi)/2;

        ll _x = mid/x;
        ll _y = mid/y;
        ll _xy = mid/(x*y);

        ll xCanTake = _y - _xy;
        ll yCanTake = _x - _xy;
        ll bothCanTake = mid - xCanTake - yCanTake - _xy;

        ll xLeft = max(0ll, cnt1 - xCanTake);
        ll yLeft = max(0ll, cnt2 - yCanTake);

        if(xLeft + yLeft <= bothCanTake) hi = mid;
        else lo = mid + 1;
    }

    cout << hi << endl;

    return 0;
}
