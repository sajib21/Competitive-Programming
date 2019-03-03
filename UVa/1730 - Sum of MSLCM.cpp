#include<bits/stdc++.h>
#define LIM 4500
#define vi vector<int>
#define pb(x) push_back(x)
#define ll long long int

using namespace std;

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);
    int n;
    while(scanf("%d", &n) && n) {
        ll sq = sqrt(n);
        ll ans = n;
        ll last = n;
        for(int i=2; i<=sq; i++) {
            ll j = n/i;
            ans += i*j;
            ans += ( last*(last+1)/2 - j*(j+1)/2 ) * (i-1);
            last = j;
        }
        if(sq < last) {
            ans += ( last*(last+1)/2 - sq*(sq+1)/2 ) * sq;
        }
        printf("%lld\n", ans-1);
    }
}
