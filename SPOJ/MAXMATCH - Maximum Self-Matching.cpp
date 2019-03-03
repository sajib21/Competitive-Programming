#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
ld PI = acosl(-1);
typedef long long ll;
typedef pair<int, int> ii;

#define vi vector<ll>
#define pb(x) push_back(x)


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

int main() {
    string s;
    cin >> s;

    vi a,b,c;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'a') a.pb(1), b.pb(0), c.pb(0);
        if(s[i] == 'b') b.pb(1), a.pb(0), c.pb(0);
        if(s[i] == 'c') c.pb(1), a.pb(0), b.pb(0);
    }

    vi ra,rb,rc;
    ra = a; rb = b; rc = c;
    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());
    reverse(rc.begin(), rc.end());

    vector<ll>x,y,z;
    x = multiply(ra,a); y = multiply(rb,b); z = multiply(rc,c);

    ll p,q=0;
    for(int i=0; i<(int)s.size()-1; i++) {
//        cout << i << ' ' << x[i] << ' ' << y[i] << ' ' << z[i] << ' ' << x[i]+y[i]+z[i] << endl;
        if(x[i]+y[i]+z[i] > q) {
            q = x[i]+y[i]+z[i];
//            p = i;
        }
    }
    cout << q << endl;
    bool f = false;
    for(int i=(int)s.size()-2; i>=0; i--) {
        if(x[i]+y[i]+z[i] == q) {
            if(f) printf(" ");
            printf("%d", (int)s.size()-i-1);
            f = true;
        }
    }
    cout << endl;
//     << (int)s.size()-p-1 << endl;
}