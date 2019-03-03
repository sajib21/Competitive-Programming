#include<bits/stdc++.h>
#define ll long long int

using namespace std;

//long double bigMod1(ll n, ll r) {
//    if(!n) return 0.0;
//    if(!r) return 1.0;
//    long double ans;
//    if(r%2) {
//        ans = 1.0 * (1.0*bigMod1(n, r-1)*n) ;
//        while(ans > 999.0) ans /= 10.0;
//        return ans;
//    }
//    ans = bigMod1(n, r/2);
//    ans *= ans;
//    while(ans > 999.0) ans /= 10.0;
//    return ans ;
//}

ll bigMod(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1)*n) % 1000;
    ll ans = bigMod(n, r/2);
    return (ans*ans) % 1000;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n,k;
        scanf("%d %d", &n,&k);

        long double dn = n; n = n % 1000;
        int tail = 1;
		long double c = k * log10(dn);
		c = c - floor(c);
		int head = (int)pow((long double)10.0, 2 + c);

//        int a = floor(bigMod1(n, k));
        printf("Case %d: %d %03lld\n",t, head, bigMod(n,k));
    }
    return 0;
}
