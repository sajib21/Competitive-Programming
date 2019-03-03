#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int n, a, m;
ll maxx = 0, res = INT_MAX;
ll lsum[1010], rsum[1010], num[1010];

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        maxx = 0;


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

        ll lo = maxx , hi = lsum[n];
        bool flag = false;

        while(lo < hi) {

//            cout << lo << ' ' << hi << endl;

            ll md = (lo+hi)/2;
            ll pre = 0;

//            cout << md << endl;

            int cnt = 0;
            while(pre < n) {
                int lol = pre+1, hil = n;
                bool fl = false;

                while(lol < hil) {

                    if(lsum[hil]-lsum[pre] <= md) {
//                        cnt++;
                        lol = hil;
                        break;
                    }

                    int mid = (lol+hil)/2;
                    if(lsum[mid] - lsum[pre] <= md) lol = mid;
                    else hil = mid;

                    if(lol+1 == hil) {
                        if(fl == true) {
                            break;

                        }
                        fl = true;
                    }
                }
                cnt++;
                pre = lol;
            }
            if(cnt <= m) hi = md;
            else if(cnt > m) lo = md;

            if(lo+1 == hi) {
                if(flag == true) break;
                flag = true;
            }
        }
        printf("Case %d: %lld\n", t, hi);
    }

    return 0;

}
