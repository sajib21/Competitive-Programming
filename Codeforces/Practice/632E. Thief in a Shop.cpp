#include<bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
#define LIM 1010
//#define ll long long int

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

vector<ll> vecBigMod(vector<ll> n, int r) {
//    cout << "CALC " << r << endl; getchar();
    if(r == 1) return n;

    vector<ll>ans, temp;
    if(r%2) {
        temp = vecBigMod(n, r-1);
//        cout << "MULING ODD " << r << ' ' << temp.size() << endl; getchar();
        ans = multiply(temp , n) ;
        for(int i=0; i<ans.size(); i++) if(ans[i]) ans[i] = 1;
    }
    else {
        temp = vecBigMod(n, r/2);
//        cout << "MULING EVEN " << r << ' ' << temp.size() << endl; getchar();
        ans = multiply(temp, temp);
        for(int i=0; i<ans.size(); i++) if(ans[i]) ans[i] = 1;
    }
    return ans;
}

int main() {
    int n,k;
    vector<ll> v;
    for(int i=0; i<=1000; i++) v.pb(0);

    scanf("%d %d", &n,&k);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v[x] = 1;
    }
//    for(int i=0; i<v.size(); i++) if(v[i]) cout << i << ' ' ; cout << endl;

//    vector<ll> temp = multiply()

    vector<ll> sol = vecBigMod(v, k);
//    vector<ll> sol = multiply(v, v);

//    cout << sol.size() << endl;
//    int ans = 0;
//    for(int i=0; i<sol.size(); i++) if(sol[i]) ans++;
//    cout << ans << endl;
//    for(int i=0, j=0; i<sol.size() && j<10; i++) if(sol[i]) {
//        cout << i << ' ' ;
//        j++;
//    }
//    cout << endl;
    for(int i=0; i<sol.size(); i++) if(sol[i]) cout << i << ' ' ; cout << endl;

//    vector<int> a = {1, 1, 1}, b = {1, 1, 1};
//    vector<ll>x = multiply(a,b);
//    for(int i=0; i<x.size(); i++) cout << x[i] << ' ' ; cout << endl;
}
