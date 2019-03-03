#include    <bits/stdc++.h>
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     10000000
#define     MOD     1000000007
#define     MAX     10000000
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


int n, num[110], suml[110], sumr[110];
int dp[110][110], dr[110][110];

int getMax(int left, int right) {

    if(left+1 == right) return 0;
    if(dr[left][right] != -1) return dp[left][right];

    int temp = INT_MIN;

    for(int i=left+1; i<right; i++) temp = max(temp, suml[i]-suml[left] - getMax(i, right));
    for(int i=right-1;i>left; i--)  temp = max(temp, sumr[i]-sumr[right]- getMax(left, i));

//    cout << left << ' ' << right << ' ' << temp << endl;

//    if(con != 1) temp = max( num[left] + getMax(left+1, right, 0) , num[left] - getMax(left+1, right, 2) );
//    if(con != 0) temp = max( num[right] + getMax(left, right-1, 1), num[right] - getMax(left, right-1, 2) );

    dr[left][right] = 1;
    return dp[left][right] = temp;

}

int main() {

    int t;
//    cin >> t;
    while(scanf("%d", &n) && n) {

        memset(dp, -1, sizeof(dp));
        memset(dr, -1, sizeof(dr));

//        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &num[i]);
//        suml[1] = num[0];
        for(int i=1; i<=n; i++) suml[i] = suml[i-1] + num[i];
//        sumr[n-1] = num[n-1];
        for(int i=n; i>0;  i--) sumr[i] = sumr[i+1] + num[i];

//        for(int i=1; i<=n; i++) cout << suml[i] << ' ' ; cout << endl;
//        for(int i=1; i<=n; i++) cout << sumr[i] << ' ' ; cout << endl;

        printf("%d\n", getMax(0, n+1) );

    }

    return 0;

}
