#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

int n, num[LIM], cnt[5005];
int dp[5005][5005];

int getMin(int st, int ed) {

    if(st >= ed) return 0;
    if(dp[st][ed] != -1) return dp[st][ed];

    if(num[ed] > 2*num[st]) return dp[st][ed] = min( cnt[ num[st] ] + getMin(st+1, ed) , cnt[ num[ed] ] + getMin(st, ed-1) );
    else return dp[st][ed] = 0;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    memset(dp, -1, sizeof(dp));

    int c;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &c);
        num[i] = c;
        cnt[c]++;
    }
    sort(num, num+n); int j = 1;
    for(int i=1; i<n; i++) if(num[i] != num[i-1]) num[j++] = num[i];
    n = j;

//    for(int i=0; i<n; i++) cout << num[i] << ' '; cout << endl;

    printf("%d\n", getMin(0, n-1));

    return 0;

}
