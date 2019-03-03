#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int setBit(int mask, int p) { return mask | (1 << p); }
int togBit(int mask, int p) { return mask ^ (1 << p); }
int chkBit(int mask, int p) { return mask & (1 << p); }

int n, lft, rgt, target;
ll dp[22][22][22][2];

ll f(int num, int rem, int cnt, int con = 0) {
//    cout << "IN " << num << ' ' << rem << ' ' << cnt << ' ' << con << endl; getchar();
    if(!rem) {
        if(con == 0) return dp[num][rem][cnt][con] = f(n-cnt+1, rgt-1, cnt, 1);
        else if(num == 1 && cnt == n) return 1;
        else return 0;
    }
    if(dp[num][rem][cnt][con] != -1) return dp[num][rem][cnt][con];
    ll ans = 0;
    for(int i=1; i<num; i++) {
        ll perm = 1;
        for(int j=0; j<i; j++) {
//            cout << "CALLING FROM " << num << ' ' << rem << ' ' << cnt << ' ' << con << " TO " << i << ' ' << j << endl; getchar();
            ans += f(i-j, rem-1, j+cnt+1, con)*perm;
            perm *= (i-1-j);
//            cout << "STATE " << num << ' ' << rem << ' ' << cnt << ' ' << con << " : " << i << ' ' << j << " : " << ans << endl; getchar();
        }
    }
    return dp[num][rem][cnt][con] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d", &n,&lft,&rgt);
        memset(dp, -1, sizeof dp);
//        memset(dq, -1, sizeof dq);
        ll ans = 0;
        target = (1 << n) -1;

        printf("%lld\n", f(n, lft-1, 1));
//        cout <<  << endl;

//        for(int mask=setBit(1, n-1); mask<target; mask++) {
//            ans += f(mask, lft, 0);
//        }
    }
    return 0;
}
