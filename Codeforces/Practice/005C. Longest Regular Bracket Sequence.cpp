#include<bits/stdc++.h>

using namespace std;

int main() {

    string seq;
    cin >> seq;
    int sz = seq.size();

    stack<char>stk;
    int ans = 0, cnt = 0, t = 0, tc;

    int tmp =0;
    for(int i=0; i<sz; i++) {
        if(seq[i] == '(') {
            if(stk.empty()) stk.push('(');
            else {
                t = ans;
            }
        }
        else {
            if(!stk.empty()) {
                tmp += 2;
                stk.pop();
                cout << "i = " << i << " e tmp += 2 " << tmp << endl;
            }
            else {
                if(tmp > ans) {
                    ans = tmp;
                    cnt = 1;
                    cout << "i = " << i << " e ans = tmp " << tmp << endl;
                }
                else if(tmp == ans) {
                    cout << "i = " << i << " cnt++ " << tmp << endl;
                    cnt++;
                }
                else cout << "roll over " << tmp << endl;
                tmp = 0;
            }
        }
    }

    if(stk.empty())

//    if(tmp > ans) ans = tmp, cnt = 1;
//    else if (tmp == ans) cnt++;

    if(ans) cout << ans << ' ' << cnt << endl;
    else cout << "0 1" << endl;

    return 0;

}
