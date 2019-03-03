#include<bits/stdc++.h>
#define LIM 50000
#define pii pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

int n;
vector<pii>pv;

int main() {

    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++) {
        scanf("%d", &n);
        pv.clear();
        for(int i=0; i<n; i++) {
            int s,t;
            scanf("%d %d", &s,&t);
            pv.pb(mp(s, -1));
            pv.pb(mp(t, 1));
        }
        sort(pv.begin(), pv.end());

        int cnt = 0, tc = 0;
        for(int i=0; i<2*n; i++ ) {
//            cout << pv[i].second << endl;
            tc += pv[i].second;
            cnt = min(cnt, tc);
        }

        printf("Case %d: %d\n", tt, -cnt);
    }
    return 0;

}
