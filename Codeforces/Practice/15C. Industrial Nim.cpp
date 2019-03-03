#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll f(ll x) {
    x++;
    ll div = 1;
    ll xr = 0;

    while(div <= x) {
        div *= 2;
        ll d = x / div;
        ll m = x % div;
        ll c = d*(div/2);
        if(m > div/2) c += m-div/2;

        xr ^= (c%2) * (div/2);
//        cout << c << ' ' << div << endl;

//        div *= 2;
    }
    return xr;
}

int main() {
//    cout << f(8) << endl;

    ll n,x,y,m, XOR = 0;
    scanf("%lld", &n);
    while(n--) {
        scanf("%lld %lld", &x,&m);
        y = x+m-1;
        x--;
        XOR ^= f(y) ^ f(x);
    }
    if(XOR) cout << "tolik" << endl;
    else cout << "bolik" << endl;
}
