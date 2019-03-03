#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define pll pair<ll,ll>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

struct info {
    int x,y;
    info() {}
    info(int a, int b) {
        x = a; y = b;
    }
};

bool cmp (pii a, pii b) {
    return 1LL * a.second * b.first < 1LL * b.second * a.first;
}

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

int n;
pii pnt[707], slope[700 + 7];

int main() {

//    freopen("1292i.txt", "r", stdin);
//    freopen("1292o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &pnt[i].first, &pnt[i].second);

        if(n < 3) {
            printf("Case %d: %d\n", t, n);
            continue;
        }

        int ans = 2;
        for(int i=0; i<n; i++) {
            int s=0;
            for(int j=i+1; j<n; j++) {
                int dx = pnt[i].first - pnt[j].first;
                int dy = pnt[i].second - pnt[j].second;
                int g = gcd(abs(dx), abs(dy));
                if(g) dx /= g , dy /= g;
                if(dx < 0) dx *= -1 , dy *= -1 ;
                if(dx == 0 && dy < 0) dy = -dy;


                slope[s++] = mp(dx , dy);
            }
            sort(slope, slope+s, cmp);
            int cnt = 2;
            for(int k=1; k<s; k++) {
                if( slope[k].first !=  slope[k-1].first || slope[k].second != slope[k-1].second ) {
                    ans = max(ans, cnt);
                    cnt = 2;
                }
                else cnt++;
            }
            ans = max(ans, cnt);
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
