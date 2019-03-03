#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int n, a, m;
        ll maxx = 0, res = INT_MAX;
        ll lsum[1010], rsum[1010], num[1010];
        scanf("%d %d", &n,&m);
        lsum[0] = rsum[n+1] = 0;

        for(int i=1; i<=n; i++) {
            scanf("%d", &num[i]);
            maxx = max(maxx, num[i]);
        }
        for(int i=1; i<=n; i++) lsum[i] = lsum[i-1] + num[i];

        if(n <= m) {
            printf("Case %d: %d\n", t, maxx);
            continue;
        }

        for(int i=1; i<=n-2; i++) {
            ll a,b,c,x, lo,hi;
            a = lsum[i];
            x = (lsum[n] - lsum[i]) / 2;
            lo = i+1;
            hi = n;

            while(lo < hi) {

                int md = (lo+hi) / 2;
                cout << "IN " << lo << ' ' << md << ' ' << hi << endl;
                if(lsum[md] - lsum[i] < x) lo = md;
                else hi = md;

                if(lo+1 == hi) break;
            }
            b = lsum[hi] - lsum[i];
            c = lsum[n] - lsum[hi];
            res = min(res, max(a, max(b,c)) ); cout << a << ' ' << b << ' ' << c << endl;

            b = lsum[hi-1] - lsum[i];
            c = lsum[n] - lsum[hi-1];
            res = min(res, max(a, max(b,c)) ); cout << a << ' ' << b << ' ' << c << endl;
        }

        printf("Case %d: %lld\n", t, res);
    }

    return 9;

}
