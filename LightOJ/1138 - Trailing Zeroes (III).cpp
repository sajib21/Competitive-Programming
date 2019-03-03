#include<bits/stdc++.h>
#define ll long long int
#define LIM 400000100LL
using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int n;
        scanf("%d", &n);

        ll lo = 1 , hi = LIM, zrs, ans = -1;
        while(lo < hi) {
            int mid = (lo+hi)/2;

//            cout << lo << ' ' << mid << ' ' << hi << endl;

            zrs = 0;
            ll div = 5, temp = mid;
            while(mid >= div) {
                zrs += temp / div;
                div *= 5;
            }

//            cout << zrs << endl;

            if(zrs < n) lo = mid;
            else {
                hi = mid;
                if(zrs == n) ans = hi;
            }

            if(lo+1 == hi) break;
        }

        if(ans == -1) printf("Case %d: impossible\n", t);
        else printf("Case %d: %lld\n", t, ans);
    }
//    int cnt = 0, i;
//    for(i=5; cnt < 100000000LL; i+=5) {
//        ll tmp = i;
//        while(tmp%5==0) {
//            cnt++;
//            tmp/=5;
//        }
//
//    }
//
//    cout << i << " : " << cnt << endl;

    return 0;
}
