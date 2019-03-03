#include <iostream>
#include <utility>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <climits>

#define pii         pair<int,int>
#define ff          first
#define ss          second
#define mp          make_pair

using namespace std;

int c,h,b;
pii info[1010];
int dp[1010][1010][2];

int f(int lft, int rgt, int side) {
    if(lft == 0 && rgt == c-1) {
        if(!side) return 0;
        else return max(info[rgt].ff, info[rgt].ss);
    }
    if(dp[lft][rgt][side] != -1) return dp[lft][rgt][side];
    int ans = INT_MAX;
    if(!side) {
        if(lft >= 1 ) ans = min(ans, abs(info[lft].ff-info[lft-1].ff) + f(lft-1,rgt, 0) );
        if(rgt < c-1) ans = min(ans, abs(info[lft].ff-info[rgt+1].ff) + f(lft, rgt+1,1) );
        ans = max(ans, info[lft].ss);
    }
    else {
        if(lft >= 1 ) ans = min(ans, abs(info[rgt].ff-info[lft-1].ff) + f(lft-1,rgt, 0) );
        if(rgt < c-1) ans = min(ans, abs(info[rgt].ff-info[rgt+1].ff) + f(lft, rgt+1,1) );
        ans = max(ans, info[rgt].ss);
    }
    return dp[lft][rgt][side] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d %d", &c,&h, &b);
    for(int i=1; i<=c; i++) scanf("%d %d", &info[i].ff, &info[i].ss);
    info[0] = pii(0,0);
    c++;
    sort(info, info+c);

    int ans = INT_MAX;
    for(int i=0; i<c; i++) {
        ans = min(ans, abs(info[i].ff-b) + min(f(i,i,0), f(i,i,1) ) );
    }
    printf("%d\n", ans);

    return 0;
}
