#include<bits/stdc++.h>

using namespace std;

int gold[111];
int ways;
int n;
int dp[111];
vector<int>vec;

int sumVec() {

    int temp = 0;
    for(int i=0; i<vec.size(); i++) temp += vec[i];
    return temp;
}

int getExp(int indx) {

    if(indx == n) {
        ways++;
        cout << "ways++ " << ways << ' ' << sumVec() << endl;
        return sumVec();
    }
    if(dp[indx] != -1) {
        cout << "dp paisi " << indx << " indx e " << dp[indx] << endl;
        return dp[indx];
    }

    int temp = 0;

    for(int i=indx+1; i<=indx+6; i++) {
        if(i > n) continue;
        vec.push_back(gold[i]);
        temp += (getExp(i));
        vec.pop_back();
    }

    dp[indx] = temp;
    cout << dp[indx] << ' ' << ways << endl;
    return dp[indx];
}

int main() {

    int t, T;
    cin >> T;
    for(t=1; t<=T; t++) {

        ways = 0;
        memset(dp, -1, sizeof(dp));
        memset(gold, 0, sizeof(gold));

        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> gold[i];
        }

        printf("Case %d: %.10lf\n", t, 1.0 * (getExp(1) + gold[1]*ways) / ways);

    }

    return 0;
}
