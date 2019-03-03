#include<bits/stdc++.h>
#define LIM 303
#define ll long long int

using namespace std;

int n;
ll x,y, X,Y;
ll a, b, c;

int f(ll x, ll y) {
    ll v = a*x + b*y + c;
    if(v > 0) return 1;
    return -1;
}

int main() {
    scanf("%lld %lld", &x,&y);
    scanf("%lld %lld", &X,&Y);
    scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if(f(x,y) != f(X,Y)) ans++;
    }
    printf("%d", ans);
}
