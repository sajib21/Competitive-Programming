#include<bits/stdc++.h>

using namespace std;

int dir[] = {+1, -1};

int n, ara[1010];
bool firstTaken = false;

int dp[1010][3];

int getMax(int indx, bool firstTaken) {

    int ans = 0;

    if(indx >= n) return 0;

    if(indx == n-1) {
        if(firstTaken == false) {
            //cout << indx << ' ' << ara[indx] << ' ' << firstTaken << endl;
            return ara[indx];
        }
        else return 0;
    }

    else if(dp[indx][firstTaken] != -1) return dp[indx][firstTaken];

    else if(!indx) {
        int a,b;
        a = ara[indx] + getMax(indx+2, true);
        b = getMax(indx+1, false);
        //cout << a << " and " << b << endl;
        ans = max(a,b);
    }

    else ans = max( ara[indx] + getMax(indx+2, firstTaken) , getMax(indx+1, firstTaken) );

    return dp[indx][firstTaken] = ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));
        firstTaken = false;

        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &ara[i]);

        printf("Case %d: %d\n", t, getMax(0, false) );
    }
}
