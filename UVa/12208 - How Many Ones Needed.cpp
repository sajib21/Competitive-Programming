#include<bits/stdc++.h>
#define SZ 32
#define bit bitset<SZ>
#define ll unsigned long long int

using namespace std;

ll a,b, ex[40];

ll f(int p) {
    bit n = p;
    ll ans = 0;
//    cout << "START " << p << ' ' << n << endl;
    for(int i=SZ-1; i>=0; i--) {
        if(n[i]) {
            ans += i*ex[i]/2;
//            cout << "F " << i*ex[i]/2 << endl;
            p -= ex[i];
            ans += p+1;
//            cout << "S " << p+1 << endl;
        }
//        cout << i << ' ' << ans << endl;
    }
    return ans;
}

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);

    ex[0] = 1; for(int i=1; i<32; i++) ex[i] = ex[i-1]*2;
    int t = 1;
    while( scanf("%llu %llu", &a, &b) ) {
        if(!a && !b) return 0;
        if(a) a--;

        printf("Case %d: %llu\n", t++, f(b) - f(a) );



    }
}
