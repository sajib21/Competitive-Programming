#include<bits/stdc++.h>
#define LIM 40004
#define vl vector<long long int>
#define pb push_back

using namespace std;

typedef long double ld;
ld PI = acosl(-1);
typedef long long ll;
typedef pair<int, int> ii;

struct cplx {
	ld a, b;
	cplx(ld a = 0, ld b = 0) : a(a), b(b) {}
	const cplx operator + (const cplx &c) const
		{ return cplx(a + c.a, b + c.b); }
	const cplx operator - (const cplx &c) const
		{ return cplx(a - c.a, b - c.b); }
	const cplx operator * (const cplx &c) const
		{ return cplx(a * c.a - b * c.b, a * c.b + b * c.a); }
};
typedef vector<cplx> vc;
void fft(vc &p, bool inv = 0) {
	int n = p.size(), i = 0;
	for(int j = 1; j < n - 1; ++j) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1);
		if(j < i) swap(p[i], p[j]);
	}
	for(int m = 2; m <= n; m <<= 1) {
		int mh = m >> 1;
		cplx wn = cplx(cos(2 * PI / m), sin(2 * PI / m));
		if(inv) wn = cplx(cos(2 * PI / m), -sin(2 * PI / m));
		for(int j = 0; j < n; j += m) {
			cplx w(1, 0);
			for(int k = 0; k < mh; ++k) {
				int pos = j + k;
				cplx t = w * p[pos + mh];
				p[pos + mh] = p[pos] - t;
				p[pos] = p[pos] + t;
				w = w * wn;
			}
		}
	} if(inv) for(int i = 0; i < n; i++) p[i].a /= n, p[i].b /= n;
}
vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
	int n = a.size(), m = b.size(), t = n + m - 1, sz = 1;
	while(sz < t) sz <<= 1;
	vc x(sz), y(sz), z(sz);
	for(int i = 0 ; i < sz; ++i) {
		x[i] = i < a.size() ? cplx(a[i], 0) : cplx(0, 0);
		y[i] = i < b.size() ? cplx(b[i], 0) : cplx(0, 0);
	} fft(x), fft(y);
	for(int i = 0; i < sz; ++i) z[i] = x[i] * y[i];
	fft(z, 1);
	vector<ll> ret(t + 1);
	for(int i = 0; i <= t; ++i) ret[i] = z[i].a + 0.5;
	return ret;
}

int n, a[LIM],mn=INT_MAX, mx=INT_MIN;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    for(int i=0; i<n; i++) a[i] -= mn;
    sort(a, a+n);
    vector<ll> v, vv;
    for(int i=0; i<=mx-mn; i++) v.pb(0);
    for(int i=0; i<n; i++) v[ a[i] ]++;

    vector<ll> two = multiply(v,v);
//    for(int i=0; i<n; i++) two[ a[i]*2 ]--;
//    for(int i=0; i<n; i++) two[ a[i]*2 ] /= 2;+.accumulate
    vector<ll> three = multiply( two, v );
    for(int i=0; i<n; i++) three[ a[i]*3 ]--;

    for(int i=0; i<=2*(mx-mn); i++) vv.pb(0);
    for(int i=0; i<n; i++) vv[ 2*a[i] ]++;
    vector<ll>rem = multiply(vv, v);
    for(int i=0; i<n; i++) rem[ 3*a[i] ]--;
    for(int i=0; i<rem.size(); i++) rem[ i ] *= 3;

//    for(int i=0; i<two.size(); i++) if(two[i]) cout << i << " : " << two[i] << endl;
//    cout << "THREE  " << endl; for(int i=0; i<three.size(); i++) cout << i << " : " << three[i] << endl;
//    cout << "REMOVE " << endl; for(int i=0; i<rem.size(); i++) cout << i << " : " << rem[i] << endl;

    for(int i=0; i<three.size() && i<rem.size(); i++) three[i] -= rem[i];
//    cout << "FIN    " << endl;
    for(int i=0; i<three.size(); i++) if(three[i] > 0) printf("%d : %d\n", i+3*mn, three[i]/6); //cout << i+3*mn << " : " << three[i]/6 << endl;

}
