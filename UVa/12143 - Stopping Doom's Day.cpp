#include<bits/stdc++.h>
#define LIM 12
#define MOD 10007
#define ll long long int
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}
ll modInverse(ll n, ll k) { return bigMod(n, k-2, k);  }

ll A[110][110], B[110];
ll inv[MOD+10];
vector<vi>mat;

ll f(ll n) {
    ll ans = 0;
    for(ll i=1; i<=n; i++) {
        for(ll j=1; j<=n; j++) {
            for(ll k=1; k<=n; k++) {
                for(ll l=1; l<=n; l++) {
                    for(ll m=1; m<=n; m++) {
                        ans += abs(i-j)*abs(j-k)*abs(k-l)*abs(l-m)*abs(m-i);
                        ans %= MOD;
                    }
                }
            }
        }
    }
    return ans;
}

void printMat() {
    cout << "MAT " << endl;
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[0].size(); j++) {
            printf("%5d ", mat[i][j]);
        }
        cout << endl;
    }
}


vi gauss() {
    int row = mat.size(), col = mat[0].size();
    for(int r=0,c=0; c<col-1; c++) {

        int divi = inv[ mat[r][c] ];
        for(int j=c; j<col; j++) {
            mat[r][j] *= divi;
            mat[r][j] %= MOD;
        }
        for(int i=0; i<row; i++) if(i != r) {
            int mul = (mat[i][c]) % MOD;
            for(int j=c; j<col; j++) {
                mat[i][j] -= mul*mat[r][j];
                mat[i][j] %= MOD;
                mat[i][j] = (mat[i][j] + MOD) % MOD;
            }
        }
        r++;
    }

    vi sol;
    for(int i=0; i<mat.size(); i++) sol.pb(mat[i].back());
    return sol;
}

int main() {
    for(int i=1; i<MOD; i++) inv[i] = modInverse(i, MOD);

    for(ll n=1; n<=LIM; n++) {
        int co = 1;
        vi temp;
        for(int i=1; i<=LIM; i++) {
            temp.pb(co);
            co *= n; co %= MOD;
        }
        temp.pb(f(n));
        mat.pb(temp);
    }
    vi sol = gauss();

    int n;
    while(scanf("%d", &n) && n) {
        n %= MOD;
        ll NP=1;
        ll ans = 0;
        for(int i=0; i<sol.size(); i++) {
            ans += sol[i]*NP;
            ans %= MOD;
            NP *= n;
            NP %= MOD;
        }
        printf("%lld\n", ans);
    }
}
