#include    <bits/stdc++.h>
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     10000000
#define     MOD     1000000007
#define     MAX     100000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

int t1,t2, n;
int cost1[30][20], cost2[30][20], total[33], m[33];
int dp[330][330];
int dr[330][330];

int getMin(int in, int take1) {
    int take2 = (!in? 0 : total[in-1]) - take1;
//    cout << in << ' ' << take1 << ' ' << take2 << endl;
    if(take1 > t1 || take2 > t2) return MAX;
    if(in == n) return 0;

    if(dp[in][take1] != -1) return dp[in][take1];

    int a,b, ans = INT_MAX, tk;
    for(int i=0; i<=m[in]; i++) {
        int temp = cost1[in][i] + cost2[in][m[in]-i] + getMin(in+1, take1+i);
//        cout << "TEMP " << temp << ' ' << i << endl;
        if(temp < ans) {
            ans = temp;
            tk = i;
        }
    }
    dr[in][take1] = tk;
    return dp[in][take1] = ans;
}

void pathPrint(int in, int tk1) {
    if(in == n) {
//        cout << "RET " << in << ' ' << tk1 << ' ' << tk2 << " RET " << endl;
        printf("\n");
        return ;
    }

    int d = dr[in][tk1];
    if(in > 0) printf(" ");
    printf("%d", d);
    pathPrint(in+1, tk1+d);
}

int main() {

//    freopen("Di.txt", "r", stdin);
//    freopen("Do.txt", "w",stdout);

    int T;
//    scanf("%d", &T);
    for(int t=1; ; t++) {
        scanf("%d %d", &t1, &t2);
        if(!t1 && !t2) return 0;

        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        memset(dr, -1, sizeof(dr));
        memset(m, 0, sizeof(m));
//        total = 0;
        for(int j=0; j<n; j++) {
            scanf("%d", &m[j]);
            for(int i=1; i<=m[j]; i++) scanf("%d", &cost1[j][i]);
            for(int i=1; i<=m[j]; i++) scanf("%d", &cost2[j][i]);
            total[j] = m[j];
            if(j > 0) total[j] += total[j-1];
//            cout << "BUG" << endl;
        }


//        cout << total << endl;
//        for(int i=0; i<n; i++) cout << total[i] << endl;


        int ans = getMin(0, 0);

        printf("%d\n", ans);
        pathPrint(0,0);
        printf("\n");
    }

    return 0;
}

/*
10 12
5
5
10 30 70 150 310
10 20 40 60 180
7
30 60 90 120 160 200 240
20 60 100 130 160 200 240
4
40 60 80 100
30 70 100 120
3
60 120 180
20 50 90
3
30 70 100
30 70 100
0 0

*/

