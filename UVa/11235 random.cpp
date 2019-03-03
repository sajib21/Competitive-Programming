#include<bits/stdc++.h>
#define MOD 10000000000LL

using namespace std;

int main() {

    freopen("11235i.txt", "w", stdout);

    int n = 500;
    cout << n << endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ", rand() % MOD);
        }
        cout << endl;
    }

    int q = 50000;
    cout << q << endl;
    for(int i=0; i<q; i++) {
        int a,b, c,d;
        int p,q,r,s;
        a = rand() % n + 1, b = rand() % n + 1, c = rand() % n + 1, d = rand() % n + 1;
        p = min(a,c); r = max(a,c);
        q = min(b,d); s = max(b,d);
        cout << 'q' << ' ' << p << ' ' << q << ' ' << r << ' ' << s << endl;
    }

}
