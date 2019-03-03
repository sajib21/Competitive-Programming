#include<bits/stdc++.h>

using namespace std;

int main() {

    string str;
    cin >> str;
    int sz = str.size();

    int ara[110];
    for(int i=0; i<sz; i++) ara[i] = str[i]-'0';

    bool flag = false;
    int res;
    for(int i=0; i<sz; i++) {
        int fst = ara[i];
        if(fst % 8 == 0) {
            res = fst;
            flag = true;
            break;
        }
        for(int j=i+1; j<sz; j++) {
            int sec = fst*10 + ara[j];
            if(sec % 8 == 0) {
                res = sec;
                flag = true;
                break;
            }
            for(int k=j+1; k<sz; k++) {
                int thr = sec*10 + ara[k];
                if(thr % 8 == 0) {
                    res = thr;
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
        }
        if(flag == true) break;
    }

    if(flag == true) cout << "YES" << endl << res << endl;
    else cout << "NO" << endl;

    return 0;

}
