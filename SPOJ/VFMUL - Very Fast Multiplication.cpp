#include<bits/stdc++.h>
#define LIM 300045
#define vii vector<ll>
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
vector<ll> multiply(vector<int> &a, vector<int> &b) {
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
    int t;
    scanf("%d", &t);
    while(t--) {
        char a[LIM], b[LIM];
        scanf("%s", a);
        scanf("%s", b);

        vector<int> p,q;
        int sz = strlen(a);
        for(int i=sz-1; i>=0; i--) p.pb(a[i]-'0');
        sz = strlen(b);
        for(int i=sz-1; i>=0; i--) q.pb(b[i]-'0');

        while(p.size() < q.size()) p.pb(0);
        while(q.size() < p.size()) q.pb(0);

//        for(int i=0; i<p.size(); i++) cout << p[i] << ' ' ; cout << endl;
//        for(int i=0; i<q.size(); i++) cout << q[i] << ' ' ; cout << endl;

        vector<ll> ans = multiply(p,q);

//        for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ' ; cout << endl;

        sz = ans.size();
        int carry = 0;
        vii mul;
        for(int i=0; i<ans.size() && ans[i] >= 0 ; i++) {
            carry += ans[i];
            mul.pb(carry%10);
//            printf("%d", carry%10);
            carry /= 10;
        }
        while(carry) {
            mul.pb(carry%10);
            carry /= 10;
        }

        while(mul.back() == 0) mul.pop_back();

        for(int i=mul.size()-1; i>=0; i--) printf("%d", mul[i]);
        if(mul.empty()) printf("0");
        printf("\n");
    }
    return 0;
}
