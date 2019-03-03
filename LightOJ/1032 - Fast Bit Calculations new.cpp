#include<bits/stdc++.h>
#define ll long long int
#define SOMAN 1

using namespace std;

int n, sz;
string bin; vector<char>flag;
ll dp[33][3][3], power2[33];


void getBinary(int n) {

    bin.clear();
    while(n) {
        bin += n%2 + '0';
        n /= 2;
    }
    bin += '0';
    reverse(bin.begin(), bin.end());
    return;
}

//void pr() {
//
//    int l = flag.size();
//    for(int i=0; i<l; i++) cout << flag[i];
//    cout << endl;
//}

ll getCount(int indx, int isEqual, int last, ll adjCount) {

//    cout << indx << ' ' << isEqual << ' ' << last << ' ' << adjCount << endl;

    if(indx == sz) {
        //pr();
//        cout << "return " << adjCount << endl;
        return adjCount;
    }
    if(dp[indx][isEqual][last] != -1) {
//        cout <<"dp " << indx << ' ' << isEqual << ' ' << last << ' ' << adjCount << endl;
//        cout << dp[indx][isEqual][last] << endl;
        return dp[indx][isEqual][last] + adjCount * power2[sz-indx];
    }
    ll temp = 0;



    if(isEqual == SOMAN) {
        if(bin[indx] == '1') {
            if(last == 1) temp += getCount(indx+1, SOMAN, 1, adjCount+1);
            else temp += getCount(indx+1, SOMAN, 1, adjCount);

            temp += getCount(indx+1, !SOMAN, 0, adjCount);
        }
        else {
            temp += getCount(indx+1, SOMAN, 0, adjCount);
        }
    }
    else {
        if(last == 1) temp += getCount(indx+1, !SOMAN, 1, adjCount+1);
        else temp += getCount(indx+1, !SOMAN, 1, adjCount);

        temp += getCount(indx+1, !SOMAN, 0, adjCount);
    }

    dp[indx][isEqual][last] = temp - adjCount * power2[sz-indx];
    return temp;

}

int main() {

    power2[0] = 1;
    for(int i=1; i<=31; i++) power2[i] = power2[i-1] * 2;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        scanf("%d", &n);
        getBinary(n);
//        cout << bin << endl;
        sz = bin.size();

        printf("Case %d: %lld\n",t, getCount(1, SOMAN, 0, 0));
    }
}
