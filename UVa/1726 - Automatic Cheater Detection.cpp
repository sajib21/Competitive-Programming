#include<bits/stdc++.h>

using namespace std;

struct info{
    int x,y,z; /// x = difficulty, y = leaked, z = solved
    info() {}
    info(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        return (x == b.x && y > b.y) || x < b.x;
    }
};

int n;
info mcq[50004];

int main() {
//    freopen("o.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            char c;
            scanf("%d %d %c", &mcq[i].x, &mcq[i].y, &c);
            if(c == 'c') mcq[i].z = 1;
            else mcq[i].z = 0;
        }
        sort(mcq, mcq+n);
//        cout << "DATA" << endl;
//        for(int i=0; i<n; i++) cout << ' ' << mcq[i].x << ' ' << mcq[i].y << ' ' << mcq[i].z << endl;


        long long  ans = 0;
        long long  li = 0;

        for(int i=0; i<n; i++) {
            if(mcq[i].y) {
                if(mcq[i].z) ans += li;
            }
            else {
                if(!mcq[i].z) li++;
            }
//            cout << i << ' ' << li << ' ' << ans << endl;
        }
        printf("%lld\n", ans);
    }
}
