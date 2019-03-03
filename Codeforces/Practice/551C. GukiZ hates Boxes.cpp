#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int

using namespace std;

int n, N, m, p[LIM], t[LIM];
ll mx;

bool f(ll tim) {
    if(tim < n) return false;
    int cnt = 0;
    ll x = 0;
    for(int i=1; i<=n; i++) t[i] = p[i];

//    cout << "TESTING " << tim << endl;

    for(int i=1; i<=n; ) {

        if(x <= 0) {
            cnt++;
            x = tim-i;
            if(x <= 0) return false;
        }
//        cout << i << ' ' << t[i] << ' ' << x << ' ' << cnt << endl; getchar();
        if(t[i] > x) {
            t[i] -= x;
            x = 0;
        }
        else {
            x -= t[i];
            t[i] = 0;
            i++;
            x--;
        }
    }
    return cnt <= m;
}

int main() {
    scanf("%d %d", &N,&m);
    for(int i=1; i<=N; i++) {
        scanf("%d", &p[i]);
        mx += p[i];
        if(p[i]) n = i;
    }

    ll lo = 1, hi = mx + n+10000000;

    while(lo < hi) {
        ll md = (lo+hi) / 2;
//        cout << "FOR " << lo << ' ' << hi << ' ' << md << endl; getchar();
        if(f(md)) hi = md;
        else lo = md+1;
    }

    cout << hi << endl;
}
