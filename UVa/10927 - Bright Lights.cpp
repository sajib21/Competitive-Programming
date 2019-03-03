#include<bits/stdc++.h>
#define ll long long int
#define LIM 100005
#define sqr(x) ( (x) * (x) )
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

struct info{
    ll x,y,z;
    int in;
    bool vis;
    info() {}
    info(ll xx, ll yy, ll zz, int i) {
        x = xx; y = yy; z = zz; in = i;
    }
    ll dist() {
        return sqr(x) + sqr(y);
    }
    bool operator < (info &b) {
        return dist() < b.dist();
    }
};

bool cmp(info a, info b) {
    return (a.x == b.x && a.y < b.y) || a.x < b.x;
}

int n;
info pts[LIM];

int main() {
//    freopen("10927i.txt", "r", stdin);
//    freopen("10927o.txt", "w", stdout);
//    cout << __gcd(4, 0) << endl;
    int t = 1;
    while(scanf("%d", &n)) {
        if(!n) return 0;
        memset(pts, 0, sizeof pts);
        for(int i=0; i<n; i++) scanf("%lld %lld %lld", &pts[i].x, &pts[i].y, &pts[i].z);
        sort(pts, pts+n);

        int ans = 0;
        map<pll,ll>lastZ;
        for(int i=0; i<n; i++) {
            ll x = pts[i].x, y = pts[i].y, z = pts[i].z;
            int in = pts[i].in;
            ll g = __gcd( abs(x), abs(y) );
            x /= g; y /= g;
            if(lastZ.find(pll(x,y)) == lastZ.end() || lastZ[pll(x,y)] < z) {
                lastZ[pll(x,y)] = z;
                ans++;
                pts[i].vis = 1;
            }
        }

        printf("Data set %d:\n", t++);
        if(ans == n) {
            printf("All the lights are visible.\n");
        }
        else {
            printf("Some lights are not visible:\n");
            sort(pts, pts+n, cmp);
            bool f = false;
            for(int i=0; i<n; i++) {
                if(pts[i].vis) continue;
                if(f) printf(";\n");
                f = true;
                printf("x = %lld, y = %lld", pts[i].x, pts[i].y);
            }
            printf(".\n");
        }
    }
}
