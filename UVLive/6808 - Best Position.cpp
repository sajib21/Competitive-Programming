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

char grida[505][505], gridb[505][505];

int main() {
//    freopen("in.txt", "r", stdin);

    int n,m, r,c, i, T, u=0,v=0;
    vl ans[2], a[3], b[3];
    ll g,l;

    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++) scanf("%s", grida[i]);

    for(int j=0; j<n; j++) {
        for(int p=0; p<m; p++) {
            if(grida[j][p] == 'G') {
                a[0].pb(1);
                a[1].pb(0);
            }
            else {
                a[0].pb(0);
                a[1].pb(1);
            }
        }
    }

//    for(int i=0; i<a[0].size(); i++) {
//        cout << a[0][i]; //if(i%m==0) cout << " ";
//    } cout << endl;
//    for(int i=0; i<a[1].size(); i++) {
//        cout << a[1][i]; //if(i%m==0) cout << " ";
//    } cout << endl;

    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(ans, NULL, sizeof ans);
        memset(b, NULL, sizeof b);
        g = l = 0;

        scanf("%d %d", &r, &c);
        for(int i=0; i<r; i++) scanf("%s", gridb[i]);
//        for(int i=0; i<r; i++) reverse(gridb[i], gridb[i]+c);


        for(int j=0; j<r; j++) {
            for(int p=0; p<c; p++) {
                if(gridb[j][p] == 'G') {
                    b[0].pb(1);
                    b[1].pb(0);
                }
                else {
                    b[0].pb(0);
                    b[1].pb(1);
                }
            }
            if(j < r-1) for(int p=0; p<m-c; p++) {
                b[0].pb(0);
                b[1].pb(0);
            }
        }
        reverse(b[0].begin(), b[0].end());
        reverse(b[1].begin(), b[1].end());

//        for(int j=0; j<b[0].size(); j++) cout << b[0][j]; cout << endl;
//        for(int j=0; j<b[1].size(); j++) cout << b[1][j]; cout << endl;

        ans[0] = multiply(a[0], b[0]);
        ans[1] = multiply(a[1], b[1]);

        for(int i=r-1; i<n; i++) {
            for(int j=c-1; j<m; j++) {
                int in = m*i + j;
                if(ans[0][in]+ans[1][in] > g+l) {
                    g = ans[0][in];
                    l = ans[1][in];
                    u = i-r+1; v = j-c+1;
                }
//                cout << i << ' ' << j << ' ' << in << ' ' << ans[0][in] << ' ' << ans[1][in] << endl;
            }
        }

//        for(int i=0; i<=n-r; i++) {
//            for(int j=i; j-i<r; j++) ans[j-i] = multiply(a[j],b[j-i]);
//
//            for(int j=c-1; j<m; j++) {
//                ll tg = 0, tl = 0;
//                for(int k=0; k<r; k++) {
//                    tg += ans[k][j];
//                    tl += ans[k][j];
//                }
//                if(tg > g) {
//                    g = tg; l = tl; u = i; v = j-c+1;
//                }
//            }
//        }

        printf("Case #%d: %d %d %lld %lld\n", t, u+1,v+1, g,l);

    }



    return 0;
//    main();
}

