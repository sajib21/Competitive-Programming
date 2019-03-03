#include<bits/stdc++.h>
#define ll long long int
#define pll pair<ll,ll>
#define MAX 100000
#define MOD 1000000007

using namespace std;

#define p1 65537
#define p2 100003

string sa, sb;
int saSize, sbSize;
ll ex1[MAX+10], ex2[MAX+10];
void pre() {
    ex1[0] = ex2[0] = 1;
    for(int i=1; i<=MAX; i++) {
        ex1[i] = (ex1[i-1]*p1) % MOD;
        ex2[i] = (ex2[i-1]*p2) % MOD;
    }
}
ll h11[MAX+10], h12[MAX+10];
ll h21[MAX+10], h22[MAX+10];
void gen() {
    h11[1] = sa[0] - 'a' + 1;
    h12[1] = sa[0] - 'a' + 1;
    h21[1] = sb[0] - 'a' + 1;
    h22[1] = sb[0] - 'a' + 1;

    for(int i=1; i<sa.size(); i++) {
        h11[i+1] = (h11[i]*p1 + sa[i]-'a'+1) % MOD;
        h12[i+1] = (h12[i]*p2 + sa[i]-'a'+1) % MOD;
    }
    for(int i=1; i<sb.size(); i++) {
        h21[i+1] = (h21[i]*p1 + sb[i]-'a'+1) % MOD;
        h22[i+1] = (h22[i]*p2 + sb[i]-'a'+1) % MOD;
    }
}
pll getHash1(int l, int r) {
    ll one, two;
    return pll( ((h11[r+1]-h11[l]*ex1[r-l+1])%MOD + MOD ) % MOD ,
                ((h12[r+1]-h12[l]*ex2[r-l+1])%MOD + MOD ) % MOD );
}
pll getHash2(int l, int r) {
    ll one, two;
    return pll( ((h21[r+1]-h21[l]*ex1[r-l+1])%MOD + MOD ) % MOD ,
                ((h22[r+1]-h22[l]*ex2[r-l+1])%MOD + MOD ) % MOD );
}

int gcd(int type, int i, int j, int k, int l) {
//    cout << "IN " << type << ' ' << i << ' ' << j << ' ' << k << ' ' << l << endl; getchar();
    if(type == 0) {
        if(k == l) return j-i;
        int s=i, t=j, sz = l-k;
        while(s < t && getHash2(k,l-1) == getHash1(s,s+sz-1)) s += sz;
//        cout << "NEW S " << s << endl;
        if(s == i) return 0;
        return gcd(1, k,l, s,t);
    }
    else {
        if(k == l) return j-i;
        int s=i, t=j, sz = l-k;
        while(s < t && getHash1(k,l-1) == getHash2(s,s+sz-1)) s += sz;
        if(s == i) return 0;
        return gcd(0, k,l, s,t);
    }
}

//int dq(int lo, int hi) {
//    int sz = hi-lo+1;
//    if(sz&1) {
//        for(int i=lo; i<hi; i++) if(sa[i] != sa[i+1]) return sz;
//        return
//    }
//    if(getHash1(lo, lo+sz/2-1) == getHash1(lo+sz/2, hi)) return dq(lo, lo+sz/2-1);
//    else return sz;
//}

int main() {
    freopen("i.txt", "r", stdin);
    cin >> sa >> sb;
    if(sa.size() < sb.size()) swap(sa,sb);
    pre();
    gen();

    int x = gcd(0, 0,sa.size(), 0,sb.size()) ;
    if(!x) {
        cout << x << endl;
        return 0;
    }

    int cnt = 1;
    for(int sz=1; sz<x; sz++) {
        bool f = true;
        int p;
        for(p=sz; p<x && f; p+=sz) {
            if(getHash1(p, p+sz-1) != getHash1(p-sz, p-1)) f = false;
        }
//        if(f && p == x) cout << "SZ " << sz << endl;
        cnt += (f && p == x);
    }

    cout << cnt << endl;

    return 0;
}
