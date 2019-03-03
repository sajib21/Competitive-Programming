#include <iostream>
#include <utility>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <climits>

using namespace std;

int n,l, pos[1010], x, dp[1010][1010][2];

int f(int lft, int rgt, int side) {
    if(lft == 0 && rgt == n-1) return dp[lft][rgt][side] = 0;
    if(dp[lft][rgt][side] != -1) return dp[lft][rgt][side];
    int ans = INT_MAX, rem = n-(rgt-lft+1);
    if(side == 0) {
        if(lft > 0)   ans = min(ans, abs(pos[lft]-pos[lft-1])*rem + f(lft-1, rgt, 0));
        if(rgt < n-1) ans = min(ans, abs(pos[lft]-pos[rgt+1])*rem + f(lft, rgt+1, 1));
    }
    else {
        if(lft > 0)   ans = min(ans, abs(pos[rgt]-pos[lft-1])*rem + f(lft-1, rgt, 0));
        if(rgt < n-1) ans = min(ans, abs(pos[rgt]-pos[rgt+1])*rem + f(lft, rgt+1, 1));
    }

    return dp[lft][rgt][side] = ans;
}

int main() {
    scanf("%d %d", &n,&l);
    pos[0] = l;
    for(int i=1; i<=n; i++) scanf("%d", &pos[i]);
    n++;
    sort(pos, pos+n);
    for(int i=0; i<n; i++) if(pos[i] == l) x = i;
    memset(dp, -1, sizeof dp);
    printf("%d\n", f(x,x,0));

    return 0;
}

/*
4 10
1   180
9   100
11  18.
19  18.8
*/
