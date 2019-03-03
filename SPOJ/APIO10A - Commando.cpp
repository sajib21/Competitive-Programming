#include <bits/stdc++.h>
#define ll long long int
#define vii     vector<ll>
#define pb      push_back
#define pp      pop_back
#define LIM     1000006


using namespace std;

/// for minimum
struct CHT {
    int ptr,sz;
    vii M, C;

    CHT() {
        ptr = sz = 0;
        M.clear(); C.clear();
    }

//    bool bad(ll m, ll c) { /// min
//        return (long double) (C[sz-2] - C[sz-1]) * 1.0 / (C[sz-1] - c) > (long double) (M[sz-1] -M[sz-2]) * 1.0 / (m - M[sz-1]);
//    }
    bool bad(ll m, ll c) { ///max
        return (long double) (c - C[sz-2]) / (1.0*M[sz-2] - m) < (long double) (C[sz-1] - C[sz-2]) / (1.0*M[sz-2] - M[sz-1]);
    }


    void addLine(ll m, ll c) { ///desc slopes, desc cons for min
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

    ll sortedQuery(ll x) { /// <= : min; >= max;
        if(ptr >= sz) ptr = sz - 1;
        while(ptr < sz-1 && getY(ptr+1, x) >= getY(ptr, x)) ptr++;
        return M[ptr]*x + C[ptr];
    }
};

ll n,a,b,c, x[LIM], S[LIM];

int main() {//freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld", &n);
        scanf("%lld %lld %lld", &a,&b,&c);
        for(int i=1; i<=n; i++) scanf("%lld", &x[i]);
        for(int i=1; i<=n; i++) S[i] = S[i-1] + x[i];

//        for(int i=1; i<=n; i++) cout << S[i] << ' '; cout << endl;
//        cout << a << ' ' << b << ' ' << c << endl;

        CHT cht = CHT();
        ll dp = a*S[1]*S[1] + b*S[1] + c;
        for(int i=2; i<=n; i++) {
            cht.addLine(-2*a*S[i-1], a*S[i-1]*S[i-1] - b*S[i-1] + dp);
//            cout << "INSERT " << dp << ' ' << a*S[i-1]*S[i-1] << ' ' << -b*S[i-1] << endl;
//            cht.printHull();
            dp = a*S[i]*S[i] + max(0LL,cht.sortedQuery(S[i])) + b*S[i] + c;
//            cout << dp << ' ' << cht.sortedQuery(S[i]) << endl;

        }
        printf("%lld\n", dp);
//        cht.printHull();
    }
}
