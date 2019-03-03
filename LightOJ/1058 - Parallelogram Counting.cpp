#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define pdd pair<double, double>

#define EPS 1e-9

using namespace std;

struct info {
    double midx,midy;
    int tanx, tany;
    info() {}
    info(double mx, double my, int tx, int ty) {
        midx = mx; midy = my; tanx = tx; tany = ty;
    }
};

int n,cnt, pntx[1010], pnty[1010];
pdd ln[LIM*LIM+100];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        cnt = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &pntx[i], &pnty[i]);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
//                int tx,ty;
//                if(pntx[i] == pntx[j])
//                    tx = 0 , ty = 1;
//                else {
//                    tx = pntx[i] - pntx[j];
//                    ty = pnty[i] = pnty[j];
//                    int g = __gcd(tx,ty);
//                    tx /= g; ty /=g ;
//                }
//                ln[cnt++] = info( (pntx[i]+pntx[j])/2.0 , (pnty[i]+pnty[j])/2.0 , tx, ty );
                ln[cnt++] = pdd( (pntx[i]+pntx[j])/2.0 , (pnty[i]+pnty[j])/2.0);
            }
        }

//        cout << "MIDS " << endl;
//        for(int i=0; i<cnt; i++) cout << ln[i].first << ' ' << ln[i].second << endl;

        sort(ln, ln+cnt);

        ll ans = 0, c = 1;
        pdd tmp = ln[0];
        for(int i=1; i<cnt; i++) {
            pdd nw = ln[i];
            if(nw.first == tmp.first && nw.second == tmp.second) c++;
            else {
//                cout << "NOW " << c << endl;
                ans += c*(c-1)/2;
                c = 1;
                tmp = nw;
            }
        }
        printf("Case %d: %lld\n", t, ans + c*(c-1)/2);
    }
    return 0;
}
