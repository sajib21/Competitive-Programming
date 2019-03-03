#include <bits/stdc++.h>
#define ll      long long int
#define vii     vector<ll>
#define pb      push_back
#define pp      pop_back
#define pii     pair<ll,ll>
#define ff      first
#define ss      second

using namespace std;

/// for minimum
struct CHT {
    int ptr, sz;
    vii M, C; /// y = Mx + C

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
        for(int i=0; i<sz; i++) cout << i << " : " << M[i] << ' ' << C[i] << endl;
    }

    ll getY(int pos, ll x) {
//        cout << pos << ' ' << x << ' ' << M[pos] << ' ' << c[pos] << ' ' << M[pos]*x + c[pos] << endl;
        return M[pos]*x + C[pos];
    }
    ll sortedQuery(ll x) { /// pointer
//        double x = 1.0*c/d;
        ptr = 0;
        if(ptr >= M.size()) ptr = M.size() - 1;
        while(ptr < M.size()-1 && getY(ptr+1, x) <= getY(ptr, x) ) ptr++;
        ll ans = M[ptr]*x + C[ptr];
//        cout << "QUERY " << ptr << endl;
        return ans;
    }
    int BSQuery(int x) { /// binary search

    }
};

int n, in=0;
pii data[50050], pure[50050];

int main() {
//    freopen("aqi.txt", "r", stdin);

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld %lld", &data[i].ss, &data[i].ff);
    sort(data, data+n);

    for(int i=0; i<n; i++) {
        while(in && pure[in-1].ss <= data[i].ss) in--;
        pure[in++] = data[i];
    }

//    cout << "PURE " << endl;
//    for(int i=0; i<in; i++) cout << pure[i].ff << ' ' << pure[i].ss << endl;

    CHT cht;
    cht.addLine(pure[0].ss, 0);

////    cout << "DP" << endl;

    ll dp = 0;
    for(int i=0; i<in; i++) {
        dp = cht.sortedQuery(pure[i].ff);
        cht.addLine(pure[i+1].ss, dp);

//        cout << "DP " << dp << " ADDED " << pure[i+1].ss << ' ' << dp << endl; getchar();

    }
    printf("%lld\n", dp);

    return 0;
}

/*
4
100 1
15 15
20 5
1 100
*/
