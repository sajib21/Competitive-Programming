#include<bits/stdc++.h>
#define pb push_back
#define ull unsigned long long int

using namespace std;

int n,m;
vector<int>graph[15];
ull dp[15][15][8200][3];
int par[15];

ull setBit(ull n, int pos) { return n | (1 << pos); }
ull chkBit(ull n, int pos) { return n & (1 << pos); }

ull getDumb(int st, int last, ull mask, int cnt) {

//    cout << "NOW AT " << st << ' ' << last << ' ' << par[last] << ' ' << mask << ' ' << cnt << endl;

    if(cnt == 2) return 1;
//    if(mask == (1 << n) - 1) return 0;

    if(dp[st][last][mask][cnt] != -1) return dp[st][last][mask][cnt];

    double ans = 0;
    int sz = graph[last].size();
    for(int i=0; i<sz; i++) {
        int v = graph[last][i];

        if(v == st && par[last] != v) {
//                cout << "DHUKE " << st << ' ' << last << ' ' << par[last] << ' ' << v << ' ' << cnt << endl;
            ans += getDumb(st, v, mask, cnt+1);
        }
        else if(!chkBit(mask, v)) {
            int pre = par[v];
            par[v] = last;
            ans += getDumb(st, v, setBit(mask, v), cnt );
            par[v] = pre;
        }
    }
//    cout << "RETURNING FROM " << st << ' ' << last << ' ' << cnt << " WHITH " << ans << endl;
    return dp[st][last][mask][cnt] = ans;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++) {

//        if(t == 47) cout << "************************************************************" << endl;

        for(int i=0; i<=13; i++) graph[i].clear();
//        for(int i=0; i<=13; i++) par[i] = 14;
        memset(dp, -1, sizeof(dp));
        memset(par, -1, sizeof(par));


        scanf("%d %d", &n,&m);
        if(t == 47) cout << n << ' ' << m << endl;

        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            graph[u].pb(v);
            graph[v].pb(u);

//            if(t == 47) cout << u << ' ' << v << endl;

        }

//        if(t == 47) cout << "************************************************************" << endl;

        ull ans = 0;
        for(int i=0; i<n; i++) {
            ans += ( getDumb(i, i, (1 << i) , 0) + 7 ) / 8;
//            cout << "AT " << i << " RETURNED " << ans << endl;
        }
        printf("Case %d: %llu\n", t, ans);
    }
    return 0;

}
