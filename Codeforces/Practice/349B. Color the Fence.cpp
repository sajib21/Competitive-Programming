#include<bits/stdc++.h>
#define LIM 1000006

using namespace std;

int v, a[12];
int dp[LIM], dr[LIM];

int f(int rem) {
    if(dp[rem] != -1) return dp[rem];
    int ans = 0, dir = 0;
    for(int i=1; i<=9; i++) if(a[i] <= rem) {
        int temp = 1+f(rem-a[i]);
        if(temp >= ans) {
            ans = temp;
            dir = i;
        }
    }
    dr[rem] = dir;
    return dp[rem] = ans;
}

void g(int rem) {
    if(!dp[rem]) return;
    printf("%d", dr[rem]);
    g(rem-a[ dr[rem] ]);
}

int main() {
    scanf("%d", &v);
    for(int i=1; i<=9; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
    f(v);
    if(f(v) > 0) g(v);
    else printf("-1");
    printf("\n");

//    cout << f(v) << endl;
}
