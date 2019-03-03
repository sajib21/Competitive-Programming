#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define LIM 30000
#define MAX 1000000000
#define pb push_back
using namespace std;

int n,w, ls, rs;
vll L,R, vlc, vrc;

void genComb(vll vin, vll &vout, int in, ll sum) {
    if(in == vin.size()) {
        vout.pb(sum);
        return;
    }
    genComb(vin, vout, in+1, sum);
    genComb(vin, vout, in+1, sum+vin[in]);
    genComb(vin, vout, in+1, sum+2*vin[in]);
}

bool BS(int val) {
    int lo = 0, hi = rs;
    bool flag = false;
    while(lo < hi) {
        int md = (lo+hi) >> 1;

//        cout << "IN BS " << lo << ' ' << md << ' ' << hi << endl;
//        cout << val+vrc[md] << endl;
        if(val+vrc[md] == w) return true;
        if(val+vrc[md] < w) lo = md;
        else hi = md;

        if(lo + 1 == hi) {
            if(flag) break;
            flag = true;
        }
    }
    return false;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        L.clear(); R.clear();
        vlc.clear(); vrc.clear();
//        cnt1 = cnt2 = 0;
//        memset(comb, 0, sizeof(comb));
        scanf("%d %d", &n, &w);
        for(int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            if(i&1) R.pb(x);
            else L.pb(x);
        }

        genComb(L, vlc, 0, 0);
        genComb(R, vrc, 0, 0);

        sort(vrc.begin(), vrc.end());
        sort(vlc.begin(), vlc.end());
        ls = vlc.size();
        rs = vrc.size();

//        cout << cnt1 << ' ' << cnt2 << endl;
//        for(int i=0; i<10; i++) cout << comb1[i] << ' ' ; cout << endl;
//        for(int i=0; i<10; i++) cout << comb2[i] << ' ' ; cout << endl;

        bool ans = false;
        for(int i=0; i<ls; i++) {
            if(vlc[i] > w) break;
//            if(!rs || L[i]+R[0] > w) ans++;
            if(BS(vlc[i])) {
                ans = true;
                break;
            }
//            cout << "NOW AT " << i << ' ' << vlc[i] << ' ' << ans << endl;
        }
//        printf("Case %d: %lld\n", t, ans);
        if(ans) printf("Case %d: Yes\n", t);
        else printf("Case %d: No\n", t);

    }
    return 0;
}
