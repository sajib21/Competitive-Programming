#include<bits/stdc++.h>
#define ll long long int
#define sqr(x) ( (x) * (x) )

using namespace std;

ll n;

int main() {
    scanf("%lld", &n);

    ll ans = sqr( n*(n-1)*(n-2)*(n-3)*(n-4) / (5*4*3*2*1) ) * (5*4*3*2*1);

    printf("%lld\n", ans );

}
