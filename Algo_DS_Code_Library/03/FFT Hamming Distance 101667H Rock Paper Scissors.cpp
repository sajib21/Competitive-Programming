/**
given two sequence of rock paper scissors, put 2nd seq
such way that winning is maximized.
hamming distance:
keep (rock, scissors) etc pair and fft 2 times
**/

#include<bits/stdc++.h>
#define vl vector<ll>
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



int main() {
//    freopen("in.txt", "r", stdin);

    int n,m, i;

    while(scanf("%d %d", &n,&m) == 2) {

        string str, pat;
        vl ans, a,b, temp;
        cin >> str;
        cin >> pat;
        reverse(pat.begin(), pat.end());

        for(int i=0; i<n; i++) ans.pb(0);
        for(int i=0; i<n; i++) a.pb(0);
        for(int i=0; i<m; i++) b.pb(0);

        ///rock
        for(int i=0; i<n; i++) {
            if(str[i] == 'S') a[i] = 1;
            else a[i] = 0;
        }
        for(int i=0; i<m; i++) {
            if(pat[i] == 'R') b[i] = 1;
            else b[i] = 0;
        }
        temp = multiply(a,b);
        ans = temp;

        ///paper
        for(int i=0; i<n; i++) {
            if(str[i] == 'R') a[i] = 1;
            else a[i] = 0;
        }
        for(int i=0; i<m; i++) {
            if(pat[i] == 'P') b[i] = 1;
            else b[i] = 0;
        }
        temp = multiply(a,b);
        for(i=0; i<temp.size(); i++) ans[i] += temp[i];

        ///scissor
        for(int i=0; i<n; i++) {
            if(str[i] == 'P') a[i] = 1;
            else a[i] = 0;
        }
        for(int i=0; i<m; i++) {
            if(pat[i] == 'S') b[i] = 1;
            else b[i] = 0;
        }
        temp = multiply(a,b);
        for(int i=0; i<temp.size(); i++) ans[i] += temp[i];

        ll answer = 0;
        for(int i=m-1; i<temp.size(); i++) if(temp[i] <= m) answer = max(answer, ans[i]);

        printf("%lld\n", answer);

    }

    return 0;
//    main();
}
