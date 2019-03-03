#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define MOD 1000000007LL


#define INF INT_MAX
#define EPS 1e-9
#define LIM 100

using namespace std;

int n,m,k;
ll go[LIM+10][LIM+10];
vector< vector<ll> > co;

ll bigMod(ll p,ll e,ll M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;} return ret;}

ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

ll gauss (vector < vector<ll> > a) {
    int n = (int) a.size();
    int m = (int) a[0].size();

    int row, col;
    for (col=0, row=0; col<m-1 && row<n; ++col) {
        int sel = row;
        for (int i=sel; i<n; ++i) if(a[i][col]) { sel = i; break;}
        if (a[sel][col] == 0) continue;
        if(sel != row) swap (a[sel], a[row]);

        ll mi = (modInverse(a[row][col], k));
        for(int i=0; i<m; i++) a[row][i] = (a[row][i]*mi) % k;
        for (int i=0; i<n; ++i) {
            if(i != row)
            if (a[i][col]) {
//                double c = (a[i][col] * mi) % k;
                ll t = a[i][col];
                for (int j=0; j<m; ++j)
                    a[i][j] = ( (a[i][j] - a[row][j] * t) % k + k ) % k;
            }
        }
        ++row;
    }

    return row;

}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        co.clear();
        scanf("%d %d %d", &n, &m, &k);
        memset(go, 0, sizeof(go));

        for(int i=0; i<n; i++) go[i][i] = 1;
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            u--; v--;
            go[u][v] = go[v][u] = k-1;
        }

        for(int tm=0; tm<n; tm++) {
            vector<ll>temp(n+1);
            for(int i=0; i<=n; i++) temp[i] = go[tm][i];
            co.pb(temp);
        }

//        cout << "FINALLY" << endl;
//        for(int i=0; i<n; i++) {
////            vector<double> tt = co[i];
//            for(int j=0; j<=n; j++) cout << co[i][j] << ' ';
//            cout << endl;
//        }

        ll res = gauss(co);
        printf("Case %d: %lld\n", t, bigMod(k, n-res, 1000000007LL));
    }
    return 0;
}
