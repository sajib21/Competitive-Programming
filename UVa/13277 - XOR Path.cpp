#include <bits/stdtr1c++.h>

#define MAX 1048576
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 100005
#define ll long long
#define vl vector<ll>

using namespace std;

/// Fast Walsh-Hadamard Transformation in n log n
namespace fwht{ /// hash = 840614
    const int OR = 0;
    const int AND = 1;
    const int XOR = 2;

    long long P1[MAX], P2[MAX];

    void walsh_transform(long long* ar, int n, int flag = XOR){
        if (n == 0) return;

        int i, m = n / 2;
        walsh_transform(ar, m, flag);
        walsh_transform(ar + m, m, flag);

        for (i = 0; i < m; i++){ /// Don't forget modulo if required
            long long x = ar[i], y = ar[i + m];
            if (flag == OR) ar[i] = x, ar[i + m] = x + y;
            if (flag == AND) ar[i] = x + y, ar[i + m] = y;
            if (flag == XOR) ar[i] = x + y, ar[i + m] = x - y;
        }
    }

    void inverse_walsh_transform(long long* ar, int n, int flag = XOR){
        if (n == 0) return;

        int i, m = n / 2;
        inverse_walsh_transform(ar, m, flag);
        inverse_walsh_transform(ar + m, m, flag);

        for (i = 0; i < m; i++){ /// Don't forget modulo if required
            long long x = ar[i], y = ar[i + m];
            if (flag == OR) ar[i] = x, ar[i + m] = y - x;
            if (flag == AND) ar[i] = x - y, ar[i + m] = y;
            if (flag == XOR) ar[i] = (x + y) >> 1, ar[i + m] = (x - y) >> 1; /// Modular inverse if required here
        }
    }

    vector <long long> convolution(int n, long long* A, long long* B, int flag = XOR){
        assert(__builtin_popcount(n) == 1); /// n must be a power of 2
        for (int i = 0; i < n; i++) P1[i] = A[i];
        for (int i = 0; i < n; i++) P2[i] = B[i];

        walsh_transform(P1, n, flag);
        walsh_transform(P2, n, flag);
        for (int i = 0; i < n; i++) P1[i] = P1[i] * P2[i];
        inverse_walsh_transform(P1, n, flag);
        return vector<long long> (P1, P1 + n);
    }

    /// For i = 0 to n - 1, j = 0 to n - 1
    /// v[i or j] += A[i] * B[j]
    vector <long long> or_convolution(int n, long long* A, long long* B){
        return convolution(n, A, B, OR);
    }

    /// For i = 0 to n - 1, j = 0 to n - 1
    /// v[i and j] += A[i] * B[j]
    vector <long long> and_convolution(int n, long long* A, long long* B){
        return convolution(n, A, B, AND);
    }

    /// For i = 0 to n - 1, j = 0 to n - 1
    /// v[i xor j] += A[i] * B[j]
    vector <long long> xor_convolution(int n, long long* A, long long* B){
        return convolution(n, A, B, XOR);
    }
}

int n,sz;
vi g[LIM], c[LIM];
int vis[LIM], keys[LIM];
long long A[MAX], B[MAX], C[MAX];

void dfs(int u) {
    vis[u] = 1;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i], w = c[u][i];
        if(vis[v]) continue;
        keys[v] = keys[u] ^ w;
        A[ keys[v] ]++;
        dfs(v);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        sz = (1 << 16);
        memset(g, NULL, sizeof g);
        memset(c, NULL, sizeof c);
        memset(vis, 0, sizeof vis);
        memset(keys, 0, sizeof keys);
        memset(A, 0, sizeof A);

        for(int i=1; i<n; i++) {
            int u,v,w;
            scanf("%d %d %d", &u,&v,&w);
            g[u].pb(v); g[v].pb(u);
            c[u].pb(w); c[v].pb(w);
        }
        dfs(1);
        A[0]++;
//        for(int i=1; i<=n; i++) cout << keys[i] << ' ' ; cout << endl;
//        for(int i=0; i<10; i++) cout << A[i] << ' ' ; cout << endl;

        vl res = fwht::xor_convolution(sz, A, A); res[0] -= n;
        printf("Case %d:\n", t);
        for(int i=0; i<sz; i++) printf("%lld\n", res[i]/2);

    }
    return 0;
}
