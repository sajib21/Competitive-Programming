#include<bits/stdc++.h>
#define ll long long int
using namespace std;

string pre, post;
ll dp[34][5], power2[35];
int sz;

ll getZero(int indx, int preCon, ll cur) {

    if(indx == sz) return cur;
    if(dp[indx][preCon] != -1) {
        return dp[indx][preCon] + cur * power2[sz-indx];
    }

    int temp = 0;
    if(preCon == 0) {


        if(pre[indx] != post[indx]) {
            if(pre[indx] == '0') temp += getZero(indx+1, 1, cur+1);
            else temp += getZero(indx+1, 1, cur);
            if(pre[indx]) temp += (post[indx]-pre[indx] - 1)*getZero(indx+1, 2, cur);
            else temp += (post[indx] - '0' - 1)*getZero(indx+1, 2, cur);
            temp += getZero(indx+1, 3, cur);
        }
        else {
            if(pre[indx] == '0') temp += getZero(indx+1, 0, cur+1);
            else temp += getZero(indx+1, 0, cur);
        }
//        if(pre[indx] == '0') {
//            temp++;
//        }
    }

    else if(preCon == 1) {
        if(pre[indx] == '0') temp += getZero(indx+1, 1, cur+1);
        else temp += getZero(indx+1, 1, cur);
        if(pre[indx]) temp += ('9'- pre[indx])*getZero(indx+1, 2, cur);
        else temp += ('9'- '0')*getZero(indx+1, 2, cur);
//        if(pre[indx] == '0') temp++;
    }

    else if(preCon == 2){
        temp += getZero(indx+1, 2, cur+1);
        temp += 9*getZero(indx+1, 2, cur);
//        temp++;
    }

    else {
        if(post[indx] == '0') temp += getZero(indx+1, 3, cur+1);
        else temp += getZero(indx+1, 3, cur);
        temp += (post[indx] - '0')*getZero(indx+1, 2, cur);
//        temp++;
    }

    dp[indx][preCon] = temp - cur * power2[sz-indx];
    return temp;
}

int main() {

    power2[0] = 1;
    for(int i=1; i<=32; i++) power2[i] = power2[i-1] * 2;

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));

        cin >> pre >> post;

        reverse(pre.begin(), pre.end());

        int tmp = post.size() - pre.size();
        while(tmp--) pre = pre + '0';
        reverse(pre.begin(), pre.end());
        int i = 0;
        while(pre[i] == '0') pre[i++] = 0;
//        string temp = '\0';
//        while(tmp--) temp = temp + '\0';
//        temp = temp + pre;
//        pre = temp;
        sz = post.size();
        cout << pre << endl;

        printf("Case %d: %lld\n", t, getZero(0, 0, 0));
    }

    return 0;

}
