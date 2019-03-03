#include<bits/stdc++.h>
#define ll long long int

using namespace std;

struct info{
    ll p,q;
    info() {}
    info(ll xx) {
        p = xx; q = 1;
    }
    info(ll xx, ll yy) {
        ll g = __gcd(xx,yy);
        p = xx/g; q = yy/g;
    }
    info operator + (const info &b) const {
        ll g = __gcd(q, b.q);
        ll mul = q*b.q;
        ll x = mul/g;
        ll y = (x/q*p) + (x/b.q*b.p);
        return info(y, x);
    }
    info operator - (const info &b) const {
        ll g = __gcd(q, b.q);
        ll mul = q*b.q;
        ll x = mul/g;
        ll y = (x/q*p) - (x/b.q*b.p);
        return info(y, x);
    }
    info operator * (const info &b) const {
        ll y = p*b.p;
        ll x = q*b.q;
        return info(y, x);
    }
};

info f(ll n) {
    if(n == 1) return info(1LL);
    if(n == 2) return info(1,2);
//    return info(1.0, n) + info(n-1, n)*info(1, n-1) + info(n-1, n)*info(n-1-1, n-1)*f(n-1);
    return info(1.0, n) + info(n-2, n)*f(n-1);
}

int main() {
    ll n;
    while(scanf("%lld", &n) ) {
        if(!n) return 0;
        printf("1/2\n");
        continue;

        info ans = f(n);
        ans = info(1) - ans;
        printf("%lld/%lld\n", ans.p, ans.q );
    }

}
