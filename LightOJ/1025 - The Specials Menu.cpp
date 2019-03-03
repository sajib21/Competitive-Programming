#include<bits/stdc++.h>

using namespace std;

int sz;
string seq;
vector<char>pal;
int dp[53];

bool checkPal() {

    int l = pal.size();
    int h = l/2;
    for(int i=0; i<h; i++) if(pal[i] != pal[l-i-1]) return false;
    return true;
}

int getWays(int indx) {

    if(indx == sz) {
        for(int i=0; i<pal.size(); i++) cout << pal[i];
        cout << endl;
        if(checkPal()) return 1;
        else return 0;
    }

    //if(dp[indx] != -1) return dp[indx];

    int ans = 0;
    pal.push_back(seq[indx]);
    ans = ans + getWays(indx+1);
    pal.pop_back();
    ans = ans + getWays(indx+1);

    return dp[indx] = ans;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        cin >> seq;
        sz = seq.size();

        printf("Case %d: %d\n", t, getWays(0));
    }
}
