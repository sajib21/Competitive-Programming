#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll ans = 0;
ll ann = 0;
bool f(ll a, ll b) {
    if(!a && !b) return false;
    bool ret = f(a/2, b/2);

    if(ret) {
        ans = ans*2 + 1;
        return true;
    }

    if(a%2 != b%2) {
        ans = ans*2 + 1;
        return true;
    }

    ans = ans*2 + (a%2);
    return false;
}

bool g(ll a, ll b) {
    if(!a && !b) return false;
    bool ret = g(a/2, b/2);

    if(ret) {
        ann = 2*ann;
        return true;
    }

    if(a%2 != b%2) {
        ann = ann*2;
        return true;
    }

    ann = ann*2 + (a%2);
    return false;

//    ll c = (a+b)/2;
}

int main() {
//    f(1,2);
//    cout << ans << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        ll a,b;
        scanf("%lld %lld", &a, &b);
//        cout << "TEST " << a << ' ' << b << endl;
        ans = 0;
        f(a,b);
//        cout << ans << endl;
        ann = 0;
        g(a,b);

        printf("Case %d: %lld %lld\n", t, ans, ann);
    }
}
