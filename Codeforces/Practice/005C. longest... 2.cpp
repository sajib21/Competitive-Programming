#include<bits/stdc++.h>

using namespace std;

int sz, indx, maxAns = INT_MIN;
string seq;

int counts[1000006];

int getAns() {

    int ans = 0, tmp = 0, cnt = 0;

//    stack<char>stk;
    char stk = seq[indx];
//    stk.push(seq[indx]);
    indx++;

    while(indx < sz) {
        if(seq[indx] == ')') {
            if(stk) {
                ans += 2;
                indx++;
                counts[ans]++;
                stk = 0;
            }
            else {
                maxAns = max(maxAns, ans);
                return ans;
            }

        }
        else {
            tmp = getAns();
            if(!ans) {
                ans = tmp;
            }
            else {
                ans += tmp;
                if(tmp) counts[ans]++;
            }
        }
    }
    maxAns = max(maxAns, ans);
    if(!stk) return ans;
    else return 0;
}

int main() {

    cin >> seq;
    sz = seq.size();

    //int s;
    for(indx=0; indx<sz; ) {
        if(seq[indx] == '(') {
            getAns();
        }
        else indx++;
    }

    //cout << getAns() << endl;

    if(maxAns != INT_MIN && maxAns) cout << maxAns << ' ' << counts[maxAns] << endl;
    else cout << "0 1" << endl;

}
