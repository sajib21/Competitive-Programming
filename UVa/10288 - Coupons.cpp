#include<bits/stdc++.h>
#define ll long long int

using namespace std;

struct info{
    ll x,y,z;
    info() {x = 0; y = 0; z = 1;}
    info(ll xx, ll yy, ll zz) {x = xx; y = yy; z = zz;}
    info operator + (const info &b) const {
        info ans;
        ans.x = x + b.x;
        ll g = __gcd(z, b.z);
        ll l = z*b.z / g;
        ans.z = l;
        ans.y = l/z*y + l/b.z*b.y;
        if(ans.y >= ans.z) {
            ans.x += ans.y / ans.z;
            ans.y %= ans.z;
        }
        g = __gcd(ans.y, ans.z);
        if(g > 1) {
            ans.y /= g;
            ans.z /= g;
        }
        return ans;
    }

    void print() {
        if(y == 0) printf("%lld\n", x);
        else {
            ll temp = x;
            while(temp) {
                printf(" ");
                temp /= 10;
            }
            printf(" %lld\n", y);
            printf("%lld ", x);
            temp = z;
            while(temp) {
                printf("-");
                temp /= 10;
            }
            printf("\n");
            temp = x;
            while(temp) {
                printf(" ");
                temp /= 10;
            }
            printf(" %lld\n", z);
        }
    }
};

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        info ans;
        for(int i=0; i<n; i++) ans = (ans + (info(0, n, n-i)));
        ans.print();
    }
}
