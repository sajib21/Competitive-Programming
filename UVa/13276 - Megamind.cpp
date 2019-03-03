#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {
//    freopen("o.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        ll e,p,k,r;
        scanf("%lld %lld %lld %lld", &e,&p,&k,&r);


        if(e <= p*k) {
            printf("Case %d: %lld\n", t, (e+p-1)/p );
            continue;
        }

//        ll ans = k;
        e -= p*k;

        ll rnd = p*k - r;

        if(rnd <= 0) {
            printf("Case %d: -1\n", t);
            continue;
        }

        ll div = (e+rnd-1)/rnd;
        ll mod = e-div*rnd;
        ll ans = div*k;

        if(!mod) {
            ans += k;
        }
        else {
            e = mod+p*k;
//            div = e/rnd;
//            mod = e%rnd;
//            ans += div*k;
//            if(mod <= r) {
//    //            ans--;
//            }
//            else {
                ans += (e+p-1)/p;
//            }
        }
        printf("Case %d: %lld\n", t, ans);
    }
}
