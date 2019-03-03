#include<bits/stdc++.h>
#define MAX 2000000000
#define ll long long int

using namespace std;

ll fib[100];
int n,m;

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);

    fib[0] = 1; fib[1] = 2;
    for(m=2; ; m++) {
        fib[m] = fib[m-1] + fib[m-2];
        if(fib[m] > MAX) break;
    }

    int T;
    scanf("%d", &T); //cout << T << endl;
    for(int t=1; t<=T; t++) {
        ll x, ans = 1;
        scanf("%d", &n);
//        cout << n << endl;
        while(n--) {
            scanf("%lld", &x);
            ll cnt = 0;
            while(x) {
                int p = upper_bound(fib, fib+m, x) - fib;
                p--;
//                cout << x << ' ' << p << ' ' << fib[p] << endl; getchar();
                cnt++;
                x -= fib[p];
            }
            ans *= cnt;
//            cout << "DONE " << endl;
        }
        printf("Case %d: %lld\n", t, ans);
    }
}
