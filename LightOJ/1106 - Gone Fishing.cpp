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

int n,h, f[27], d[27], t[27];
int dp[27][195];
int dr[27][195];

int getExp(int in, int spent) {
//    cout << "IN  " << in << ' ' << spent << endl;
    if(spent == h) return 0;
    if(spent >  h) return INT_MAX;
    if(in == n) return 0;
    if(dp[in][spent] != -1) return dp[in][spent];
    int a = 0, b=0, c=-1;

    int x = f[in], y=0;
    for(int take=0; take<=h-spent; take++) {
        if(take) a = y ;
        if(spent+take+t[in] <= h) a += getExp(in+1, spent+take+t[in]);
        if(a >= b) {
            b = a;
            c = take;
//            if(in == 1 && spent == 11) cout << "AT " << take << ' ' << a << ' ' << b << ' ' << c << endl;
//            else c =
        }

        y += x;
        x = max(0, x-d[in]);

    }
//    cout << "RETURN " << in << ' ' << spent << ' ' << b << ' ' << c << endl;
    dp[in][spent] = b;
    dr[in][spent] = c;

//    cout << "OUT " << in << ' ' << spent << " WITH " << b << ' ' << c << endl;
    return dp[in][spent];
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++) {
        memset(dp, -1, sizeof(dp));
        memset(dr, -1, sizeof(dr));
        memset(t ,  0, sizeof( t));
        scanf("%d %d", &n,&h);
        h = h * 60 / 5;
//        cout << h << endl;
        for(int i=0; i<n; i++)   scanf("%d", &f[i]);
        for(int i=0; i<n; i++)   scanf("%d", &d[i]);
        for(int i=0; i<n-1; i++) scanf("%d", &t[i]);

        printf("Case %d:\n", tt);
        int ans = getExp(0,0);
        printf("%d", 5*dr[0][0]);
        int x = dr[0][0] <=h? dr[0][0] : -1 , y = dr[0][0] ;
        bool f = true;
        for(int in=1; in<n; in++) {
            y = t[in-1]+x<=h? dr[in][ t[in-1]+x ]: MAX;
//            cout << "TEMO " << t[in-1]+x << ' ' << y << endl;
            if(f && y != MAX) {
                printf(", %d", 5*y);
                x = x + t[in-1] + y;
            }
            else {
                printf(", 0");
                f = false;
            }
//            if(f && x+dr[in][y]+t[in] <= h) {
//                x = x + ( x+dr[in][y]+t[in]<=h? dr[in][y]+t[in] : -1);
//            }
//            else x = -1 , f = false;
        }
        printf("\n");
        printf("Number of fish expected: %d\n", ans);
    }

    return 0;
}

