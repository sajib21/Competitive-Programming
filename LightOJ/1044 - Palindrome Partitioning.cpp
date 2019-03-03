#include<bits/stdc++.h>
#define IM 10000

using namespace std;

int sz; string seq;
int dp[1002];

bool checkPal(int left, int right) {

    while(left < right) {
        if(seq[left] != seq[right]) return false;
        left++; right--;
    }
    return true;
}

int getMin(int left) {

//    cout << left << ' ' << right << endl;
//    getchar();

    if(left == sz) return 0;
//    if(left == right) return 0;

    if(dp[left] != -1) return dp[left];

    //if(checkPal(left, right)) return dp[left][right] = 1;

    int ans = IM;
    for(int mid=left; mid<sz; mid++) {
        if(checkPal(left, mid)) {
            ans = min(ans, 1 + getMin(mid+1));
        }
    }

    return dp[left] = ans;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        cin >> seq;
        sz = seq.size();

        printf("Case %d: %d\n", t, getMin(0));
    }

    return 0;
}
