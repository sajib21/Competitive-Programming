
#include<bits/stdc++.h>
#define ll long long int
#define LIM 100000

using namespace std;

int n, x[LIM+10], h[LIM+10];
ll dp[LIM+10][3];

ll getMax(int indx, int where) {

    if(indx == n-1) return 0;
    if(dp[indx][where] != -1) return dp[indx][where];

    ll a=0,b=0;
    if(where == 0 && h[indx] < x[indx]-x[indx-1]) a = 1 + getMax(indx+1, 0) ;
    else if(where && h[indx] < x[indx]-x[indx-1]-h[indx-1]) a = 1 + getMax(indx+1, 0) ;
    else if(h[indx] < x[indx+1]-x[indx]) a = 1+ getMax(indx+1, 1);


    b = getMax(indx+1, 0);

    return dp[indx][where] = max(a,b);
}

int main() {

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x[i], &h[i]);
    }

    if(n == 1) cout << 1 << endl;
    else cout << getMax(1, 0) + 2 << endl;

    return 0;

}
