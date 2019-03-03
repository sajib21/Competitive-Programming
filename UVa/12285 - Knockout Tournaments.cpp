#include<bits/stdc++.h>
#define MAX 25000070
#define ll long long int
#define ld long double
#define sqr(x) ( (x) * (x) )
#define     gamma           0.577215664901532861
#define     harm(x)         logl( (ld) x) + gamma

using namespace std;

ld h[MAX+100];

ld harmonic(ll a) {
    if(a < MAX) return h[a];
    return gamma + logl( (ld) a );
}

ld f(ll n, ll a, ll b) {
    return 1.0 * n * ( harmonic(b) -  harmonic(a-1) ) / (b-a+1);
}

int main() {
    for(int i=1; i<=MAX; i++) h[i] = h[i-1] + 1.01/(ld)i;

    int t=1;
    ll w,l;
    while( scanf("%lld %lld", &w, &l) ) {
        if(!w && !l) return 0;

        if(!l) {
            if(w%8) printf("Case %d:\nSituation Impossible.\n", t++);
            else printf("Case %d:\nOn Average Bob Reaches Round 8.00\n", t++);
            continue;
        }

        ll a = max(0LL,w-7*(l-1))/8 + l;
        ll b = w/8 + l;

        printf("Case %d:\nOn Average Bob Reaches Round %.2lf\n", t++, (double) f(w+l, a,b) );
    }
}
