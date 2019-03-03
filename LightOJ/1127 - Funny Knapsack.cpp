#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 30
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define vll vector<ll>

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
}

int BS(int val) {
    int lo = 0, hi = rs;
    bool flag = false;
    while(lo < hi) {
        int md = (lo+hi) >> 1;

        if(val+vrc[md] <= w) lo = md;
        else hi = md;

        if(lo + 1 == hi) break;
    }
    return lo+1;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        L.clear(); R.clear();
        vlc.clear(); vrc.clear();

        scanf("%d %d", &n,&w);
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
//        cout << ls << ' ' << rs << endl;

//        for(int i=0; i<ls; i++) cout << vlc[i] << ' '; cout << endl;
//        for(int i=0; i<rs; i++) cout << vrc[i] << ' '; cout << endl;

        ll ans = 0;
        for(int i=0; i<ls; i++) {
            if(vlc[i] > w) break;
//            if(!rs || L[i]+R[0] > w) ans++;
            ans += BS(vlc[i]);
//            cout << "NOW AT " << i << ' ' << vlc[i] << ' ' << ans << endl;
        }
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
