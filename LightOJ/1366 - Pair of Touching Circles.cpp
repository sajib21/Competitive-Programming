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

int H,W;

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &H,&W);
        ll ans = 0;

        for(int i=2; i<=W && i<=H; i+=2) {
            for(int j=2; i+j<=W && max(i,j)<=H; j+=2) {
                ans += (W-(i+j)+1) * (H-max(i,j)+1);
                cout << i << ' ' << j << ' ' << i+j << ' ' << max(i,j) << ' ' << (W-(i+j)+1) * (H-max(i,j)+1) << endl;
            }
        }
        swap(W,H);
        for(int i=2; i<=W && i<=H; i+=2) {
            for(int j=2; i+j<=W && max(i,j)<=H; j+=2) {
                ans += (W-(i+j)+1) * (H-max(i,j)+1);
                cout << i << ' ' << j << ' ' << i+j << ' ' << max(i,j) << ' ' << (W-(i+j)+1) * (H-max(i,j)+1) << endl;
            }
        }
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
