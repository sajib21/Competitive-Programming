#include<bits/stdc++.h>

using namespace std;

int n,k,x, cnt[3][1030], p;

int main() {
    scanf("%d %d %d", &n, &k, &x);
    for(int i=0; i<n; i++) {
        scanf("%d", &p);
        cnt[0][p]++;
    }

    for(int i=1; i<=k; i++) {
//        cout << "BUG" << endl;

        int in = i&1;
        memset(cnt[in], 0, sizeof cnt[in]);

        int t = 0;
        for(int j=0; j<1024; j++) {
//            if((j^x) >= 2050) {
////                cout << "PAISI " << j << ' ' << (j^x) << endl;
//            }
            assert( (j^x) < 1024);
            if(cnt[!in][j]%2==0) {
                cnt[in][j^x] += cnt[!in][j]/2;
                cnt[!in][j] /= 2;
            }
            else {
                if(t==0) {
                    cnt[in][j^x] += (cnt[!in][j]+1)/2;
                    cnt[!in][j] /= 2;
                    t = !t;
                }
                else {
                    cnt[in][j^x] += cnt[!in][j]/2;
                    cnt[!in][j] /= 2; cnt[!in][j]++;
                    t = !t;
                }
            }
//            cnt[in][j] cnt[!in][j]
        }

        for(int j=0; j<1024; j++) cnt[in][j] += cnt[!in][j];

//        for(int j=0; j<=20; j++) cout << cnt[i&1][j] << ' ';
//        cout << endl;
    }

    int mn = 10000, mx=-1;
    for(int i=0; i<1024; i++) if(cnt[n&1][i]) {
        mn = min(mn, i);
        mx = max(mx, i);
    }
    cout << mx << ' ' << mn << endl;
}
