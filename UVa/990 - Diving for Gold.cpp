#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int t,w, n;
int depth[32], gold[32];

pii dp[32][1010];
int dir[32][1010];

pii getMax(int indx, int tim) {

    if(tim > t) return make_pair(INT_MIN, INT_MIN);
    if(indx == n) return make_pair(0,0);

    if(dp[indx][tim] != make_pair(-1,-1)) return dp[indx][tim];
    pii tmp = getMax(indx+1, tim + depth[indx]*w);
    pii ans1 = make_pair( gold[indx] + tmp.first, 1+tmp.second);
    pii ans2 = getMax(indx+1, tim);

    if(ans1.first > ans2.first) dir[indx][tim] = 1, dp[indx][tim] = ans1;
    else if(ans1.first == ans2.first && ans1.second <= ans2.second) dir[indx][tim] = 1, dp[indx][tim] = ans1;

    else dir[indx][tim] = 2, dp[indx][tim] = ans2;

    return dp[indx][tim];
}

void getPath(int indx, int tim) {

    if(dir[indx][tim] == 0) return;
    if(dir[indx][tim] == 1) {
        printf("%d %d\n", depth[indx], gold[indx]);
        getPath(indx+1, tim+depth[indx]*w);
    }
    else getPath(indx+1, tim);
}

int main() {

    int tst = 0;

    while(scanf("%d %d", &t, &w) != EOF) {
        if(tst) printf("\n");
        tst++;

        memset(dp, -1, sizeof(dp));
        memset(dir, 0, sizeof(dir));

        w *= 3;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d %d", &depth[i], &gold[i]);

        pii tmp = getMax(0,0);
        printf("%d\n%d\n", tmp.first, tmp.second);
        getPath(0,0);

    }

    return 0;
}
