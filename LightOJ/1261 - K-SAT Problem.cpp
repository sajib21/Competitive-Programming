#include<bits/stdc++.h>
#define ll long long int
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

int n,m,k;
int req[33][33];
int p, r, f[33];

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(f, 0, sizeof f);
        scanf("%d %d %d", &n,&m,&k);
        for(int i=0; i<n; i++) {
            for(int j=0; j<k; j++) scanf("%d", &req[i][j]);
        }
        scanf("%d", &p);
        bool cor[33] = {false};
        bool ans = true;
        for(int pp=0; pp<p; pp++) {
            scanf("%d", &r);
            f[r] = 1;
//            cout << r << ' ' << f[r] << endl;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<k && !cor[i]; j++) {
                if( (req[i][j] < 0 && f[ -req[i][j] ] == 0 ) || (req[i][j] > 0 && f[ req[i][j] ] == 1 ) ) {
                    cor[i] = true;
//                    cout << req[i][j] << ' ' << f[ req[i][j] ] << endl;
                }
            }
            ans &= cor[i];
            if(!ans) break;
        }

        if(ans) printf("Case %d: Yes\n", t);
        else printf("Case %d: No\n", t);
    }

    return 0;
}

