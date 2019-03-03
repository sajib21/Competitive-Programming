#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

struct info{
    ll x,y;
    info() {}
    info(ll xx, ll yy) {
        x = xx; y = yy;
    }
};

int n;
info pnt[10005];

int main() {

//    cout << __gcd( 0, 5) << endl;

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%lld %lld", &pnt[i].x, &pnt[i].y);
        pnt[n] = pnt[0];

        double area = 0;
        for(int i=0; i< n; i++) area += pnt[i].x*pnt[i+1].y;
        for(int i=1; i<=n; i++) area -= pnt[i].x*pnt[i-1].y;
        area = fabs(area);
//        area /= 2.0;

        ll out = 0;
        for(int i=0; i<n; i++) out += __gcd( abs(pnt[i].x-pnt[i+1].x) , abs(pnt[i].y-pnt[i+1].y) );

//        cout << area << ' ' << out << endl;

        ll ans = (area - out)/2 + 1;

        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}

