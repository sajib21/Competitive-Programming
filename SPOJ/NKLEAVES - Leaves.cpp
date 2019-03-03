#include<bits/stdc++.h>
#define LIM 1003
#define ll long long int
#define vi vector<ll>
#define pb push_back
#define pp pop_back

using namespace std;

struct CHT {
    int ptr,sz;
    vi M, C;

    CHT() {
        ptr = sz = 0;
        M.clear(); C.clear();
    }

    bool bad(ll m, ll c) {
        return (C[sz-2] - C[sz-1]) * 1.0 / (C[sz-1] - c) >= (M[sz-1] -M[sz-2]) * 1.0 / (m - M[sz-1]);
    }
    void addLine(ll m, ll c) {
        while(sz >= 2 && bad(m,c)) {
            M.pp(); C.pp(); sz--;
        }
        M.pb(m); C.pb(c);
        sz++;
    }

    void printHull() {
        cout << "HULL" << endl;
        for(int i=0; i<sz; i++) cout << i << " : " << M[i] << ' ' << C[i] << endl;
    }

    ll getY(int pos, ll x) {
        return M[pos]*x + C[pos];
    }

    ll sortedQuery(ll x) {
        while(ptr < sz-1 && getY(ptr+1, x) <= getY(ptr, x)) ptr++;
        return M[ptr]*x + C[ptr];
    }
};

int n,k;
ll x[LIM], w[LIM], S[LIM], M[LIM];
ll dp[3][LIM];

int main() {

//    CHT cht;
//    cht.addLine(5)

    while(scanf("%d %d", &n,&k) != EOF) {
        for(int i=1; i<=n; i++) scanf("%d", &w[i]);
        for(int i=1; i<=n; i++) S[i] = S[i-1] + w[i];
        for(int i=1; i<=n; i++) M[i] = M[i-1] + i*w[i];

        for(int j=n; j>=1; j--) dp[1][j] = M[n] - M[j-1] - j*S[n] + j*S[j-1];

        for(int j=1; j<=n; j++) cout << dp[1][j] << ' ' ; cout << endl;

        CHT cht = CHT();

        for(int i=2; i<=k; i++) {
            cht = CHT();
            for(int j=n-i+1; j>=1; j--) {
                cht.addLine(S[j], M[j]+dp[(i-1)%2][j+1]);
                cht.printHull();
                dp[i%2][j] = -M[j-1] + cht.sortedQuery(-j) + j*S[j-1];
                cout << i << ' ' << j << " : " << dp[i%2][j] << endl;
            }
        }

        printf("%lld\n", dp[k%2][1]);

        break;
    }
}
